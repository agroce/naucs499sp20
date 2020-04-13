int nondet_int();

int main() {
  int x = nondet_int();
  int y = nondet_int();
  __CPROVER_assume(x > 0);
  __CPROVER_assume(y > 0);
  printf("x=%d, y=%d\n", x, y);
  assert ((x * y) != (x + y) + 5);
}
