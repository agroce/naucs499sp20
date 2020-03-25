# CLASS 8: Sanitizers 1

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