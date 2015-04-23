#include "logprobs.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

int main ()
{
    
    double epsilon = 1.0e-14;
    
    std::cout << "enter a probability value p between 0 and 1" << std::endl;
    logprobs::prob p;
    std::cin >> p;
    assert(0.0 < p && p <= 1.0);
    
    std::cout << "enter a probability value q between 0 and 1" << std::endl;
    logprobs::prob q;
    std::cin >> q;
    assert(0.0 < q && q <= 1.0);
    
    logprobs::logprob x = logprobs::norm2log(p);
    logprobs::logprob y = logprobs::norm2log(q);

    std::cout << std::setprecision(16);
    
    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "x = log(p) = " << x << std::endl;
    std::cout << "y = log(q) = " << y << std::endl;

    assert(std::abs(logprobs::log2norm(x) - p) < epsilon);
    assert(std::abs(logprobs::log2norm(y) - q) < epsilon);
    
    logprobs::logprob z;
    logprobs::prob r;
    logprobs::prob s;
    double d;
    
    z = logprobs::multiply(x,y);
    r = logprobs::log2norm(z);
    s = p*q;
    d = std::abs((r - s)/s);
    std::cout << "using logprobs, p*q = " << r << std::endl;
    std::cout << "using normal math, p*q = " << s << std::endl;
    std::cout << "fractional error is = " << d << std::endl;
    assert(d < epsilon);
    
    z = logprobs::divide(x,y);
    r = logprobs::log2norm(z);
    s = p/q;
    d = std::abs((r - s)/s);
    std::cout << "using logprobs, p/q = " << r << std::endl;
    std::cout << "using normal math, p/q = " << s << std::endl;
    std::cout << "fractional error is = " << d << std::endl;
    assert(d < epsilon);
    
    z = logprobs::add(x,y);
    r = logprobs::log2norm(z);
    s = p+q;
    d = std::abs((r - s)/s);
    std::cout << "using logprobs, p+q = " << r << std::endl;
    std::cout << "using normal math, p+q = " << s << std::endl;
    std::cout << "fractional error is = " << d << std::endl;
    assert(d < epsilon);
    
    z = logprobs::subtract(x,y);
    r = logprobs::log2norm(z);
    s = p-q;
    d = std::abs((r - s)/s);
    std::cout << "using logprobs, p-q = " << r << std::endl;
    std::cout << "using normal math, p-q = " << s << std::endl;
    std::cout << "fractional error is = " << d << std::endl;
    assert(d < epsilon);
    
    return 0;
}
