#include <iostream>
#include <string>
#include <utility>

class A
{
public:
    A( const std::string& phrase, int nombre )
        : _phrase(phrase), _nombre(nombre)
    {}
    A( const A& ) = default;
    A( A&& ) = default;
    ~A() = default;

    std::ostream& serialize( std::ostream& out ) const
    {
        out << "<A> " << this->_phrase << " " << this->_nombre;
        return out;
    }
private:
    std::string _phrase;
    int _nombre;
};

class B
{
public:
    B() = default;

};

template<class K> 
struct has_serialize 
{
    template<typename C> static constexpr 
    decltype(std::declval<C>().serialize(std::cout), bool()) test(int)
    {
        return true; 
    } // Le symbole , évalue une expression de gauche à droite, donc au final on retourne un bool
    
    template<typename C> static constexpr bool test(...) 
    {
        return false; 
    }
    
    // La valeur booléenne finale évaluée par le compilateur pour savoir si 
    // C contient une méthode serialize
    static constexpr bool value = test<K>(int());
};

template<typename T>
void display_serialization( const T& obj )
{
    if constexpr (has_serialize<T>::value)
    {
        obj.serialize(std::cout);
        std::cout << std::endl << std::flush;
    }
    else
    {
        std::cout << "No serialization..." << std::endl << std::flush;
    }
}

int main()
{
    display_serialization(A{"La réponse à l'univers est ", 40});
    display_serialization(B{});
    display_serialization(3);
    return EXIT_SUCCESS;
}