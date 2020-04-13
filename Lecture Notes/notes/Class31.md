# CLASS 31:

**CBMC and Model Checking**

Another kind of "symbolic execution" is SAT-based bounded model checking.

Idea:

1. take a program, specify how  many times loops are allowed to be run (max bound, hence "bounded")
2. turn the program into a big equation over bit-values that has a solution iff the program can violate a property
3. solve the giant Boolean SAT equation

The CBMC (C Bounded Model Checker) tool does this, and has become quite practical for some embedded verification tasks.  Often much faster than angr/manticore style execution (partly because it doesn't really model full memory contents, just ANSI C semantics)

Tool: http://www.cprover.org/cbmc/

CBMC is easy to install, and works on Linux, Mac, and even Windows (though getting it set up with Visual Studio tools can be a pain, last time I checked).

A simple example, with no loops (so the limits of **bounded** model checking don't matter:

```
int nondet_int();

int main() {
  int x = nondet_int();
  int y = nondet_int();
  __CPROVER_assume(x > 0);
  __CPROVER_assume(y > 0);
  printf("x=%d, y=%d\n", x, y);
  assert ((x * y) != (x + y) + 5);
}
```
What's all this mean?

Because it has no body, CBMC assumes `nondet_int()` can return anything of the appropriate return type.  `__CPROVER_assume` lets you encode _assumptions_ about values (ignore tests that don't satisfy assumptions).  And you know assert.

If we run CBMC like this:

```
cbmc_examples adg326$ cbmc noloops.c --trace
CBMC version 5.11 (cbmc-5.11-733-ge2a543033) 64-bit x86_64 macos
Parsing noloops.c
Converting
Type-checking noloops
file noloops.c line 8 function main: function `printf' is not declared
file noloops.c line 9 function main: function `assert' is not declared
Generating GOTO Program
Adding CPROVER library (x86_64)
Removal of function pointers and virtual functions
Generic Property Instrumentation
Running with 8 object bits, 56 offset bits (default)
Starting Bounded Model Checking
size of program expression: 38 steps
simple slicing removed 5 assignments
Generated 1 VCC(s), 1 remaining after simplification
Passing problem to propositional reduction
converting SSA
Running propositional reduction
Post-processing
Solving with MiniSAT 2.2.1 with simplifier
2225 variables, 10554 clauses
SAT checker: instance is SATISFIABLE
Runtime decision procedure: 0.0148293s

** Results:
noloops.c function main
[main.assertion.1] line 9 assertion x * y != x + y + 5: FAILURE

Trace for main.assertion.1:

State 17 file noloops.c function main line 4 thread 0
----------------------------------------------------
  x=0 (00000000 00000000 00000000 00000000)

State 18 file noloops.c function main line 4 thread 0
----------------------------------------------------
  x=7 (00000000 00000000 00000000 00000111)

State 19 file noloops.c function main line 5 thread 0
----------------------------------------------------
  y=0 (00000000 00000000 00000000 00000000)

State 20 file noloops.c function main line 5 thread 0
----------------------------------------------------
  y=2 (00000000 00000000 00000000 00000010)
x=7, y=2


Violated property:
  file noloops.c function main line 9 thread 0
  assertion x * y != x + y + 5
  x * y != x + y + 5



** 1 of 1 failed (1 iteration)
VERIFICATION FAILED
```

What about if we have a loop?

The code above is in the "cbmc_examples" dir in the class repo now, also.

```
int nondet_int();

#define SIZE 5

int main() {
  int a[SIZE];
  for (int i = 0; i < SIZE; i++) {
    a[i] = nondet_int();
    printf("LOG: a[%d] = %d\n", i, a[i]);
  }

  // MAKE SURE NO DUPLICATES BY ADDING
  for (int i = 0; i < (SIZE-1); i++) {
    for (int j = i + 1; j < SIZE; j++) {
      if (a[i] == a[j]) {
        printf("LOG: setting a[%d] to %d to avoid matching a[%d]\n", i, a[i]+1, j);
        a[i] = a[i] + 1;
      }
    }
  }

  // CHECK FOR DUPLICATES
  for (int i = 0; i < (SIZE-1); i++) {
    for (int j = i + 1; j < SIZE; j++) {
      if (a[i] == a[j]) {
        printf("LOG a[%d] = %d = a[%d]\n", i, a[i], j);
      }
      assert(a[i] != a[j]);
    }
  }
}
```

Simple code to make sure an array is modified to have no duplicated values.  Seems legit, right?

Now, let's run this, and ignore all the details CBMC produces, AND ask CBMC to "beautify" (simplify) the output trace to make it easier to understand:

```
cbmc loops.c --trace --beautify >& log
(base) cmp3149:cbmc_examples adg326$ grep LOG log
LOG: a[0] = -1
LOG: a[1] = 0
LOG: a[2] = -1
LOG: a[3] = -1
LOG: a[4] = -1
LOG: setting a[0] to 0 to avoid matching a[2]
LOG: setting a[2] to 0 to avoid matching a[3]
LOG: setting a[3] to 0 to avoid matching a[4]
LOG a[0] = 0 = a[1]

```

**READING:** http://www.kroening.com/papers/tacas2004.pdf

**VIDEO** https://www.youtube.com/watch?v=RxHjhBVOCSU
(not just about CBMC, whole question of how usable these tools are getting, compared to the past)


Getting CBMC to work with complex code with lots of system library calls is hard, but for core algorithms, or critical pieces of embeddded C code, it is extremely fast and powerful, often.  It has been used on some VERY hairy real code:  https://arxiv.org/pdf/1610.03052.pdf
