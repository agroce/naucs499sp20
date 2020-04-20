# CLASS 32:

**Timing**

A common need in embedded systems is to ensure some processing
satisfies a deadline.  Embedded code is often "real-time".  If a
sensor's results take a minute to process, this may be a bit slow for
a braking system!

In deepstate_timing/timing.cpp you see a DeepState harness checking
the execution time for a (rather bogus!) example with a five second
deadline.  Play with it, and discover for yourself the interesting
aspects of such examples.  Wednesday I will discuss what you should be
aware of by then.
