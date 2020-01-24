#include "pbuffer.h"

void pbuffer(unsigned char *buffer) {
  for (int i = 5; i < 64; i++) {
    if ((unsigned)buffer[i] > 5) {
      return;;
    }
  }
  if (buffer[0] != buffer[63]) {
    return;
  }
  if (buffer[4] == 4) {
    assert(0);
  }
}
