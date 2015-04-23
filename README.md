# cpp-logprobs
C++ implementation of log-space arithmetic for probabilities

This is a library for doing simple but accurate and efficient claculations with small prbabilities in C++.
The arithmetic for the probabilities is done in log space, to prevent underflowing 64-bit double precision.

# Usage
If you put `logprobs.hpp` and `logprobs.cpp` in the same directory as your project, all you need to do is add `#include "logprobs.hpp"` to the top of whatever file you want to use `logprobs` in.

The file `test.cpp` shows how to use the library.
The library uses the namespace `logprob`, so any function you want is called using `logprob::<thefunction>`.
I define two type aliases to help keep track of whether the number you're using is in log space (`logprobs::logprob`), or a normal probability (logprobs::prob).
C++ has weak type checking, so you can still mess yourself up since both types are just aliased to `double`, but I think it help keep things straight.
