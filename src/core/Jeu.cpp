#include "Jeu.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Constructeur par défaut.
Jeu::Jeu() : cube()
{
    cube.initCube();
}

//La fonction suivante est un accesseur retournant un cube.
Cube& Jeu::getCube ()
{
    return cube;
}

//La fonction suivante est un accesseur retournant un cube.
const Cube& Jeu::getconstCube () const
{
    return cube;
}

//La procédure suivante gère l'affichage de départ.
void Jeu::AffichageDepart()
{
    cube.initCouleurs(); //Initialisation des couleurs.
    cube.initCube();  //Initialisation du cube.
}

//La procédure suivante gère le mélange aléatoire du cube.
void Jeu::MelangerCube()
{
    cube.initCouleurs(); //Initialisation des couleurs.

    int nb_mouvements=5; //Valeur maximal d'appel à un mouvement.

    srand((unsigned int)time(NULL));
    int valeurs[9]; //Ce tableau permet de récuperer le nombre d'appels pour un mouvement de cube donné.
    
    for(int i=0; i<9; i++)
    {
        valeurs[i]=rand()%(nb_mouvements+1); //Stocker dans la case du tableau un nombre aléatoire compris entre 0 et nb_mouvements.
    }

    //Appels des différents mouvements aléatoirement pour un mélange unique à chaque fois.
    for(int i=0; i<valeurs[0]; i++)
    {
        action.MouvementR(cube);
    }
    for(int i=0; i<valeurs[1]; i++)
    {
        action.MouvementL(cube);
    }
    for(int i=0; i<valeurs[2]; i++)
    {
        action.MouvementU(cube);
    }
    for(int i=0; i<valeurs[3]; i++)
    {
        action.MouvementD(cube);
    }
    for(int i=0; i<valeurs[4]; i++)
    {
        action.MouvementF(cube);
    }
    for(int i=0; i<valeurs[5]; i++)
    {
        action.MouvementB(cube);
    }
    for(int i=0; i<valeurs[6]; i++)
    {
        action.MouvementX(cube);
    }
    for(int i=0; i<valeurs[7]; i++)
    {
        action.MouvementY(cube);
    }
    for(int i=0; i<valeurs[8]; i++)
    {
        action.MouvementZ(cube);
    }
}

//La procédure suivante permet de gérer la réinitialisation du cube de départ.
void Jeu::Reinitialiser()
{
    Jeu::AffichageDepart(); //Appel de la procédure AffichageDepart();
}

//La procédure permet de gérer les différentes actions au clavier en fonction de la touche enfoncée.
void Jeu::ActionClavier(const char touche)
{
    switch(touche)
    {
        case 'R':
        action.MouvementR(cube);
        break;

        case 'L':
        action.MouvementL(cube);
        break;

        case 'U':
        action.MouvementU(cube);
        break;

        case 'D':
        action.MouvementD(cube);
        break;

        case 'F':
        action.MouvementF(cube);
        break;

        case 'B':
        action.MouvementB(cube);
        break;

        case 'X':
        action.MouvementX(cube);
        break;

        case 'Y':
        action.MouvementY(cube);
        break;

        case 'Z':
        action.MouvementZ(cube);
        break;

        case 'r':
        action.Mouvementr(cube);
        break;

        case 'l':
        action.Mouvementl(cube);
        break;

        case 'u':
        action.Mouvementu(cube);
        break;

        case 'd':
        action.Mouvementd(cube);
        break;

        case 'f':
        action.Mouvementf(cube);
        break;

        case 'b':
        action.Mouvementb(cube);
        break;

        case 'x':
        action.Mouvementx(cube);
        break;

        case 'y':
        action.Mouvementy(cube);
        break;

        case 'z':
        action.Mouvementz(cube);
        break;

    }
}