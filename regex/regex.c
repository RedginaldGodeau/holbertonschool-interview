/**
 * file: regex.c
 * Auth: Your Name
 * Date: Current Date
 */

#include "regex.h"

/**
 * regex_match - Checks if a string matches a given pattern.
 * @str: The string to check.
 * @pattern: The pattern to match.
 *
 * Return: 1 if the string matches the pattern, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern) {
  if (!str || !pattern)
    return (0);

  if (*pattern == '\0')
    return (*str == '\0');

  if (*(pattern + 1) == '*') {
    if (regex_match(str, pattern + 2))
      return (1);
    if (*str != '\0' && (*pattern == '.' || *pattern == *str))
      return (regex_match(str + 1, pattern));
    return (0);
  } else {
    if (*str != '\0' && (*pattern == '.' || *pattern == *str))
      return (regex_match(str + 1, pattern + 1));
    return (0);
  }
}
