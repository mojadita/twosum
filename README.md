## Program to solve a simplified Knapsack problem.

The target of this game is to read a list of numbers and
a target sum, and try to find two numbers in the list that
satisfy the addition.

The program operates by sorting the list as doing this way
we can follow a direct algorithm that allows to discard
already visited numbers when we switch to scan from one number
to the next... if the sum has to conseve, if the first number
is greater, the second must be lesser.

We begin sorting the array received and initializing two
pointers to the two sides of the array.  If the sum is
larger than the target, we proceed by moving the larger number
pointer, and recheck.  We stop when the pointers meet at
some point in the array.

Actually, this project is made of two programs, the main
algorithm, called `twosum`, and a simple random number `generator`
to test it.

`twosum` uses the following options:

    twosum [ ... options ]

* **-v**, to produce a trace of the iterations the algorithm is
doing.
* **-t** _target_, to indicate the target sum to pursue.

`generator`, on the other side uses the following options:

    generator [ ... options ]

* **-n** _number_, to fix the number of random numbers to generate.
* **-m** _number_, to fix the minimum random value to generate.
* **-M** _number_, to fix the maximum random number (well, the number
used is the maximum plus one) generated.
* **-s** _seed_, to fix the random number generator seed.  If you
don't use this option, it defaults to some number derived from the
current time.  You can use this option to regenerate the same sequence
of numbers.  The program prints the seed used to stderr when executed.
