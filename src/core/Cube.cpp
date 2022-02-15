#include "Cube.h"
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/*La représentation suivante est la vue 2D du patron du Rubik's Cube avec la vue 3D correspondante.

         #  #  #  #                                             #  #  # #
         #--------#                                          #--------# #
         #Face 5--#                                       #Face 5- #    #   
         #--------#                                    #-------#        #
#  #  #  #  #  #  #  #  #  #  #  #  #  #            #  #  #  # Face 6 #
#--------#--------#-----------#--------#            #--------#      # 
#Face 4--#Face 1--#Face 2-----#Face 3--#            #Face 1--#    #
#--------#--------#-----------#--------#            #--------#  #
#  #  #  #  #  #  #  #  #  #  #  #  #  #            #  #  #  #
         #--------#
         #Face 6--#
         #--------#
         #  #  #  #
*/

//Constructeur par défaut sans paramètres: patron de taille 9 x 12 divisé en 6 faces de couleurs différentes.
Cube::Cube()
{
    dimension_x=9;
    dimension_y=12;
    nb_couleurs=7;
}

//Constructeur de la classe avec paramètres
Cube::Cube(unsigned int dimx, unsigned int dimy, unsigned int colors)
{
    dimension_x=dimx;
    dimension_y=dimy;
    nb_couleurs=colors;
}

//Construction de copie.
Cube::Cube(const Cube& c)
{
    dimension_x=c.dimension_x;
    dimension_y=c.dimension_y;
    nb_couleurs=c.nb_couleurs;
}


//Dans la procédure suivante, on initialise le tableau de couleurs avec les valeurs de enum Couleur.
//Couleur est composé des caractères des 6 couleurs pour les 6 faces et d'une couleur supplémentaire: case vide.
void Cube::initCouleurs()
{
    couleurs[0]=Couleur::Blanc;
    couleurs[1]=Couleur::Bleu;
    couleurs[2]=Couleur::Jaune;
    couleurs[3]=Couleur::Vert;
    couleurs[4]=Couleur::Rouge;
    couleurs[5]=Couleur::Orange;
    couleurs[6]=Couleur::NoColor;
}


//Dans la procédure suivante, on initialise le patron de cube avec les valeurs du tableau de couleurs pour chaque face.
void Cube::initCube()
{
    //Pour toutes les faces du milieu du patron du cube (voir le dessin du haut pour repère).
    for(unsigned int i=(dimension_x/3); i<(dimension_x/3)+3; i++)
    {
        for(unsigned int j=(dimension_y/4); j<(dimension_y/2); j++)
        {
            cube[i][j]=couleurs[0]; //Face 1 de couleur blanche (au milieu).
        }
        for(unsigned int k=(dimension_y/2); k<(dimension_y/2)+3; k++)
        {
            cube[i][k]=couleurs[1]; //Face 2 de couleur bleue (au milieu, à droite).
        }
        for(unsigned int l=(dimension_y/2)+3; l<(dimension_y); l++)
        {
            cube[i][l]=couleurs[2]; //Face 3 de couleur jaune (au milieu, tout à droite)
        }
        for(unsigned int m=0; m<(dimension_y/4); m++)
        {
            cube[i][m]=couleurs[3]; //Face 4 de couleur verte (au milieu, à gauche)
        }
    }

    //Pour toutes les faces du haut du patron de cube.
    for(unsigned int i=0; i<(dimension_x/3);i++)
    {
        for(unsigned int j=(dimension_y/4); j<(dimension_y/2); j++)
        {
            cube[i][j]=couleurs[4]; //Face 5 de couleur rouge (en haut, au milieu).
        }
        for(unsigned k=0; k<(dimension_y/4); k++)
        {
            cube[i][k]=couleurs[6];  //Case vide sans couleur (en haut, à gauche).
        }
        for(unsigned l=(dimension_y/2); l<(dimension_y); l++)
        {
            cube[i][l]=couleurs[6];  //Case vide sans couleur (en haut, à droite).
        }
    }

    //Pour toutes les faces du bas du patron de cube.
    for(unsigned int i=(dimension_x/3)+3; i<(dimension_x); i++)
    {
        for(unsigned int j=(dimension_y/4); j<(dimension_y/2); j++)
        {
            cube[i][j]=couleurs[5];  //Face 6 de couleur orange (en bas, au milieu).
        }
        for(unsigned k=0; k<(dimension_y/4); k++)
        {
            cube[i][k]=couleurs[6]; //Case vide sans couleur (en bas, à gauche).
        }
        for(unsigned l=(dimension_y/2); l<(dimension_y); l++)
        {
            cube[i][l]=couleurs[6]; //Case vide sans couleur (en bas, à droite). 
        }
    }
}

