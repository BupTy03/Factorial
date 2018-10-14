#pragma once

#ifndef FACTORIAL
#define FACTORIAL

#include <type_traits>
#include <array>

template<int N, typename = typename std::enable_if<(N <= 21 && N >= 1)>::type>
struct Factorial
{
    Factorial()
    {
        arr.at(0) = 1L;
        for (unsigned long long i = 1L; i < N; ++i)
        {
            arr.at(i) = arr.at(i - 1L) * i;
        }
    }
    unsigned long long operator()(int n) const
    {
        if (n < 0 || n >= N)
        {
            return 0;
        }
        return arr.at(n);
    }
private:
    std::array<unsigned long long, N> arr;
};

Factorial<21> fact;


#endif // FACTORIAL