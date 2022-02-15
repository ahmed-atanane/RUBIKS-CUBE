#include "Actions.h"
#include <cassert>
#include <iostream>
using namespace std;

//La procédure suivante permet de faire tourner la face avant de 90º au sens horaire.
void Actions::MouvementFace1_Horaire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de devant avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,3); //stocker les indices de couleurs des carrés de gauche.
        couleurs[1][i]=c.getColorIndice(3,i+3); //stocker les indices de couleurs des carrés du haut.
        couleurs[2][i]=c.getColorIndice(i+3,5);  //stocker les indices de couleurs des carrés de droite.
        couleurs[3][i]=c.getColorIndice(5,i+3); //stocker les indices de couleurs des carrés du bas.
    }

    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+3,couleurs[0][2-i]); //les carrés du haut prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,5,couleurs[1][i]); //les carrés de droite prennent la valeur des carrés du haut.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+3,couleurs[2][2-i]); //les carrés du bas prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+3,3,couleurs[3][i]); //les carrés du gauche prennent la valeur des carrés du bas.
    }
}

//La procédure suivante permet de faire tourner la face avant de 90º au sens anti-horaire.
void Actions::MouvementFace1_AntiHoraire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de devant avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,5);  //stocker les indices de couleurs des carrés de droite.
        couleurs[1][i]=c.getColorIndice(5,i+3);  //stocker les indices de couleurs des carrés du bas.
        couleurs[2][i]=c.getColorIndice(i+3,3);  //stocker les indices de couleurs des carrés de gauche.
        couleurs[3][i]=c.getColorIndice(3,i+3);  //stocker les indices de couleurs des carrés du haut.
    }
    
    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+3,couleurs[0][i]); //les carrés du haut prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,5,couleurs[1][2-i]); //les carrés de droite prennent la valeur des carrés du bas.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+3,couleurs[2][i]); //les carrés du bas prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+3,3,couleurs[3][2-i]); //les carrés de gauche prennent la valeur des carrés du haut.
    }
}

//La procédure suivante permet de faire tourner la face de droite de 90º au sens horaire.
void Actions::MouvementFace2_Horaire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de droite avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,6); //stocker les indices de couleurs des carrés de gauche.
        couleurs[1][i]=c.getColorIndice(3,i+6); //stocker les indices de couleurs des carrés du haut.
        couleurs[2][i]=c.getColorIndice(i+3,8);  //stocker les indices de couleurs des carrés de droite
        couleurs[3][i]=c.getColorIndice(5,i+6); //stocker les indices de couleurs des carrés du bas.
    }

    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+6,couleurs[0][2-i]); //les carrés du haut prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,8,couleurs[1][i]); //les carrés de droite prennent la valeur des carrés du haut.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+6,couleurs[2][2-i]); //les carrés du bas prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+3,6,couleurs[3][i]); //les carrés du gauche prennent la valeur des carrés du bas.
    }
}

//La procédure suivante permet de faire tourner la face de droite de 90º au sens anti-horaire.
void Actions::MouvementFace2_AntiHoraire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de droite avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,8);  //stocker les indices de couleurs des carrés de droite.
        couleurs[1][i]=c.getColorIndice(5,i+6); //stocker les indices de couleurs des carrés du bas.
        couleurs[2][i]=c.getColorIndice(i+3,6); //stocker les indices de couleurs des carrés de gauche.
        couleurs[3][i]=c.getColorIndice(3,i+6); //stocker les indices de couleurs des carrés du haut.
    }
    
    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+6,couleurs[0][i]); //les carrés du haut prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,8,couleurs[1][2-i]); //les carrés de droite prennent la valeur des carrés du bas.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+6,couleurs[2][i]); //les carrés du bas prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+3,6,couleurs[3][2-i]); //les carrés de gauche prennent la valeur des carrés du haut.
    }
}

