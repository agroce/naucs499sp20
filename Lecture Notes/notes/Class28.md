# CLASS 28: (begin online mode)

Symbolic execution!

* DeepState does not just offer fuzzing, it also provides symbolic execution.

* What is symbolic execution?  Running a program in a "mode" where
(some) inputs are not N bytes, but a kind of algebraic X.

Example:

```
int f(int x) {
   if (x > 10)
       return x;
   return x * 2;
}
```

If we symbolically execute:

`y = f(sym_x);`  where `sym_x` is a symbolic value, an input to the
program, we don't know what `y` is, exactly.  We assign `y` a choice,
approximately:

`y = sym_x > 10 ? sym_x : sym_x * 2`

The C choice encodes we took a branch based on the unknown value of
`sym_x`.

If we hit an assert:

`assert (y > 3)`

we can try to _solve_ for  an input to break the assert:

`(sym_x > 10 ? sym_x : sym_x * 2) <= 3`

so `sym_x = 0` would cause the assert to be violated.

Roughly speaking, this is what symbolic execution tools DO.

* Benefits: can find things hopeless for most fuzzers

* Downside:  scales very poorly!

TO WATCH:  https://www.youtube.com/watch?v=yRVZPvHYHzw and/or
https://www.youtube.com/watch?v=QrtGOrSrVPQ (decide which you prefer,
or watch both, this is interesting and somewhat tricky stuff)


**DEEPSTATE AND SYMBOLIC EXECUTION:**

* Try to fuzz `symex/pythag.cpp`.

* Can AFL/libFuzzer find an assertion violation?

* However:

```
user@751c72d54458:~/naucs499sp20/symex$ clang++ -o pythag pythag.cpp -ldeepstate
user@751c72d54458:~/naucs499sp20/symex$ deepstate-angr ./pythag
INFO    | 2020-03-23 18:11:55,401 | deepstate.angr | Running 1 tests across 1 workers
CRITICAL | 2020-03-23 18:13:25,761 | deepstate | pythag.cpp(9): 9^2 + 40^2 = 41^2
ERROR   | 2020-03-23 18:13:25,761 | deepstate | Failed: Pythagorean_Triple
INFO    | 2020-03-23 18:13:25,762 | deepstate | Saved test case in file out/pythag.cpp/Pythagorean_Triple/98f1e4fc62db6d65ea230ed4e8cb4b75.fail
```

angr is a SYMBOLIC EXECUTION tool that works on
BINARY CODE.  Some symbolic execution tools require source code, but
these do not.  DeepState's origin lies partly in making such tools
accessible to "normal" users, and less painful for experts.  Roughly
speaking, angr (and Trail of Bits' manticore) try to generate inputs to execute every
_path_ through a program, including assertion violations and memory
safety problems as new paths.

Fuzzers are not good at randomly generating data that forms a
Pythagorean triple, simple as this seems to us.  The symbolic tool
just solve the algebra, the way we do!