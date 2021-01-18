#include <iostream>

struct vecteur3d
{
    double x,y,z;
};

int main()
{
    // Faire des initialisation différentes de plusieurs vecteurs3d
    vecteur3d u;
    vecteur3d v{1.,2.,3.};
    vecteur3d w{.y=0.1,.z=1.2};

    // Afficher u, v et w :
    std::cout << "u : <" << u.x << ", " << u.y << ", " << u.z << ">" << std::endl
              << "v : <" << v.x << ", " << v.y << ", " << v.z << ">" << std::endl
              << "w : <" << w.x << ", " << w.y << ", " << w.z << ">" << std::endl;
    
    // A initialiser avec les vecteurs <1,0,0>, <0,1,0> et <0,0,1>
    vecteur3d base[3] = {
        {1.,0.,0.}, {0.,1.,0.},{0.,0.,1.}
    };

    // Afficher la base
    std::cout << "e1 : <" << base[0].x << ", " << base[0].y << ", " << base[0].z << ">" << std::endl
              << "e2 : <" << base[1].x << ", " << base[1].y << ", " << base[1].z << ">" << std::endl
              << "e3 : <" << base[2].x << ", " << base[2].y << ", " << base[2].z << ">" << std::endl; 

    return EXIT_SUCCESS;
}