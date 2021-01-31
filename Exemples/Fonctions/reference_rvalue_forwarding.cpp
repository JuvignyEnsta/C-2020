#include <iostream>
#include <vector>

void set_data( std::vector<double>& u, std::vector<double>&& temp)
{
    temp.swap(u);
}

void set_data2( auto& u, auto&& temp )
{
    temp.swap(u);
}

int main()
{
    std::vector u{1.,2.,3.,4.};

    set_data(u, {1.,2.,5.,6.,3.,7.});

    std::vector v{-1.,-2.,-3.,-4.};
    // set_data(u, v); // Erreur de compilation

    set_data2(u, std::vector{1.,2.,5.,6.,3.,7.});
    set_data2(u, v);

}