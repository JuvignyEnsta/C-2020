# SDL2-C++ : encapsulation C++ de la bibliothèque SDL 2

****

## Introduction

Simple Directmedia Layer (SDL) est une bibliothèque écrite en C qui permet un accès "bas niveau" au son, au clavier, à la souris, au joystick, et au hardware graphique via OpenGL et Direct3D. Cette bibliothèque est utilisée par les logiciels permettant de visualiser de la vidéo, les émulateurs, des jeux (en particuliers ceux publiés par Valve utilisent SDL...). 

SDL est supportée officiellement par Windows, Mac OS X, Linux, iOS et androïd. D'autres plateformes sont également plus ou moins supportées.

SDL est écrit en langage C, est supporté nativement par le C++ et il existe des api pour divers langages dont C# et Python.

La version 2.0 de cette librairie est sous license zlib, c'est à dire qu'on peut l'utiliser gratuitement dans n'importe quel logiciel.

Vous trouverez un wiki sur cette bibliothèque à : <https://github.com/libsdl-org/SDL/wiki>

La bibliothèque proposée ici se repose sur SDL 2.0 et profite de l'avantage offert par le C++ pour simplifier l'appel à SDL. De plus, il a été rajouté certaines fonctionnalités non présentes dans SDL 2 (dont le texte multi-ligne avec justification) pour faciliter la mise au point du projet.

Cette bibliothèque est amenée à évoluer, et si vous voulez proposer *une nouvelle fonctionnalité ou une amélioration de cette bibliothèque*, vous êtes les bienvenues !

## Présentation de SDL2-C++

### Initialisation et finalisation

Afin d'initialiser certains paramètres correctement ainsi que la bibliothèque SDL 2, il est nécessaire d'appeler une fonction d'initialisation. De même, afin de nettoyer correctement la mémoire prise par le programme, il est conseillé de finaliser la session graphique. Cela se fait à l'aide de deux fonctions qu'on trouve dans le header sdl2.hpp

    sdl2::init(argc, args) : permet d'initialiser le contexte SDL 2. Prends les argc et argv de la fonction main.
    sdl2::finalise()       : finalise la session en nettoyant proprement la mémoire

Attention, il faut s'assurer que tous les objets SDL 2 créés pendant la session graphique soient détruits avant l'appel de la fonction finalise, sous peine d'obtenir des erreurs mémoires. La solution la plus simple pour cela est d'initialiser sdl 2 et le finaliser dans la fonction main puis gérer les objets sdl 2 dans des fonctions, mais surtout pas dans la fonction main elle-même !

Ainsi, le fichier contenant la fonction main() ressemblera probablement aux lignes suivantes :

    # include "sdl2/sdl2.hpp"

    void début()
    {
        ...
    }

    int main(int argc, char* args[])
    {
        sdl2::init(argc, args);
        début();
        sdl2::finalize();
        return EXIT_SUCCESS;
    }

### Création d'une fenêtre graphique

Pour créer ensuite une fenêtre graphique, il suffit de la créer de la manière suivante :

    sdl2::window fenêtre(titre, dimension[, position, à afficher])

où les paramètres entre [ et  ] sont optionnels. Le titre est le texte qui sera affiché dans la barre de la fenêtre (et non dans la fenêtre). Quant à la dimension, c'est un tableau à deux valeurs entières donnant respectivement le nombre de pixel en largeur et en hauteur. Ainsi, on pourra créer une fenêtre contenant 800 × 600 pixels comme suit :

    window fenêtre("Ceci est le titre de ma fenêtre", {800,600});

Il est possible d'interroger une fenêtre pour connaître sa dimension :

    auto [w,h] = fenêtre.dimensions();

où w recevra le nombre de pixel en longueur et h le nombre de pixel en hauteur.

Enfin, on peut effacer tout le contenu d'une fenêtre avec la fonction cls (CLear Screen) qui par défaut rendra un fond blanc. On peut donner à la fonction cls une autre couleur de fond en lui précisant la couleur sous la forme de quatre entiers variant entre 0 et 255, donnant respectivement les composants rouge, vert, bleu et alpha (ce dernier servant à la transparence). Par exemple, pour effacer la fenêtre avec un fond noir :

    fenêtre.cls({0,0,0,255});

En ce qui concerne l'affichage des divers types d'objets sur la fenêtre, on gère tout cela au travers d'un flux d'entrée sur la fenêtre, un peut comme les std::ostream. Les objets peuvent être créés au vol ou bien à l'avance. Un exemple, dont les divers composants seront plus clairs est le suivant :

    fenêtre << sdl2::rectangle({10,10},{20,10}, {0xFF,0xF0,0,0xFF}, true)
            << sdl2::line({60,100}, {20,150}, {0,0,0xFF,0xFF}) << sdl2::flush;

#### Remarque 1 

Une fenêtre graphique ne possède pas un repère direct comme en mathématiques. En particuliers, le point (0,0) se trouve en haut à gauche de la fenêtre et l'axe des y est dirigé vers le bas (l'axe des x est dirigé vers la droite). L'origine de cette convention provient des écrans à tube cathodique dont le canon à électron balayait l'écran du haut vers le bas. 

#### Remarque 2

Lorsque vous commencerez à vouloir afficher des "choses" sur la fenêtre, vous serez peut-être surpris de constater que rien ne s'affiche. C'est que vous avez probablement oublié de mettre à jour la fenêtre grâce à sdl2::flush qui se gère sur le flot d'entrée de la fenêtre (voir l'exemple plus haut).

### Primitives graphiques

Quelques primitives graphiques sont proposées par SDL 2. On peut en particulier définir et afficher un segment de droite en lui donnant les deux points d'extrémités et la couleur du segment. Par exemple :

    sdl2::line segment({0,0},{255,255}, {0xFF,0,0,0xFF});

définit un segment de droite allant de la coordonnée (0,0) à la cordonnée (255,255) et dont la couleur est ici rouge.

Pour afficher le segment, il suffit de le mettre dans le flux d'entrée de la fenêtre de la manière suivante :

    fenêtre << segment;

On peut bien entendu afficher un segment créé au vol, au moment de l'affichage :

    fenêtre << sdl2::line({0,0},{255,255}, {0xFF,0,0,0xFF});