//La procédure suivante permet de faire tourner la face de derrière de 90º au sens horaire.
void Actions::MouvementFace3_Horaire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de derrière avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,9); //stocker les indices de couleurs des carrés de gauche.
        couleurs[1][i]=c.getColorIndice(3,i+9); //stocker les indices de couleurs des carrés du haut.
        couleurs[2][i]=c.getColorIndice(i+3,11);  //stocker les indices de couleurs des carrés de droite
        couleurs[3][i]=c.getColorIndice(5,i+9); //stocker les indices de couleurs des carrés du bas.
    }

    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+9,couleurs[0][2-i]); //les carrés du haut prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,11,couleurs[1][i]); //les carrés de droite prennent la valeur des carrés du haut.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+9,couleurs[2][2-i]); //les carrés du bas prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+3,9,couleurs[3][i]); //les carrés du gauche prennent la valeur des carrés du bas.
    }
}

//La procédure suivante permet de faire tourner la face de derrière de 90º au sens anti-horaire.
void Actions::MouvementFace3_AntiHoraire(Cube& c)
{
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,11);  //stocker les indices de couleurs des carrés de droite.
        couleurs[1][i]=c.getColorIndice(5,i+9); //stocker les indices de couleurs des carrés du bas.
        couleurs[2][i]=c.getColorIndice(i+3,9); //stocker les indices de couleurs des carrés de gauche.
        couleurs[3][i]=c.getColorIndice(3,i+9); //stocker les indices de couleurs des carrés du haut.
    }
    
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+9,couleurs[0][i]); //les carrés du haut prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,11,couleurs[1][2-i]); //les carrés de droite prennent la valeur des carrés du bas.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+9,couleurs[2][i]); //les carrés du bas prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+3,9,couleurs[3][2-i]); //les carrés de gauche prennent la valeur des carrés du haut
    }
}

//La procédure suivante permet de faire tourner la face de gauche de 90º au sens horaire.
void Actions::MouvementFace4_Horaire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de gauche avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,0); //stocker les indices de couleurs des carrés de gauche.
        couleurs[1][i]=c.getColorIndice(3,i); //stocker les indices de couleurs des carrés du haut.
        couleurs[2][i]=c.getColorIndice(i+3,2);  //stocker les indices de couleurs des carrés de droit
        couleurs[3][i]=c.getColorIndice(5,i); //stocker les indices de couleurs des carrés du bas.
    }

    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i,couleurs[0][2-i]); //les carrés du haut prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,2,couleurs[1][i]); //les carrés de droite prennent la valeur des carrés du haut.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i,couleurs[2][2-i]); //les carrés du bas prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+3,0,couleurs[3][i]); //les carrés du gauche prennent la valeur des carrés du bas.
    }
}

//La procédure suivante permet de faire tourner la face de gauche de 90º au sens anti-horaire.
void Actions::MouvementFace4_AntiHoraire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de gauche avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,2);  //stocker les indices de couleurs des carrés de droite.
        couleurs[1][i]=c.getColorIndice(5,i); //stocker les indices de couleurs des carrés du bas.
        couleurs[2][i]=c.getColorIndice(i+3,0); //stocker les indices de couleurs des carrés de gauche.
        couleurs[3][i]=c.getColorIndice(3,i); //stocker les indices de couleurs des carrés du haut.
    }
    
    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i,couleurs[0][i]); //les carrés du haut prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,2,couleurs[1][2-i]); //les carrés de droite prennent la valeur des carrés du bas.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i,couleurs[2][i]); //les carrés du bas prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+3,0,couleurs[3][2-i]); //les carrés de gauche prennent la valeur des carrés du haut
    }
}

//La procédure suivante permet de faire tourner la face de haut de 90º au sens horaire.
void Actions::MouvementFace5_Horaire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de haut avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i,3); //stocker les indices de couleurs des carrés de gauche.
        couleurs[1][i]=c.getColorIndice(0,i+3); //stocker les indices de couleurs des carrés du haut.
        couleurs[2][i]=c.getColorIndice(i,5);  //stocker les indices de couleurs des carrés de droite.
        couleurs[3][i]=c.getColorIndice(2,i+3); //stocker les indices de couleurs des carrés du bas.
    }

    for(int i=0; i<3; i++)
    {
        c.setXY(0,i+3,couleurs[0][2-i]); //les carrés du haut prennent la valeur des carrés de gauche.

    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i,5,couleurs[1][i]); //les carrés de droite prennent la valeur des carrés du haut.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(2,i+3,couleurs[2][2-i]);  //les carrés du bas prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i,3,couleurs[3][i]);  //les carrés du gauche prennent la valeur des carrés du bas.
    }
}

