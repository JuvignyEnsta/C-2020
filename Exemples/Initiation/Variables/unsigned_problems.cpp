#include <iostream>

int main()
{
  std::cerr << "Attention, ce programme doit faire une boucle infinie. Veuillez le terminer avec in Ctrl + C"
            << std::flush << std::endl;
  // Recherche racine carrée d'un entier de la forme n² par dichotomie
  std::uint32_t sqn = 3249; // n² = 57²
  std::uint32_t a = sqn;
  std::uint32_t b = 0;
  std::uint32_t c = (a+b)/2;
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