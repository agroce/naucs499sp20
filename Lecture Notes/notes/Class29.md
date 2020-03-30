# CLASS 29:

(yes, I swapped with coverage/mutation analysis and ensemble fuzzing,
trying to line up a guest lecture for mutation)

Static analysis (SA) looks for problems in code _without running it_

* Bad "patterns" in source code
* **Over-approximation** (or **under-approximation**) of all _possible_ runs of a program
* Often analyzes functions or parts of code in isolation

* Compiler warnings are static analysis: your code is wrong, but no
tests were run

* Good intro notes on SA:
https://www.cs.colorado.edu/~kena/classes/5828/s12/presentation-materials/blackshearsam.pdf
* **Sound** analysis overapproximates; if a sound analysis says your
code is bug-free, congratulations! -- But bugs may be false alarms,
behaviors that can't really happen
* **Complete** analysis underapproximates: when it finds a bug, it's
  real, but it might miss some bugs

* We've been mostly covering _dynamic analysis_ (which nobody calls
DA, by the way)

* Differences:

* * Dynamic requires compiling the code, running it, has to produce
tests
* * Many properties are hard for dynamic analysis, as we've seen
* * Dynamic analysis can never say "yup, your program is bug-free"
* * Static analysis can say that in some cases (see notes above for
sound analyses)
* * Dynamic usually under-approximates behavior

* * OTOH, dynamic analyis produces way fewer false positives!
* * Balancing bug detection with limiting false positives is a key trade
off in SA
* * If a tool says every line is "maybe buggy" it might as well say nothing!

**VIDEO AND READING ASSIGNMENTS BELOW**

-----------------------------------------------------

Video:  my old boss on SA at JPL:
https://www.youtube.com/watch?v=mVkz-ETpb0w
* His talk starts at around the 30 minute mark
* https://github.com/nimble-code/Cobra is the tool he talks about
* http://spinroot.com/uno/ is another of his SA tools

There are numerous free tools, here's an older talk on them:
https://www.youtube.com/watch?v=sn1Vg8A_MPU
* The best/most powerful tools are things like
Coverity/CodeSonar/KlocWork that cost **BIG BUCKS**
* Worth it for serious non-free code
* Open source projects can get free analysis:  https://scan.coverity.com/faq

Reading:  https://cacm.acm.org/magazines/2010/2/69354-a-few-billion-lines-of-code-later/fulltext