//La procédure suivante permet de faire tourner la face de haut de 90º au sens anti-horaire.
void Actions::MouvementFace5_AntiHoraire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face de haut avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i,5);  //stocker les indices de couleurs des carrés de droite.
        couleurs[1][i]=c.getColorIndice(2,i+3); //stocker les indices de couleurs des carrés du bas.
        couleurs[2][i]=c.getColorIndice(i,3); //stocker les indices de couleurs des carrés de gauche.
        couleurs[3][i]=c.getColorIndice(0,i+3); //stocker les indices de couleurs des carrés du haut.
    }
    
    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(0,i+3,couleurs[0][i]);  //les carrés du haut prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i,5,couleurs[1][2-i]);  //les carrés de droite prennent la valeur des carrés du bas.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(2,i+3,couleurs[2][i]);  //les carrés du bas prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i,3,couleurs[3][2-i]);  //les carrés de gauche prennent la valeur des carrés du haut
    }
}

//La procédure suivante permet de faire tourner la face du bas de 90º au sens horaire.
void Actions::MouvementFace6_Horaire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face du bas avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+6,3); //stocker les indices de couleurs des carrés de gauche.
        couleurs[1][i]=c.getColorIndice(6,i+3); //stocker les indices de couleurs des carrés du haut.
        couleurs[2][i]=c.getColorIndice(i+6,5);  //stocker les indices de couleurs des carrés de droite
        couleurs[3][i]=c.getColorIndice(8,i+3); //stocker les indices de couleurs des carrés du bas.
    }

    for(int i=0; i<3; i++)
    {
        c.setXY(6,i+3,couleurs[0][2-i]); //les carrés du haut prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+6,5,couleurs[1][i]); //les carrés de droite prennent la valeur des carrés du haut.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(8,i+3,couleurs[2][2-i]); //les carrés du bas prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+6,3,couleurs[3][i]); //les carrés du gauche prennent la valeur des carrés du bas.
    }
}

//La procédure suivante permet de faire tourner la face du bas de 90º au sens anti-horaire.
void Actions::MouvementFace6_AntiHoraire(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits carrés de la face du bas avant de modifier les couleurs.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+6,5);  //stocker les indices de couleurs des carrés de droite.
        couleurs[1][i]=c.getColorIndice(8,i+3); //stocker les indices de couleurs des carrés du bas.
        couleurs[2][i]=c.getColorIndice(i+6,3); //stocker les indices de couleurs des carrés de gauche.
        couleurs[3][i]=c.getColorIndice(6,i+3); //stocker les indices de couleurs des carrés du haut.
    }
    
    //Les boucles for suivantes permettent d'effectuer les changements de couleurs correspondants.
    for(int i=0; i<3; i++)
    {
        c.setXY(6,i+3,couleurs[0][i]);  //les carrés du haut prennent la valeur des carrés de droite.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+6,5,couleurs[1][2-i]);  //les carrés de droite prennent la valeur des carrés du bas.
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(8,i+3,couleurs[2][i]);  //les carrés du bas prennent la valeur des carrés de gauche.
    }
    for(int i=0; i<3;i++)
    {
        c.setXY(i+6,3,couleurs[3][2-i]);  //les carrés de gauche prennent la valeur des carrés du haut
    }
}

