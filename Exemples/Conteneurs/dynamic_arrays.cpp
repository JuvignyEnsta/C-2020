#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std::string_literals;

void allocation_dynamique_avec_new_et_delete(std::size_t n)
{
    int* pt_indices = new int[n];
    auto pt_coords = new std::array<double,3>[n];
    double** matrice = new double*[n];
    for ( decltype(n) i = 0; i < n; ++i )
        matrice[i] = new double[n];

    for ( decltype(n) i = 0; i < n; ++i )
    {
        pt_indices[i] = i+1;

        pt_coords[i] = {3.*i, 2.*i, 1.5*i};

        for ( decltype(n) j = 0; j < n; ++j )
            matrice[i][j] = (i+j)%n+1;
    }

    std::cout << "indices : ";
#   if (__cplusplus > 201709L)    
    std::copy_n(pt_indices, n, std::ostream_iterator<int>(std::cout, " "));
#   else
    for ( decltype(n) i = 0; i < n; ++i )
        std::cout << pt_indices[i] << " ";
#   endif
    std::cout << "\ncoordonnées : ";
    for (decltype(n) i = 0; i < n; ++i )
        std::cout << "(" << pt_coords[i][0] << ", " << pt_coords[i][1] << ", " << pt_coords[i][2] << ") ";
    std::cout << "\nmatrice : " << std::endl;
    for ( decltype(n) i = 0; i < n; ++i )
    {
        std::cout << "|";
        for ( decltype(n) j = 0; j < n; ++j )
        {
            std::cout << std::setw(3) << matrice[i][j];
        }
        std::cout << " |\n";
    }
    std::cout << std::flush;
    for ( decltype(n) i = 0; i < n; ++i )
        delete [] matrice[i];
    delete [] matrice;
    delete [] pt_coords;
    delete [] pt_indices;    
}

void allocation_dynamique_avec_shared_ptr(std::size_t n)
{
#   if (__cplusplus > 201709L)    
    auto pt_indices = std::make_shared<int[]>(n);
    auto pt_coords  = std::make_shared<std::array<double,3>[]>(n);
#   else
    std::shared_ptr<int[]> pt_indices(new int[n]);
    std::shared_ptr<std::array<double,3>[]> pt_coords(new std::array<double,3>[n]);
#endif

    std::shared_ptr<std::shared_ptr<double[]>[]> matrice(new std::shared_ptr<double[]>[n]);
    for ( decltype(n) i = 0; i<n; ++i )
    {
        matrice[i] = std::shared_ptr<double[]>(new double[n]);
    }

    for ( decltype(n) i = 0; i<n; ++i )
    {
        pt_indices[i] = i+1;
        pt_coords[i] = {3.*i, 2.*i, 1.5*i};
        for ( decltype(n) j = 0; j < n; ++j )
            matrice[i][j] = (i+j)%n+1;
    }

    std::cout << "indices : ";
#   if (__cplusplus > 201709L)    
    std::copy_n(pt_indices, n, std::ostream_iterator<int>(std::cout, " "));
#   else
    for ( decltype(n) i = 0; i < n; ++i )
        std::cout << pt_indices[i] << " ";
#   endif
    std::cout << "\ncoordonnées : ";
    for (decltype(n) i = 0; i < n; ++i )
        std::cout << "(" << pt_coords[i][0] << ", " << pt_coords[i][1] << ", " << pt_coords[i][2] << ") ";
    std::cout << "\nmatrice : " << std::endl;
    for ( decltype(n) i = 0; i < n; ++i )
    {
        std::cout << "|";
        for ( decltype(n) j = 0; j < n; ++j )
        {
            std::cout << std::setw(3) << matrice[i][j];
        }
        std::cout << " |\n";
    }
    std::cout << std::flush;
}

