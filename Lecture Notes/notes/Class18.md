# CLASS 18:

**[ASSIGNMENT 2](https://github.com/agroce/naucs499sp20/blob/master/assignment2.txt) 
went out**

* We looked at https://github.com/agroce/deepstate-c-blosc2 and discussed how to generalize tests from https://github.com/Blosc/c-blosc2

* Look at the general API, purpose of software; no substitute for domain knowledge of what you are testing!

* Examine actual tests, see *what can be generalized*

* Hunt for **ROUND TRIP** properties, especially: these are subtle, hard to get right, and present all over the place.  This is when f(g(x)) should be x again.  File systems and containers are even like this (read(write(data)) should just get you the data; get(key, set(key, value)) ought to be value.  And compression libraries should not change data.