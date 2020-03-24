#include <deepstate/DeepState.hpp>
using namespace deepstate;

TEST(Pythagorean, Triple) {
  unsigned a = DeepState_UIntInRange(1, 10000);
  unsigned b = DeepState_UIntInRange(1, 10000);
  unsigned c = DeepState_UIntInRange(30, 10000);

  ASSERT ((a*a + b*b) != c*c) << a <<"^2 + " << b << "^2 = " << c << "^2";
}