//La procédure suivante permet de tourner les petits cubes de droite au sens horaire.
void Actions::MouvementR(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de droite.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,5); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[1][i]=c.getColorIndice(i,5); //stocker les indices de couleurs des carrés de la face de haut.
        couleurs[2][i]=c.getColorIndice(i+3,11); //stocker les indices de couleurs des carrés de la face arrière.
        couleurs[3][i]=c.getColorIndice(i+6,5); //stocker les indices de couleurs des carrés de la face du bas.
    }

    //Les différentes modifications pour le mouvement R.
    for(int i=0; i<3; i++)
    {
        c.setXY(i,5,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,11,couleurs[1][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+6,5,couleurs[2][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,5,couleurs[3][i]);
    }

    Actions::MouvementFace2_Horaire(c); //Rotation de la face de droite au sens horaire.
}

//La procédure suivante permet de tourner les petits cubes de gauche au sens horaire.
void Actions::MouvementL(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de gauche.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,3); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[1][i]=c.getColorIndice(i,3); //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[2][i]=c.getColorIndice(i+3,9); //stocker les indices de couleurs des carrés de la face arrière.
        couleurs[3][i]=c.getColorIndice(i+6,3); //stocker les indices de couleurs des carrés de la face du bas.
    }

    //Les différentes modifications pour le mouvement L
    for(int i=0; i<3; i++)
    {
        c.setXY(i,3,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,9,couleurs[1][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+6,3,couleurs[2][2-i]); 
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,3,couleurs[3][i]);
    }

    Actions::MouvementFace4_Horaire(c);  //Rotation de la face de gauche au sens horaire.
}

//La procédure suivante permet de tourner les petits cubes du haut au sens horaire.
void Actions::MouvementU(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes du haut.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(3,i); //stocker les indices de couleurs des carrés de la face gauche.
        couleurs[1][i]=c.getColorIndice(3,i+3); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[2][i]=c.getColorIndice(3,i+6); //stocker les indices de couleurs des carrés de la face de droite.
        couleurs[3][i]=c.getColorIndice(3,i+9); //stocker les indices de couleurs des carrés de la face arrière.
    }

    //Les différentes modifications pour le mouvement U
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+3,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+6,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+9,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i,couleurs[3][i]);
    }
    Actions::MouvementFace5_Horaire(c); //Rotation de la face du haut au sens horaire.
}

//La procédure suivante permet de tourner les petits cubes du bas au sens horaire.
void Actions::MouvementD(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes du bas.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(5,i); //stocker les indices de couleurs des carrés de la face gauche.
        couleurs[1][i]=c.getColorIndice(5,i+3); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[2][i]=c.getColorIndice(5,i+6); //stocker les indices de couleurs des carrés de la face de droite.
        couleurs[3][i]=c.getColorIndice(5,i+9); //stocker les indices de couleurs des carrés de la face arrière.
    }

    //Les différentes modifications pour le mouvement D
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+3,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+6,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+9,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i,couleurs[3][i]);
    }
    Actions::MouvementFace6_Horaire(c); //Rotation de la face du bas au sens horaire.
}

//La procédure suivante permet de tourner les petits cubes de devant au sens horaire.
void Actions::MouvementF(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de devant.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(2,i+3); //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[1][i]=c.getColorIndice(i+3,6);  //stocker les indices de couleurs des carrés de la face droite.
        couleurs[2][i]=c.getColorIndice(6,i+3);  //stocker les indices de couleurs des carrés de la face du bas.
        couleurs[3][i]=c.getColorIndice(i+3,2);  //stocker les indices de couleurs des carrés de la face de gauche.
    }

    //Les différentes modifications pour le mouvement F
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,6,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(6,i+3,couleurs[1][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,2,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(2,i+3, couleurs[3][2-i]);
    }
    Actions::MouvementFace1_Horaire(c); //Rotation de la face avant au sens horaire.
}

//La procédure suivante permet de tourner les petits cubes de derrière au sens horaire.
void Actions::MouvementB(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de derrière.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(0,i+3); //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[1][i]=c.getColorIndice(i+3,8);  //stocker les indices de couleurs des carrés de la face de droite.
        couleurs[2][i]=c.getColorIndice(8,i+3);  //stocker les indices de couleurs des carrés de la face du bas.
        couleurs[3][i]=c.getColorIndice(i+3,0);  //stocker les indices de couleurs des carrés de la face de gauche.
    }

    //Les différentes modifications pour le mouvement B
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,8,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(8,i+3,couleurs[1][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,0,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(0,i+3, couleurs[3][2-i]);
    }
    Actions::MouvementFace3_Horaire(c); //Rotation de la face arrière au sens horaire.
}

