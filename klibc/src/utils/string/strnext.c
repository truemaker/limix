#include <stddef.h>

size_t strnext(char *s, char c) {
  size_t i = 0;
  while (*s && *s != c) {
    i++;
    s++;
  }
  return i;
}