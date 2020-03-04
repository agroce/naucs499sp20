# CS499, Spring 2020, Embedded Systems Testing

Prof [Alex Groce](https://agroce.github.io)

Why Embedded Testing Really Matters:
* https://safeautonomy.blogspot.com/p/safe-autonomy.html

More to come, see syllabi here for overview of topics, flow of the class

Office hours Wednesday 8:00am-9:00am (SICCS 208)

First reading, to prepare yourselves: https://www.usenix.org/system/files/1311_05-08_mickens.pdf

CLASS 1: General Overview of Class

* We're going to torture software (automatically) in order to find bugs
* We are interested in code in C/C++, mostly
* Highly critical code, sometimes safety-critical
* But written in low-level, bug-prone languages

CLASS 2: Embedded Software, What is It?

* Embedded software:  
* * Software running on something that's not "primarily a computer"
* * May not even have an operating system
* * Lives in computing power/memory constrained environment
* * "Talks to hardware, not people"
* * In particular, sensors + actuators is often the model
* * "Old school" physical world not social media land
* * Examples:  automotive, power plants, aerospace, robots, Internet of Things (controlled by the Russian mafia)...

CLASS 3:  Read Mickens, particular problems of testing embedded world; break the code, break the "OS" and you can't debug/trace

* We looked at some actual example code
* * https://github.com/TheSEGAProject/CP-Firmware (Paul Flikkema's group)
* * https://github.com/nasa/fprime (NASA "boilerplate" embedded code for CubeSAT "cheapo" satellite missions)

CLASS 4:  We will start talking about *fuzzing*

Things to look at:

* Good overview of Bart Miller's work, includes links to the paper(s):  https://blog.trailofbits.com/2018/12/31/fuzzing-like-its-1989/

* The AFL website: http://lcamtuf.coredump.cx/afl/

CLASS 5:  We talked more about fuzzing and ran AFL and libfuzzer

CLASS 6:  We're finishing up the intro to fuzzing

**[ASSIGNMENT 1](https://github.com/agroce/naucs499sp20/blob/master/assignment1.txt) 
went out**

* Topic:  command line options for fuzzers, esp. -use_value_profile=1
* Topic:  fuzzer behavior depends on two things (well, lots of things,
but):
* * Notion of WHAT IS INTERESTING BEHAVIOR?
* * How to modify/mutate files
* There is no "best fuzzer" -- need to run many, hope to get lucky!

CLASS 7: Sanitizers 1

* Sanitizers are powerful tools for _making your code crash more_
* Expose bad behavior that slips by, e.g. memory-safety issues
* -fsanitize=address - AddressSanitizer (ASAN) is best known, most
useful
* Others:  undefined (UBSAN), integer, memory (uninitialized values),
thread

* Sanitizers are SLOW:  2x up to much worse slowdown; in class we saw
4x
* Slow is fine for unit tests, but not so hot for fuzzing
* Sanitizers are VERBOSE -- real code produces lots of bogus warnings, often

* Good general reading on the sanitizers from Google is at
  https://github.com/google/sanitizers -- in particular, note the top
  contributor, kcc : Kostya Serebryany (known as "Kostya" like
  "Prince" or "Madonna" to security/testing people) is also the
  libFuzzer Guy

CLASS 8: Sanitizers Big Picture / Odds and Ends

* Well defined behavior: program only does "legal" things
* Implementation-defined behavior: program does stuff where compilers
  can vary, but there is a requirement to have some meaning, often
  within constraints
  * Undefined behavior: see https://blog.regehr.org/archives/213

* Fuzzing crypto can be tough:  no paths, in part to avoid
timing/power attacks

* Run fuzzing in a VM, to avoid a bug trashing your file system

* radamsa is a "mess with this input" fuzzer

READINGS FOR NEXT WEEK:

* https://www.cs.princeton.edu/courses/archive/fall12/cos109/mars.rover.pdf
* https://spaceflight.nasa.gov/spacenews/releases/2000/mpl/mpl_report_1.pdf

CLASS 9:

* NASA Gossip, My Career

CLASS 10:

* Test what you fly

* Doing fixed operations with systematic or even random faults is not enough, need random
operations (see tester.txt)

* Rename's a beast

* MER shows lots of GOOD practices (paranoia, systems that do
  predictable talking to home, heavy fault protection), and some
  weaknesses in testing

CLASS 11:

* Mars Polar Lander

* additional info: http://web.mit.edu/16.070/www/readings/Failures_MCO_MPL.pdf

* If a test fails and you "fix" the bug, run the test again to make sure

* Never assume requirements are complete!

* Backdoors from compiler bugs:  see https://www.alchemistowl.org/pocorgtfo/pocorgtfo08.pdf -- also, the classic article here is https://www.cs.cmu.edu/~rdriley/487/papers/Thompson_1984_ReflectionsonTrustingTrust.pdf (Ken Thompson's Turing Award speech)

* Testing has grave responsibility (and, ok, often not that much power, sorry)

CLASS 12:

* Fuzzing a simple library with afl (see stack_example directory)

* Why DeepState -- see https://github.com/agroce/deepstate-stack

* **READING ASSIGNMENT FOR WEDNESDAY:** https://blog.trailofbits.com/2019/01/22/fuzzing-an-api-with-deepstate-part-1/

CLASS 13:

* We ran a bunch of fuzzers, and looked for pizza

* DeepState lets you run many different fuzzers (and other tools) easily

* DeepState is a unit testing library, but you can ask a tool to pick the values forr you

* See deepstate_example

CLASS 14:

* More DeepState, this time a look at the stack example

* Introduced swarm testing (see https://agroce.github.io/issta12.pdf)

* See file swarm.txt; we could find the stack "bug" in no time with swarm, not find it in hours without using it

* DeepState lets us apply meta-heuristics, "extra tricks" on top of fuzzers like AFL/libFuzzer

* See unittestsort.txt for a preview of Monday

CLASS 15:

* Writing a test for generic binary search (see binsearch directory)

* Setting up input is tricky; fuzzer really will generate ANYTHING you let it

* Also we learned
  https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
  (a top google hit) has a broken comparison function.  TRUST NO ONE!

CLASS 16:

**[ASSIGNMENT 2](https://github.com/agroce/naucs499sp20/blob/master/assignment2.txt) 
went out**

* We looked at https://github.com/agroce/deepstate-c-blosc2 and discussed how to generalize tests from https://github.com/Blosc/c-blosc2

* Look at the general API, purpose of software; no substitute for domain knowledge of what you are testing!

* Examine actual tests, see *what can be generalized*

* Hunt for **ROUND TRIP** properties, especially: these are subtle, hard to get right, and present all over the place.  This is when f(g(x)) should be x again.  File systems and containers are even like this (read(write(data)) should just get you the data; get(key, set(key, value)) ought to be value.  And compression libraries should not change data.

* We looked at a real bug in c-blosc2 found with DeepState

CLASS 17:

* The midterm will be Friday of the week assignment 2 is due; we'll review Mon & Wed

* We looked at simulating hardware.  Why?  Real hardware is slow, hard to inject faults in, and may be expensive/dangerous to mess with/not exist

* We looked at simulated resets in https://github.com/agroce/testfs

* Injecting faults via fuzzing is a really good way to poke holes in even good embedded code

CLASS 18:

* We added corruption to resets, and found a LOT more bugs, quicker

* But "cranking up" to a harder fault model may not be a good idea, if less nasty faults are finding lots of bugs; fix the more likely ones first, avoid arguing about what the system should handle

CLASS 19:

* Use docker commit to save your docker containers

* Go read
  https://www.amazon.com/Masterminds-Programming-Conversations-Creators-Languages/dp/0596515170
  -- great book!  Look for the quote that all software ends up either
  failed or a legacy horror!  (NOTE: NOT A READING ASSIGNMENT, JUST A
  FRIENDLY ENDORSEMENT OF THE BOOK)

CLASS 20:

* Triage is as important as bug-finding: report, effectively, unique
bugs

* Need to REDUCE test cases to something minimal (deepstate-reduce
will help) -- read https://blog.trailofbits.com/2019/11/11/test-case-reduction/

* Domain knowledge helps understand which bugs look nastiest

* Art, not a science

* The easy case is when each kind of bug has a specific crash output
(assertion on line X, segfault at Y, etc.)

CLASS 21:

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

