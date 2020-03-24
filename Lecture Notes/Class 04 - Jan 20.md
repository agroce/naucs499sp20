# CLASS 4:  We will start talking about *fuzzing*

Things to look at:

* Good overview of Bart Miller's work, includes links to the paper(s):  https://blog.trailofbits.com/2018/12/31/fuzzing-like-its-1989/

* The AFL website: http://lcamtuf.coredump.cx/afl/

- our program reads bytes from stdin

- our program is broken iff it crashes


FUZZING

64 bytes
1st and last must match
4th byte must be 4
no byte between 5 and 63 can be over 5
(6/256)^(63-5+1)

P(crash) = 1/256 * 1/256

coverage:

I have 10 inputs, let's say our program has 10 statements

0: 0101000000
1: 0101000000
2: 0101000000
3: 0101000000
4: 0101000000
5: 0101000000
6: 0101000000
7: 0101000000
8: 1101010100
9: 0100011110

coverage to PATH coverages

- Identify interesting inputs, by some measure of coverage
- Try making (small, usually) changes to those inputs
- Repeat