//La fonction suivante retourne le caractère de la couleur se trouvant à la case (x,y) en respectant les assertions suivantes.
char Cube::getXY(const unsigned int x, const unsigned int y) const
{
    assert(x>=0);
	assert(y>=0);
	assert(x<=dimension_x-1);
	assert(y<=dimension_y-1);
	return cube[x][y];
}

//La procédure suivante modifie la couleur se trouvant à la case (x,y) en respectant les assertions suivantes.
void Cube::setXY(unsigned int x, unsigned int y, unsigned int c)
{
    assert(c>=0);
    assert(c<=6);
    assert(x>=0);
	assert(y>=0);
	assert(x<=dimension_x-1);
	assert(y<=dimension_y-1);
    cube[x][y] = couleurs[c];
}

//La fonction suivante retourne l'indice de la couleur se trouvant à la case (x,y) du tableau.
int Cube::getColorIndice(int x, int y) const
{
    if(cube[x][y]=='W') return 0;
    else if(cube[x][y]=='B') return 1;
    else if(cube[x][y]=='Y') return 2;
    else if(cube[x][y]=='G') return 3;
    else if(cube[x][y]=='R') return 4;
    else if(cube[x][y]=='O') return 5;
    else return 6;
}

//La fonction suivante retourne la largeur du patron de cube.
int Cube::getdimX() const
{
    return dimension_x;
}

//La fonction suivante retourne la hauteur du patron de cube.
int Cube::getdimY() const
{
    return dimension_y;
}

//La procédure suivante gère les tests de régression pour la classe Cube.
void Cube::TestRegressionCube()
{
    Cube c1;
    Cube c2(9,12,7);
    Cube c3(c1);

    //constructeur par défaut.
    assert(c1.dimension_x==9);
    assert(c1.dimension_y==12);
    assert(c1.nb_couleurs==7);

    //constructeur de la classe.
    assert(c1.dimension_x==9);
    assert(c1.dimension_y==12);
    assert(c1.nb_couleurs==7);

    //constructeur de copie.
    assert(c3.dimension_y=c1.dimension_x);
    assert(c3.dimension_y=c1.dimension_y);
    assert(c3.nb_couleurs=c1.nb_couleurs);

    //Initialisation des couleurs.
    c1.initCouleurs();
    c2.initCouleurs();
    c3.initCouleurs();

    //Initialisation des cubes.
    c1.initCube();
    c2.initCube();
    c3.initCube();

    //Retourner la valeur de l'objet à la case de coordonnées (x,y).
    assert(c1.getXY(0,3)=='R');
    assert(c2.getXY(3,3)=='W');
    assert(c3.getXY(3,6)=='B');

    //Modifier la couleur d'une case du cube.
    c1.setXY(3,3,1);
    c2.setXY(0,3,0);
    c3.setXY(6,5,4);

    //Retourner les largeurs des cubes.
    assert(c1.getdimX()==9);
    assert(c2.getdimX()==9);
    assert(c3.getdimX()==9);

    //Retourner les hauteurs des cubes.
    assert(c1.getdimY()==12);
    assert(c2.getdimY()==12);
    assert(c3.getdimY()==12);

    //Tests de vérification pour la fonction getColorIndice.
    assert(c1.getColorIndice(5,5));
    assert(c2.getColorIndice(3,4));
    assert(c3.getColorIndice(1,8));

}