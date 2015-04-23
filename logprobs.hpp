#ifndef LOGPROBS_H_INCLUDED   // if logprobs.hpp hasn't been included yet...
#define LOGPROBS_H_INCLUDED   // #define this so the compiler knows it has been included

namespace logprobs
{
    typedef double logprob;
    typedef double prob;
    
    logprob norm2log(prob x);
    prob log2norm(logprob x);
    logprob multiply(logprob x, logprob y);
    logprob divide(logprob x, logprob y);
    logprob add(logprob x, logprob y);
    logprob subtract(logprob x, logprob y);
}

#endif /* LOGPROBS_H_INCLUDED */
