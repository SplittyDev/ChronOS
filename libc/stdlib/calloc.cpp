#include <stdlib.h>
#include <string.h>

void *calloc (size_t nitems, size_t size) {
  void *ptr = malloc (nitems * size);
  if (ptr) {
    memset (ptr, 0, nitems * size);
    return ptr;
  }
  return NULL;
}
