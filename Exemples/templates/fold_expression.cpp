#include <iostream>
#include <vector>

auto sum11() { return 0; }
template<typename T1, typename... T> auto
sum11(T1 const & s, T const &...  ts) { return s + sum11(ts...); }

template<typename... T> auto
sum17(T const &... args) { return (args + ...); }

template<typename... T> void
fold_printf(T&&... args) {
    (std::cout << ... << std::forward<T>(args)) << std::endl << std::flush;
}

template<typename T, typename... Args>
void push_back(std::vector<T>& v, Args&&... args) {
  (v.push_back(args),...);
}


int main()
{
    std::cout << sum11(1,2,3,4,5,6,7) << std::endl << std::flush;
    std::cout << sum17(1,2,3,4,5,6,7) << std::endl << std::flush;
    fold_printf("Ceci est un essai => ", 3.14, " et ", 40UL);

    std::vector<int> tableau;
    push_back(tableau, 1, 2, 3, 4, 5, 6);

    for ( const auto & val : tableau )
        std::cout << val << " ";
    std::cout << std::endl << std::flush;
    return EXIT_SUCCESS;
}