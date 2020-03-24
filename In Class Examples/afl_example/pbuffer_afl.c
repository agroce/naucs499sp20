#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "pbuffer.h"

int main() {
  unsigned char buffer[64];
  for(int i = 0; i < 64; i++) {
    buffer[i] = getchar();
    printf("buffer[%u] = %u\n", i, buffer[i]);
  }

  pbuffer(buffer);
}
