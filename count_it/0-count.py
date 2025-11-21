#!/usr/bin/python3
import requests


def count_words(subreddit, word_list, after=None, counts=None, word_multipliers=None):
   """
   Recursively queries the Reddit API for hot articles in a subreddit,
   counts occurrences of given keywords (case-insensitive), and prints
   sorted results.
   
   Args:
       subreddit: The subreddit to query
       word_list: List of keywords to count
       after: Pagination token for next page (internal use)
       counts: Accumulated word counts (internal use)
       word_multipliers: Keyword multipliers for duplicate words (internal use)
   """
   # Initialize counts dictionary on first call
   if counts is None:
       counts = {}
   
   # Process word_list into multipliers on first call
   if word_multipliers is None:
       word_multipliers = {}
       for word in word_list:
           word_lower = word.lower()
           word_multipliers[word_lower] = word_multipliers.get(word_lower, 0) + 1
   
   # Reddit API configuration
   headers = {'User-Agent': 'Mozilla/5.0 (compatible; RedditWordCounter/1.0)'}
   url = f'https://www.reddit.com/r/{subreddit}/hot.json'
   params = {'limit': 100}
   if after:
       params['after'] = after
   
   try:
       # Make API request without following redirects
       response = requests.get(
           url,
           headers=headers,
           params=params,
           allow_redirects=False,
           timeout=10
       )
       
       # Invalid subreddit or error - exit silently
       if response.status_code != 200:
           return
       
       data = response.json()
       
       # Extract posts from response
       posts = data.get('data', {}).get('children', [])
       if not posts:
           return
       
       # Process each post title
       for post in posts:
           title = post.get('data', {}).get('title', '')
           if not title:
               continue
           
           # Normalize title: lowercase, split into words, strip punctuation
           words = title.lower().split()
           cleaned_words = []
           for word in words:
               # Remove punctuation from both ends of the word
               cleaned_word = word.strip('.,!?;:"()[]{}<>/\\|-_=+@#$%^&*~`')
               if cleaned_word:
                   cleaned_words.append(cleaned_word)
           
           # Count keyword occurrences
           for keyword, multiplier in word_multipliers.items():
               # Count exact word matches (whole word only)
               keyword_count = cleaned_words.count(keyword)
               if keyword_count > 0:
                   counts[keyword] = counts.get(keyword, 0) + (keyword_count * multiplier)
       
       # Get pagination token for next page
       after = data.get('data', {}).get('after')
       
       # Base case: no more pages - print results
       if after is None:
           if counts:
               # Sort by count desc, then keyword asc
               sorted_results = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
               for keyword, count in sorted_results:
                   print(f"{keyword}: {count}")
       else:
           # Recursive case: fetch next page
           count_words(subreddit, word_list, after, counts, word_multipliers)
           
   except Exception:
       # Handle any errors silently (print nothing)
       return