//La procédure suivante permet de tourner les petits cubes du milieu entre la face du haut et la face du bas au sens horaire.
void Actions::MouvementX(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de milieu entre la face du haut et la face du bas.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(4,i); //stocker les indices de couleurs des carrés de la face de gauche.
        couleurs[1][i]=c.getColorIndice(4,i+3); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[2][i]=c.getColorIndice(4,i+6); //stocker les indices de couleurs des carrés de la face de droite.
        couleurs[3][i]=c.getColorIndice(4,i+9); //stocker les indices de couleurs des carrés de la face du arrière.
    }

    //Les différentes modifications pour le mouvement X
    for(int i=0; i<3; i++)
    {
        c.setXY(4,i+3,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(4,i+6,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(4,i+9,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(4,i,couleurs[3][i]);
    }
}

//La procédure suivante permet de tourner les petits cubes du milieu entre la face de droite et la face de gauche au sens horaire.
void Actions::MouvementY(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de milieu entre la face de droite et la face de gauche.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,4); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[1][i]=c.getColorIndice(i,4); //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[2][i]=c.getColorIndice(i+3,10); //stocker les indices de couleurs des carrés de la face arrière.
        couleurs[3][i]=c.getColorIndice(i+6,4); //stocker les indices de couleurs des carrés de la face du bas.
    }

    //Les différentes modifications pour le mouvement Y
    for(int i=0; i<3; i++)
    {
        c.setXY(i,4,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,10,couleurs[1][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+6,4,couleurs[2][2-i]); 
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,4,couleurs[3][i]);
    }
}

//La procédure suivante permet de tourner les petits cubes du milieu entre la face avant et la face arrière au sens horaire.
void Actions::MouvementZ(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de milieu entre la face avant et la face arrière.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(1,i+3); //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[1][i]=c.getColorIndice(i+3,7);  //stocker les indices de couleurs des carrés de la face de droite.
        couleurs[2][i]=c.getColorIndice(7,i+3);  //stocker les indices de couleurs des carrés de la face du bas.
        couleurs[3][i]=c.getColorIndice(i+3,1);  //stocker les indices de couleurs des carrés de la face de gauche.
    }

    //Les différentes modifications pour le mouvement Z
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,7,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(7,i+3,couleurs[1][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,1,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(1,i+3, couleurs[3][2-i]);
    }
}
//La procédure suivante permet de tourner les petits cubes de droite au sens anti-horaire.
void Actions::Mouvementr(Cube& c)
{    
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de droite.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,5); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[1][i]=c.getColorIndice(i,5); //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[2][i]=c.getColorIndice(i+3,11); //stocker les indices de couleurs des carrés de la face arrière.
        couleurs[3][i]=c.getColorIndice(i+6,5); //stocker les indices de couleurs des carrés de la face du bas.
    }

    //Les différentes modifications pour le mouvement r.
    for(int i=0; i<3; i++)
    {
        c.setXY(i+6,5,couleurs[0][i]); 
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,5,couleurs[1][i]); 
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i,5,couleurs[2][2-i]);  
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,11,couleurs[3][2-i]); 
    }

    Actions::MouvementFace2_AntiHoraire(c); //Rotation de la face de droite au sens anti-horaire.
}

//La procédure suivante permet de tourner les petits cubes de gauche au sens anti-horaire.
void Actions::Mouvementl(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de gauche.    
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,3); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[1][i]=c.getColorIndice(i,3); //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[2][i]=c.getColorIndice(i+3,9); //stocker les indices de couleurs des carrés de la face arrière.
        couleurs[3][i]=c.getColorIndice(i+6,3); //stocker les indices de couleurs des carrés de la face du bas.
    }

    //Les différentes modifications pour le mouvement l.
    for(int i=0; i<3; i++)
    {
        c.setXY(i+6,3,couleurs[0][i]); 
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,3,couleurs[1][i]); 
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i,3,couleurs[2][2-i]);  
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,9,couleurs[3][2-i]); 
    }
    Actions::MouvementFace4_AntiHoraire(c);  //Rotation de la face de gauche au sens anti-horaire.
}

