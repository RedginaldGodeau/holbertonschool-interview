#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strlen - Calculate the length of a string
 * @s: The string
 * Return: The length of the string
 */
static int _strlen(char const *s) {
  int len;

  len = 0;
  while (s[len])
    len++;
  return (len);
}

/**
 * _is_valid - Check if a substring is a valid concatenation
 * @s: The main string
 * @start: Starting index of substring
 * @word_len: Length of each word
 * @nb_words: Number of words
 * @words: Array of words
 * Return: 1 if valid, 0 otherwise
 */
static int _is_valid(char const *s, int start, int word_len, int nb_words,
                     char const **words) {
  int *used;
  int i;
  int j;
  char const *chunk;

  used = calloc(nb_words, sizeof(int));
  if (!used)
    return (0);

  for (i = 0; i < nb_words; i++) {
    chunk = s + start + i * word_len;
    for (j = 0; j < nb_words; j++) {
      if (!used[j] && strncmp(chunk, words[j], word_len) == 0) {
        used[j] = 1;
        break;
      }
    }
    if (j == nb_words) {
      free(used);
      return (0);
    }
  }
  free(used);
  return (1);
}

/**
 * find_substring - Find all substrings containing concatenated words
 * @s: String to scan
 * @words: Array of words
 * @nb_words: Number of elements in words
 * @n: Address to store number of elements in returned array
 * Return: Array of indices or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n) {
  int s_len;
  int word_len;
  int total_len;
  int *result;
  int count;
  int i;

  if (!s || !words || nb_words <= 0 || !n) {
    *n = 0;
    return (NULL);
  }

  word_len = _strlen(words[0]);
  if (word_len == 0) {
    *n = 0;
    return (NULL);
  }

  s_len = _strlen(s);
  total_len = word_len * nb_words;

  if (total_len > s_len) {
    *n = 0;
    return (NULL);
  }

  result = malloc(sizeof(int) * (s_len - total_len + 1));
  if (!result) {
    *n = 0;
    return (NULL);
  }

  count = 0;
  for (i = 0; i <= s_len - total_len; i++) {
    if (_is_valid(s, i, word_len, nb_words, words)) {
      result[count] = i;
      count++;
    }
  }

  if (count == 0) {
    free(result);
    *n = 0;
    return (NULL);
  }

  *n = count;
  return (result);
}