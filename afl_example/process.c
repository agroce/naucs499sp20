#include <stdio.h>
#include <assert.h>

int process(char* readings) {
  for(int i = 0; i < 64; i++) {
    if ((unsigned int)readings[i] == 0) {
      return 1;
    }
 
    if ((unsigned int)readings[i] > 67) {
      return 1;
    }
  }
  for(int i = 0; i < 64; i += 2) {
    readings[(unsigned int)readings[i]] = (unsigned int)readings[i+1];
  }
  return 1;
}

int main() {
  char buffer[64];
  for(int i = 0; i < 64; i++) {
    buffer[i] = getchar();
    printf("buffer[%u] = %u\n", i, buffer[i]);
  }

  assert(process(buffer));
}