//La procédure suivante permet de tourner les petits cubes du haut au sens anti-horaire.
void Actions::Mouvementu(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes du haut.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(3,i);   //stocker les indices de couleurs des carrés de la face de gauche.
        couleurs[1][i]=c.getColorIndice(3,i+3); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[2][i]=c.getColorIndice(3,i+6); //stocker les indices de couleurs des carrés de la face de droite.
        couleurs[3][i]=c.getColorIndice(3,i+9); //stocker les indices de couleurs des carrés de la face arrière.
    }
    
    //Les différentes modifications pour le mouvement u.
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+9,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+3,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(3,i+6,couleurs[3][i]);
    }
    Actions::MouvementFace5_AntiHoraire(c); //Rotation de la face du haut au sens anti-horaire.
}

//La procédure suivante permet de tourner les petits cubes du bas au sens anti-horaire.
void Actions::Mouvementd(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes du bas.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(5,i); //stocker les indices de couleurs des carrés de la face de gauche.
        couleurs[1][i]=c.getColorIndice(5,i+3); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[2][i]=c.getColorIndice(5,i+6); //stocker les indices de couleurs des carrés de la face de droite.
        couleurs[3][i]=c.getColorIndice(5,i+9); //stocker les indices de couleurs des carrés de la face arrière.
    }

    //Les différentes modifications pour le mouvement d.
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+9,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+3,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(5,i+6,couleurs[3][i]);
    }
    Actions::MouvementFace6_AntiHoraire(c); //Rotation de la face du bas au sens anti-horaire.
}

//La procédure suivante permet de tourner les petits cubes de devant au sens anti-horaire.
void Actions::Mouvementf(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de devant.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(2,i+3);  //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[1][i]=c.getColorIndice(i+3,2);  //stocker les indices de couleurs des carrés de la face de gauche.
        couleurs[2][i]=c.getColorIndice(6,i+3);  //stocker les indices de couleurs des carrés de la face du bas.
        couleurs[3][i]=c.getColorIndice(i+3,6);  //stocker les indices de couleurs des carrés de la face de droite.
    }

    //Les différentes modifications pour le mouvement f.
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,2,couleurs[0][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(6,i+3,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,6,couleurs[2][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(2,i+3, couleurs[3][i]);
    }

    Actions::MouvementFace1_AntiHoraire(c); //Rotation de la face avant au sens anti-horaire.
}

//La procédure suivante permet de tourner les petits cubes de derrière au sens anti-horaire.
void Actions::Mouvementb(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de derrière.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(0,i+3); //stocker les indices de couleurs des carrés de la face du haut.
        couleurs[1][i]=c.getColorIndice(i+3,0);  //stocker les indices de couleurs des carrés de la face de gauche.
        couleurs[2][i]=c.getColorIndice(8,i+3);  //stocker les indices de couleurs des carrés de la face du bas.
        couleurs[3][i]=c.getColorIndice(i+3,8);  //stocker les indices de couleurs des carrés de la face de droite.
    }

    //Les différentes modifications pour le mouvement b.
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,0,couleurs[0][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(8,i+3,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,8,couleurs[2][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(0,i+3, couleurs[3][i]);
    }

    Actions::MouvementFace3_AntiHoraire(c); //Rotation de la face arrière au sens anti-horaire.
}

//La procédure suivante permet de tourner les petits cubes du milieu entre la face du haut et la face du bas au sens anti-horaire.
void Actions::Mouvementx(Cube& c)
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de milieu entre la face du haut et la face du bas.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(4,i); //stocker les indices de couleurs des carrés de la face de gauche.
        couleurs[1][i]=c.getColorIndice(4,i+3); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[2][i]=c.getColorIndice(4,i+6); //stocker les indices de couleurs des carrés de la face de droite.
        couleurs[3][i]=c.getColorIndice(4,i+9); //stocker les indices de couleurs des carrés de la face arrière.
    }

    //Les différentes modifications pour le mouvement x.
    for(int i=0; i<3; i++)
    {
        c.setXY(4,i+9,couleurs[0][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(4,i,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(4,i+3,couleurs[2][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(4,i+6,couleurs[3][i]);
    }
}

//La procédure suivante permet de tourner les petits cubes du milieu entre la face de droite et la face de gauche au sens anti-horaire.
void Actions::Mouvementy(Cube& c) //fonction juste juste
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de milieu entre la face de droite et la face de gauche.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(i+3,4); //stocker les indices de couleurs des carrés de la face avant.
        couleurs[1][i]=c.getColorIndice(i,4); //stocker les indices de couleurs des carrés de la face de haut.
        couleurs[2][i]=c.getColorIndice(i+3,10); //stocker les indices de couleurs des carrés de la face arrière.
        couleurs[3][i]=c.getColorIndice(i+6,4); //stocker les indices de couleurs des carrés de la face du bas.
    }

    //Les différentes modifications pour le mouvement y.
    for(int i=0; i<3; i++)
    {
        c.setXY(i+6,4,couleurs[0][i]); 
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,4,couleurs[1][i]); 
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i,4,couleurs[2][2-i]);  
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,10,couleurs[3][2-i]); 
    }
}

