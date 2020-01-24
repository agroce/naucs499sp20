#include <stddef.h>
#include <stdint.h>

#include "pbuffer.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  if (Size >= 64) {
    pbuffer((unsigned char *) Data);
  }
  return 0;  // Non-zero return values are reserved for future use.
}
