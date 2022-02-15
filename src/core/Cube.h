/** @brief Module gérant le cube du jeu Rubik's Cube.
 *  @file Cube.h
 *  @author AHMED ATANANE-L2 INFORMATIQUE
 */
#ifndef _CUBE_H

/** @def Définition de la macro _CUBE_H.
 */
#define _CUBE_H

/** @brief Fichier d'en-tête composé de la classe Cube.
 * Notre Rubik's Cube sera un cube dont chaque face est divisée en neuf petits cubes.
 * Le patron de ce cube sera représenté par une matrice de caractères de taille dimension_x et dimension_y.
 */

/** @enum Énumération des 6 couleurs du Rubik's cube représentés par des caractères. 
 * la variable NoColor de Couleur donne les cases n'appartenant pas au patron du cube.
 */ 
enum Couleur: char{Blanc='W',Bleu='B',Jaune='Y',Vert='G',Rouge='R',Orange='O',NoColor='#'};

 /** @class La classe Cube permettant de gérer un patron du Rubik's Cube en deux dimensions.
 */
class Cube
{
    private:

    /** @brief Les dimensions du patron du Rubik's Cube dimension_x, dimension_y.
     * le nombre de couleurs pour chaque face du cube.
     */ 
    unsigned int dimension_x;
    unsigned int dimension_y;
    unsigned int nb_couleurs;

    /** @brief une matrice du patron de cube représenté par un tableau 2D de cases de caractères.
     * un tableau de couleurs.
     */ 
    char cube[100][100];
    char couleurs[20];
    
    public:

    /** @brief Constructeur par défaut.
     * @param : aucun paramètre.
     */ 
    Cube();

    /** @brief Constructeur de la classe.
     * @param dimx: largeur du cube.
     * @param dimy: hauteur du cube.
     * @param colors: nombre de couleurs.
     */ 
    Cube(unsigned int dimx, unsigned int dimy, unsigned int colors);
    
    /** @brief Constructeur de copie.
     * @param c: un cube.
     */ 
    Cube(const Cube& c);
    
    /** @brief Procédure pour l'initialisation des couleurs.
     */ 
    void initCouleurs();

    /** @brief Procédure pour l'initialisation du cube.
     */ 
    void initCube();

    /** @fn Accesseur: Renvoie la couleur se trouvant à la case (x,y).
     * @param x: ligne de la case de la couleur.
     * @param y: colonne de la case de la couleur.
     */
    char getXY(const unsigned int x, const unsigned int y) const;

    /** @brief Mutateur: Modifie la couleur à la case (x,y).
     * @param x: ligne de la case de la couleur.
     * @param y: colonne de la case de la couleur.
     * @param c: indice de la couleur correspondante à la case.
     */
    void setXY(unsigned int x, unsigned int y, unsigned int c);

    /** @fn Accessseur: Retourne la largeur du patron de cube.
     */ 
    int getdimX() const;

    /** @fn Accesseur: Retourne la hauteur du patron de cube.
     */ 
    int getdimY() const;

    /** @fn: Accesseur: Retourne l'indice de la couleur 
     * @param x: ligne de la case de couleur.
     * @param y: colonne de la case de couleur.
     */
    int getColorIndice(int x, int y) const;

    /** @brief Procédure gérant les tests de régression pour la classe Cube.
     */
    void TestRegressionCube();

};

/** @brief Fin de la directive de préprocesseur _CUBE_H
 */
#endif