#include "pbuffer.h"

void pbuffer(unsigned char *buffer) {
  for (int i = 4; i < 64; i++) {
    if (buffer[i] != i) {
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
