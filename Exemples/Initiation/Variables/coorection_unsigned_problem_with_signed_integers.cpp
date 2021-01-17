#include <iostream>

int main()
{
  // Recherche racine carrée d'un entier de la forme n² par dichotomie
  std::int32_t sqn = 3249; // n² = 57²
  std::int32_t a = sqn;
  std::int32_t b = 0;
  std::int32_t c = (a+b)/2;
  while (c*c-sqn != 0)// Tant que c n'est pas la racine carrée de a
  {
    if (c*c-sqn<0)// Si c est plus petit que la racine carrée de a
    {
      b = c;
      c = (b+a)/2;
    }
    else
    {
      a = c;
      c = (b+a)/2;
    }
  }
  std::cout << "racine de " << sqn << " est egal a : " << c << std::endl;
  return EXIT_SUCCESS;
}