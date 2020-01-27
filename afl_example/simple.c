#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main() {
  unsigned char buffer[64];
  for(int i = 0; i < 64; i++) {
    buffer[i] = getchar();
    printf("buffer[%u] = %u\n", i, buffer[i]);
  }
  for (int i = 5; i < 64; i++) {
    if ((unsigned)buffer[i] > 5) {
      exit(0);
    }
  }
  if (buffer[0] != buffer[63]) {
    exit(0);
  }
  if (buffer[4] == 4) {
    assert(0);
  }
}
