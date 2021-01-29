#include <iostream>
#include <vector>
#include <cstdio>

double dot_c(std::int64_t n, const double* x, const double* y)
{
    double sum = 0;
    for ( std::int64_t i = 0; i < n; ++i )
        sum += x[i]*y[i];
    return sum;
}

auto dot_f1(std::int64_t n, const double* x, const double* y) -> double
{
    double sum = 0;
    for ( std::int64_t i = 0; i < n; ++i )
        sum += x[i]*y[i];
    return sum;
}

auto dot_f2(std::int64_t n, const double* x, const double* y)
{
    double sum = 0;
    for ( std::int64_t i = 0; i < n; ++i )
        sum += x[i]*y[i];
    return sum;    
}

int main()
{
    std::vector x{1.,2.,3.,4.,5.,6.};
    std::vector y{6.,5.,4.,3.,2.,1.};

    double s1 = dot_c(x.size(), x.data(), y.data());
    double s2 = dot_f1(x.size(), x.data(), y.data());
    double s3 = dot_f2(x.size(), x.data(), y.data());

    std::cout << "(x|y) = " << s1 << " = " << s2 << " = " << s3 << std::endl;
    return EXIT_SUCCESS;
}