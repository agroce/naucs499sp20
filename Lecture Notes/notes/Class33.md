# CLASS 32:

**REVIEW FOR THE SECOND TEST, PART THE FIRST**

This test will be cumulative, though not, technically a final; the
material will be strongly weighted towards what we did not cover the
first time.

The test will be on the 29th of April.

The core subjects covered are:

* Symbolic execution
* Static analysis
* Coverage
* Mutation testing/analysis
* CBMC and bounded model checking
* Timing

The easiest way to review is to look over class notes from "class 28"
to "class 32."

I'll start off with some summary points, though, high level views of
each topic.

* Symbolic execution is a very powerful tool that can find bugs very
  hard to find any other way; alas, it is also very hard to scale it
  to complex runs of large program.  Essentially, it has to solve
  complex equations, even with some "modern" tricks that put in value
  like system calls and pointer values via grabbing them from a real
  ("concrete") run.  In embedded code, you *might* have something
  simple enough to handle with symbolic execution, completely.  Or an
  individual important function worth checking that way.  But you
  might not.  It's an important tool to keep an eye on.  A big
  advantage of DeepState is that you can apply symbolic execution
  without tying yourself to a lot of work to use it.

* **Static analysis** is arguably the most powerful tool in our
  bug-hunting kit right now, in some ways.  It looks for bugs without
  running code, which means it can find things where generating a test
  is almost impossible.  Developing safety critical or mission
  critical embedded code without applying good static analysis is
  pretty much negligent behavior, in my opinion.  We still need
  testing; pointers and some other things can confuse static analysis,
  and it has to trade off missing some bugs with avoiding reporting
  all kinds of false positives.  If you report too many false
  positives, you might as well not report anything!

* Coverage is good.  I provided a lot of material on the controversies
  over coverage, but for most embedded systems code, you really should
  just achieve 100% statement and branch coverage with your
  tests/fuzzing.  The code is usually small, and it seldom involves a
  complex parser you don't want to fully cover.  Even the exceptions,
  you can work around:  for example, you might not want to test every
  single way an embedded file system can fail to mount a volume.  Very
  well, get 100% over all the code outside the mount, then, and use
  mount repeatedly in your tests (after a reset) to check for
  problems.

* Mutation is adding fake bugs to code in order to push beyond
  coverage.  The main weakness of coverage is that you can run code
  but not check anything about its correctness, and then what was the
  point?  Mutation forces you to catch fake bugs, or know why you
  failed to catch them.

* CBMC is in a way a kind of symbolic execution, but it's often faster
  for problems it is good at.  The big difference/limitation is that
  CBMC forces you to say how many times you allow loops to unroll.
  It will tell you if they can run more times than that, as a "bug."
  When you have loop-free code or code with small bounds on loops
  (both are pretty frequent in embedded world!) you can often use CBMC
  to just prove code correct.  That's nice!

* Timing is a tricky and annoying property to check for, but can be
  very important in embedded code.
