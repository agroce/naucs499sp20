# CLASS 9:

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