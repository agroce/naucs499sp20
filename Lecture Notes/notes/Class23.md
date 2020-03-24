CLASS 23:

* KARL POPPER:  science is _about_ falsification and "mean-spirited"
experiments

* ALEX GROCE: testing/debugging is pretty much doing science on a
program instead of the natural world (https://agroce.github.io/asej18.pdf)

* Printf is great; just don't randomly pepper your code with printfs
  to debug; think of printfs as experiments you are performing; they
  should be able to SURPRISE you; they should maybe FALSIFY some
  theory of the program...

What did people do WRONG on assignment 1?

No. 1 by a long shot:  USED RAND, WHICH IS BAD

LLVMTestOneInput(whatever) {
  // I'm just gonna totally ignore "whatever"
  int n = rand();
  foo(n);
  }

No. 2, ignored libfuzzer call signature:

LLVMTestOneInput(int a, int b, int c) {