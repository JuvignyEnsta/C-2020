#include <iostream>

int main()
{
    int values[] = {1,2,3,4,5};
    const int cst_values[] = {-1,-2,-3};
    const int c = -4;

    int *const pt_value = values + 2;
    *pt_value = -3;
    // pt_value++; <-- erreur de compilation, pt_value est un pointeur constant
    std::cout << *pt_value << std::endl;

    int const* pt_value2 = values + 3;
    //*pt_value2 = -4; <-- Erreur de compilation, pt_value2 pointe sur une valeur considérée comme constante
    pt_value2++; // Ca marche, car le pointeur lui-même n'est pas constant !
    std::cout << *pt_value2;

    int const* pt_value3 = cst_values + 1;// Pointe sur -2
    pt_value3 = &c; // Pointe sur la variable constante c.
    std::cout << "pt_value3 pointe sur " << *pt_value3 << std::endl;

    // int* pt_value4 = cst_values; <--- Erreur compilation car cst_values constant

}