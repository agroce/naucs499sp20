#include <deepstate/DeepState.hpp>

using namespace deepstate;

void foo(char* b, size_t s) {
  if (s < 2) {
    return;
  }
  if (b[0] == 0) {
    assert (b[1] != 1);
  }
}

TEST(Test, Stuff) {
  size_t our_size = DeepState_SizeInRange(1,4096);
  LOG(TRACE) << "Size = " << our_size;
  char* buffer = (char*)DeepState_Malloc(our_size);
  for (int i = 0; i < our_size; i++) {
    LOG(TRACE) << "buffer[" << i << "] = " << (unsigned) buffer[i];
  }
  foo(buffer, our_size);
  char* s = DeepState_CStrUpToLen(30);
  
  ASSERT (strstr(s, "pizza") == NULL) << "I FOUND PIZZA!";
}
