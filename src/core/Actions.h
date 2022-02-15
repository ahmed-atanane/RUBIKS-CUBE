/** @brief Module gérant les actions du joueur lors d'une partie de jeu Rubik's Cube.
 *  @file Actions.h
 *  @author AHMED ATANANE-L2 INFORMATIQUE
 */
#ifndef _ACTIONS_H

/** @def Définition de la macro _ACTIONS_H.
 */
#define _ACTIONS_H

#include "Cube.h"

/** @class: La classe Actions permettant de gérer tous les mouvements possibles pour un Rubik's Cube.
 */
class Actions
{
    public:

    /** @brief les procédures suivantes permettent de faire tourner une face entière de 90 degrés au sens horaire.
     * Ces procédures seront utiles pour les procédures de mouvements.
     * @param: un Cube c.
     */ 
    void MouvementFace1_Horaire(Cube& c); //rotation à 90º au sens horaire de la face avant.
    void MouvementFace2_Horaire(Cube& c); //rotation à 90º au sens horaire de la face de droite.
    void MouvementFace3_Horaire(Cube& c); //rotation à 90º au sens horaire de la face arrière.
    void MouvementFace4_Horaire(Cube& c); //rotation à 90º au sens horaire de la face de gauche.
    void MouvementFace5_Horaire(Cube& c);  //rotation à 90º au sens horaire de la face du haut.
    void MouvementFace6_Horaire(Cube& c);  //rotation à 90º au sens horaire de la face du bas.

    /** @brief les procédures suivantes permettent de faire tourner une face entière de 90 degrés au sens anti-horaire.
     *  Ces procédures seront utiles pour les procédures de mouvements.
     * @param: un Cube c.
     */ 
    void MouvementFace1_AntiHoraire(Cube& c); //rotation à 90º au sens anti-horaire de la face avant.
    void MouvementFace2_AntiHoraire(Cube& c); //rotation à 90º au sens anti-horaire de la face de droite.
    void MouvementFace3_AntiHoraire(Cube& c); //rotation à 90º au sens anti-horaire de la face arrière.
    void MouvementFace4_AntiHoraire(Cube& c); //rotation à 90º au sens anti-horaire de la face de gauche.
    void MouvementFace5_AntiHoraire(Cube& c); //rotation à 90º au sens anti-horaire de la face du haut.
    void MouvementFace6_AntiHoraire(Cube& c); //rotation à 90º au sens anti-horaire de la face du bas.
    
    /** @brief les procédures suivantes correspondent aux différents mouvements possibles pour le cube.
     */

    /** @brief Tourner les petits cubes de droite au sens horaire.
     * @param: un Cube c.
     */
    void MouvementR(Cube& c);

    /** @brief Tourner les petits cubes de gauche au sens horaire.
     * @param: un Cube c.
     */
    void MouvementL(Cube& c);

    /** @brief Tourner les petits cubes du haut au sens horaire.
     * @param: un Cube c.
     */
    void MouvementU(Cube& c);

    /** @brief Tourner les petits cubes du bas au sens horaire.
     * @param: un Cube c.
     */
    void MouvementD(Cube& c);

    /** @brief Tourner les petits cubes de devant au sens horaire.
     * @param: un Cube c.
     */
    void MouvementF(Cube& c);

    /** @brief Tourner les petits cubes de derrière au sens horaire.
     * @param: un Cube c.
     */
    void MouvementB(Cube& c);

    /** @brief Tourner les petits cubes du milieu dans l'axe horizontal (entre la face du haut et la face du bas) au sens horaire.
     * @param: un Cube c.
     */
    void MouvementX(Cube& c);

    /** @brief Tourner les petits cubes du milieu dans l'axe vertical (entre la face de droite et la face de gauche) au sens horaire.
     * @param: un Cube c.
     */
    void MouvementY(Cube& c);

    /** @brief Tourner les petits cubes du milieu dans l'axe vertical (entre la face de devant et la face de derrière) au sens horaire.
     * @param: un Cube c.
     */
    void MouvementZ(Cube& c);

    /** @brief Tourner les petits cubes de droite au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementr(Cube& c);

    /** @brief Tourner les petits cubes de gauche au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementl(Cube& c);

    /** @brief Tourner les petits cubes du haut au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementu(Cube& c);

    /** @brief Tourner les petits cubes du bas au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementd(Cube& c);

    /** @brief Tourner les petits cubes de devant au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementf(Cube& c);

    /** @brief Tourner les petits cubes de derrière au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementb(Cube& c);

    /** @brief Tourner les petits cubes du milieu dans l'axe horizontal (entre la face du haut et la face du bas) au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementx(Cube& c);

    /** @brief Tourner les petits cubes du milieu dans l'axe vertical (entre la face de droite et la face de gauche) au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementy(Cube& c);

    /** @brief Tourner les petits cubes du milieu dans l'axe vertical (entre la face de devant et la face de derrière) au sens anti-horaire.
     * @param: un Cube c.
     */
    void Mouvementz(Cube& c);

    /** @brief Procédure gérant les tests de régression pour la classe Actions.
     */
    void TestRegressionActions();
};

/** @brief Fin de la directive de préprocesseur _ACTIONS_H
 */
#endif