//La procédure suivante permet de tourner les petits cubes du milieu entre la face avant et la face arrière au sens anti-horaire.
void Actions::Mouvementz(Cube& c) //fonction juste juste
{
    //Définition d'un tableau 2D d'entiers dont le rôle est de stocker les indices des couleurs des petits cubes de milieu entre la face avant et la face arrière.
    int couleurs[4][3];
    for(int i=0; i<3; i++)
    {
        couleurs[0][i]=c.getColorIndice(1,i+3); //stocker les indices de couleurs des carrés de la face de haut.
        couleurs[1][i]=c.getColorIndice(i+3,1);  //stocker les indices de couleurs des carrés de la face de gauche.
        couleurs[2][i]=c.getColorIndice(7,i+3);  //stocker les indices de couleurs des carrés de la face du bas.
        couleurs[3][i]=c.getColorIndice(i+3,7);  //stocker les indices de couleurs des carrés de la face de droite.
    }

    //Les différentes modifications pour le mouvement z.
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,1,couleurs[0][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(7,i+3,couleurs[1][i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(i+3,7,couleurs[2][2-i]);
    }
    for(int i=0; i<3; i++)
    {
        c.setXY(1,i+3, couleurs[3][i]);
    }

}

//La procédure suivante gère les tests de régression pour la classe Actions.
void Actions::TestRegressionActions()
{
    Actions a;
    Cube c;

    //Les différentes rotations de faces au sens horaire.
    a.MouvementFace1_Horaire(c);
    a.MouvementFace2_Horaire(c);
    a.MouvementFace3_Horaire(c);
    a.MouvementFace4_Horaire(c);
    a.MouvementFace5_Horaire(c);
    a.MouvementFace6_Horaire(c);

    //Les différentes rotations de faces au sens anti-horaire.
    a.MouvementFace1_AntiHoraire(c);
    a.MouvementFace2_AntiHoraire(c);
    a.MouvementFace3_AntiHoraire(c);
    a.MouvementFace4_AntiHoraire(c);
    a.MouvementFace5_AntiHoraire(c);
    a.MouvementFace6_AntiHoraire(c);


    //Les différents mouvements du cube au sens horaire.
    a.MouvementR(c);
    a.MouvementL(c);
    a.MouvementU(c);
    a.MouvementD(c);
    a.MouvementF(c);
    a.MouvementB(c);
    a.MouvementX(c);
    a.MouvementY(c);
    a.MouvementZ(c);

    //Les différents mouvements du cube au sens anti-horaire.
    a.Mouvementr(c);
    a.Mouvementl(c);
    a.Mouvementu(c);
    a.Mouvementd(c);
    a.Mouvementf(c);
    a.Mouvementb(c);
    a.Mouvementx(c);
    a.Mouvementy(c);
    a.Mouvementz(c);
}