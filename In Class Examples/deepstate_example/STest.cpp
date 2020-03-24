#include <deepstate/DeepState.hpp>

using namespace deepstate;


TEST(Test, PizzaHunt) {
  char* s = DeepState_CStrUpToLen(30);
  
  ASSERT (strstr(s, "pizza") == NULL) << "I FOUND PIZZA!";
}
