# CS499, Spring 2020, Embedded Systems Testing

Prof [Alex Groce](https://agroce.github.io)

Why Embedded Testing Really Matters:
* https://safeautonomy.blogspot.com/p/safe-autonomy.html

More to come, see syllabi here for overview of topics, flow of the class

Office hours Wednesday 8:00am-9:00am

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

*[ASSIGNMENT 1](https://github.com/agroce/naucs499sp20/blob/master/assignment1.txt)
 went out*
