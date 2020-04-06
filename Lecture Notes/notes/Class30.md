# CLASS 30:

** Code coverage, mutation analysis, and evaluation of fuzzing **

Question of the day:  what is the best fuzzer?  how would we know?  how would we know when a fuzzer gets _better_ over time, or worse or...?

(These are **hard** questions, I've spent a good chunk of my too-long career messing with this stuff and I'm still not there)

* **CODE COVERAGE**: What is it?

* * Code coverage is a way to measure how much a testing effort accomplished, how tested a program is, what you missed in testing

* * Often as simple as "count the branches and statements that were run/not run in my code"

* * If you don't even run a line of code, _pretty tricky_ to find a bug in it!

* * **REQUIRED READING:  https://agroce.github.io/onwardessays14.pdf **

* * Code coverage is one way to evaluate fuzzers.  For example, check out the recent jump in effectiveness of Honggfuzz  here:  https://www.fuzzbench.com/reports/2020-04-01/index.html

* * But evaluating fuzzers properly is tricky business (one of my main research interests)

* * **REQUIRED READING:  https://www.cs.umd.edu/~mwh/papers/fuzzeval.pdf**

* * ** VIDEO: https://www.youtube.com/watch?v=ID8XtoMn43I **

-------------------------------------------------------------------

* **MUTATION TESTING**: What is it?

* * If you read the above stuff, we already told you:  introducing a lot of little changes that are basically _fake bugs_

* * Then instead of measuring what code we executed, we measure which of the bugs we were able to detect

* * **Good:**  coverage can't tell you if you run some code but _you totally ignore anything it does, and so you might as well not run it_

* * E.g., you could run a program inside a wrapper that hides all crashes and sends output to /dev/null.  Sure you, "covered" the code, but if a tree falls in a forest, and you dump the forest into a black hole, does it make a sound?

* * **Bad:** mutation testing is _expensive_ and _more complicated_ than coverage

* * ** VIDEO: https://www.youtube.com/watch?v=4bublRBCLVQ **

* * ** VIDEO: https://www.youtube.com/watch?v=rlfcGUDkSjQ **

* * ** VIDEO:  https://www.youtube.com/watch?v=NKEptA3KP08 **

* * ** VIDEO: https://www.youtube.com/watch?v=2T23mPVq2Hs **

-------------------------------------------------------------------

* **THAT IS A LOT OF STUFF, AND EVERYBODY IS ARGUING, WHAT IS A GOOD SUMMARY?**

* * Code coverage is probably useful; if you have an important embedded system, and you didn't even _run some of the code_ what the heck, man?

* * Mutation analysis is going the extra mile!  Once you have good coverage, you really should use mutants to see if you are _actually testing things_ if finding bugs is important for you

* * For important software (and **embedded systems** are often going to be in this class), you may want to not just measure a score but _examine every not-killed mutant by hand_

* * * ** VIDEO: https://www.youtube.com/watch?v=tFmajPt0_hI **

* * * ** READING: https://agroce.github.io/asej18.pdf **

* * * The reading also introduces CBMC, our topic for next week

-------------------------------------------------------------------

* **Ok, fine, but in practice how do you measure simple code coverage?**

* * You're gonna have to do that for the project!

* * https://clang.llvm.org/docs/SourceBasedCodeCoverage.html

* * https://blog.trailofbits.com/2019/11/11/test-case-reduction/

-------------------------------------------------------------------

* **And what if I want to do mutation testing too?**

* * Use my universalmutator tool?

* * https://blog.trailofbits.com/2019/01/23/fuzzing-an-api-with-deepstate-part-2/ has pretty good example commands for doing mutation analysis using the tool

* * Ask me questions, it's my tool!
