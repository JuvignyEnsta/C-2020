#include <iostream>
#include <complex>
using namespace std::complex_literals;

auto produit_conjugué( std::complex<double> z1, std::complex<double> z2 )
{
    return std::complex{z1.real()*z2.real()+z1.imag()*z2.imag(),
                        z2.real()*z1.imag()-z1.real()*z2.imag()};
}

auto produit_conjugué2 ( std::complex<double> z1, std::complex<double> z2 ) -> decltype(z1)
{
    return {z1.real()*z2.real()+z1.imag()*z2.imag(),
            z2.real()*z1.imag()-z1.real()*z2.imag()};
}
