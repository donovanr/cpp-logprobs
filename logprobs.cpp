#include "logprobs.hpp"
#include <cmath>
#include <iostream>
#include <cassert>
#include <stdexcept>

namespace logprobs
{
    /* convert normal probabilty to log-space */
    logprob norm2log(prob x)
    {
        return log(x);
    }

    /* convert log probabilty to normal-space */
    prob log2norm(logprob x)
    {
        return exp(x);
    }
    
    /* multiplication is addition in logspace */
    logprob multiply(logprob x, logprob y)
    {
        logprob z;
        z = x + y;
        return z;
    }
    
    /* division is subtraction in logspace */
    logprob divide(logprob x, logprob y)
    {
        logprob z;
        z = x - y;
        return z;
    }

    
    /* only do the +/- computations if it matters at 64 bits */
    double threshold = log(2.0)*64.0 + 1.0;
    
    /* addition is a more numerically stable version of log(e^x + e^y) */
    logprob add(logprob x, logprob y)
    {
        logprob z;
        
        /* make sure x > y, so that exp(y-x) < 1 */
        if (y > x) {
            std::swap(x,y);
        }
    
        if (x - y > threshold) {
            z = x;
        }
        else {
            z = x + log1p(exp(y-x));
        }
        
        return z;
    }
    
    /* subtraction is a more numerically stable version of log(e^x - e^y) */
    logprob subtract(logprob x, logprob y)
    {
        logprob z;
        
        /* subtracting a larger number from a smaller one -> neg probabiliy*/
        /* try/catch for error message, assert to force a crash */
        try{
            if (y > x) {
                throw std::invalid_argument("Log Subtraction Error: subtracted a larger number from a smaller one and tried to take the log of a negative number");
            }
        }
        catch( const std::invalid_argument& e ) {
            std::cerr << e.what() << std::endl;
        }
        assert(x > y);
        
        if (x - y > threshold) {
            z = x;
        } else {
            z = x + log1p(-exp(y-x));
        }
        
        return z;
    }
}
