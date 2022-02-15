/** @brief Module gérant les paramètres du jeu Rubik's Cube.
 *  @file Jeu.h
 *  @author AHMED ATANANE-L2 INFORMATIQUE
 */
#ifndef _JEU_H

/** @def Définition de la macro _JEU_H.
 */
#define _JEU_H

/** @brief Appel des fichiers d'en-tête Cube.h Actions.h contenant les classes Cube et Actions.
 */
#include "Cube.h"
#include "Actions.h"

class Cube;
class Actions;

/** @class La classe Jeu permettant de gérer les paramètres d'une partie de jeu.
 */
class Jeu
{
    private:
    /** @brief Un jeu Rubik's Cube c'est un cube ainsi que des actions (les mouvements possibles).
     */ 
    Cube cube;
    Actions action;

    public:
    /** @brief Constructeur par défaut.
     * @param : aucun paramètre.
     */ 
    Jeu();

    /** @fn Accesseur: Retourne un cube
     */
    Cube &getCube();

    /** @fn Accesseur: Retourne un cube non modifiable.
     */
    const Cube &getconstCube() const;

    /** @brief Procédure gérant l'affichage de départ.
     */
    void AffichageDepart();

    /** @brief Procédure gérant le mélange aléatoire du cube.
     */
    void MelangerCube();

    /** @brief Procédure gérant la réinitialisation du cube de départ.
     */
    void Reinitialiser();

    /** @brief Procédure gérant les différentes actions au clavier.
     * @param touche: un caractère constant.
     */
    void ActionClavier(const char touche);
};

/** @brief Fin de la directive de préprocesseur _JEU_H
 */
#endif
