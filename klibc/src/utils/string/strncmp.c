#include <math/lib.h>
#include <stddef.h>
#include <utils/strings/strings.h>

bool strncmp(char *a, char *b, size_t n) {
  if (min(strlen(a), n) != min(strlen(b), n))
    return false;
  int l = min(min(strlen(a), strlen(b)), n);
  for (int i = 0; i < l; i++) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}