void allocation_dynamique_avec_vector(int n)
{
    std::vector<int> indices(n);
    std::generate(indices.begin(), indices.end(), [n=0] () mutable { n += 1; return n; });

    std::vector<std::array<double,3>> coords(n);
    std::generate(coords.begin(), coords.end(), [n=-1] () mutable { n += 1; return std::array<double,3>{3.*n,2.*n,1.5*n}; });

    std::vector<std::vector<double>> matrice; matrice.reserve(n);
    for ( int i = 0; i < n; ++i ) matrice.emplace_back(n);

    for ( decltype(n) i = 0; i<n; ++i )
    {
        [[maybe_unused]] int j;
        std::generate(matrice[i].begin(), matrice[i].end(), [i,n,j=-1]() mutable { j = j+1; return (i+j)%n+1; } );
    }

    std::cout << "indices : ";
    for ( auto valeur : indices )
        std::cout << valeur << " ";
    std::cout << "\ncoordonnées : ";
    for ( const auto& coord : coords )
        std::cout << "(" << coord[0] << ", " << coord[1] << ", " << coord[2] << ") ";
    std::cout << "\nmatrice : " << std::endl;
    for ( decltype(n) i = 0; i < n; ++i )
    {
        std::cout << "|";
        for ( decltype(n) j = 0; j < n; ++j )
        {
            std::cout << std::setw(3) << matrice[i][j];
        }
        std::cout << " |\n";
    }
    std::cout << std::flush;
}

void stratégie_allocation_de_vector()
{
    std::vector<double> u(30);
    std::cout << "u => Capacité : " << u.capacity() << "\tTaille : " << u.size() << std::endl;
    u.resize(20);
    std::cout << "u => Capacité : " << u.capacity() << "\tTaille : " << u.size() << std::endl;
    u.resize(40);    
    std::cout << "u => Capacité : " << u.capacity() << "\tTaille : " << u.size() << std::endl;
    std::vector<double>(30).swap(u);
    std::cout << "u => Capacité : " << u.capacity() << "\tTaille : " << u.size() << std::endl;
    std::vector<double> v; v.reserve(100);
    std::cout << "v => Capacité : " << v.capacity() << "\tTaille : " << v.size() << std::endl;
    v.push_back(3.14); v.push_back(2.28); v.push_back(1.);
    std::cout << "v => Capacité : " << v.capacity() << "\tTaille : " << v.size() << std::endl;
    v.pop_back();
    std::cout << "v => Capacité : " << v.capacity() << "\tTaille : " << v.size() << std::endl;
    v.shrink_to_fit();
    std::cout << "v => Capacité : " << v.capacity() << "\tTaille : " << v.size() << std::endl;
}

void exemple_d_utilisation_de_vector()
{
    int N = 100;
    [[maybe_unused]] int i;
    std::vector<std::int32_t> carrés(N);
    std::generate(carrés.begin(), carrés.end(), [i = 0] () mutable { i += 1; return i*i; });
    std::vector<std::int32_t> non_pythagorycien; non_pythagorycien.reserve(100);
    for ( auto iter_valeurs = carrés.begin(); iter_valeurs != carrés.end(); ++iter_valeurs)
    {
        bool est_pythagorycien = false;
        for ( auto iter_2 = carrés.begin(); (iter_2 != iter_valeurs) && (est_pythagorycien==false); ++iter_2)
        {
            for ( auto iter_3 = carrés.begin(); (iter_3 != iter_2) && (est_pythagorycien==false); ++iter_3)
            {
                if ((*iter_2)+(*iter_3) == *iter_valeurs)
                    est_pythagorycien = true;
            }
        }
        if (not est_pythagorycien)
            non_pythagorycien.emplace_back(*iter_valeurs);
    }
    non_pythagorycien.shrink_to_fit();
    std::cout << "Nombre de carrés non pythagorycien : " << non_pythagorycien.size() << std::endl;
    for (auto val : non_pythagorycien)
        std::cout << val << " ";
    std::cout << std::endl;
}

int main()
{
    int n = 20;

    allocation_dynamique_avec_new_et_delete(n);
    allocation_dynamique_avec_shared_ptr(n);
    allocation_dynamique_avec_vector(n);

    stratégie_allocation_de_vector();
    exemple_d_utilisation_de_vector();

    return EXIT_SUCCESS;
}