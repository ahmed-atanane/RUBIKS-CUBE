#Rubik's Cube fait par Ahmed ATANANE en L2-INFORMATIQUE.
Le Rubik's Cube est un casse-tête très connu et un projet interessant pour le cours de LIFAP4 "Conception et Développement d'Applications".
Il s'agit d'un jeu programmé en C++ et utilisant la bibliothèque SDL2.

Le jeu se compile se Linux ainsi que sur Windows avec CodeBlocks.

#Pour compiler sur Linux:
- **Ouvrir un terminal**
- **Tapez make pour générer les fichier objets et les executables**


- **Tapez sur le terminal ./bin/rubikscube_txt en étant bien sur le répertoire racine pour executer le mode texte et ./bin/rubikscube_sdl pour executer le mode graphique**

- **Ou bien ouvrir CodeBlocks en ayant généré les executables au préalable avec make**
- **Pour compiler le mode texte, modifier Build Target afin qu'il soit sur Rubikscube_TXT**
- **Pour compiler le mode graphique, modifier Build Target afin qu'il soit sur Rubikscube_SDL**
- **Appuyer sur Run pour executer le jeu**

- **Pour générer la documentation, aller sur CodeBlocks et lancer Doxywizard dans l'onglet DoxyBlocks, puis sélectionner le repertoire doc et appuyez sur Run Doxygen afin de générer la documentation**
- **Une fois fini, tapez make clean dans le terminal pour supprimer les fichiers objets**

#Organisation des fichiers
- **src/core**   : les classes de base du Rubik's Cube. 
                        Ce code doit compiler sans dépendance à part les lib du système.
- **src/txt**   : les classes s'occupant de faire tourner un Rubik's Cube (core) et de l'afficher sur la console en texte, 
                       il y a une classe winTxt facilitant l'utilisation  une fenêtre texte et des évènements claviers.
- **src/SDL2**  : les classes s'occupant de faire tourner un Rubik's Cube (core) et de l'afficher avec SDL2

- **doc**       : le fichier doxygen qui permet de générer la documentation du code
- **data**      : les ressources (les images, sons et polices)
- **bin**       : contient les executables.
- **obj**       : contient l'ensemble des fichiers objets classés dans les répertoires obj/core, obj/SDL2 et obj/txt

#Comprendre le Jeu:
- **En mode texte**: la console de jeu affiche le patron de cube avec des caractères:
'#': aucune couleur
R: rouge
W: blanc
B: bleu
Y: jaune
G: vert
O: orange

- **Pour les mouvements horaires dans le mode texte** : 
- **Tapez R** (right ) pour tourner les petits cubes de droite au sens horaire.
- **Tapez L** (left) pour tourner les petits cubes de gauche au sens horaire.
- **Tapez U** (up) pour tourner les petits cubes du haut au sens horaire.
- **Tapez D** (down) pour tourner les petits cubes du bas au sens horaire.
- **Tapez F** (front) pour tourner les petits cubes de devant au sens horaire.
- **Tapez B** (behind) pour tourner les petits cubes de derrière au sens horaire.
- **Tapez X** pour tourner les petits cubes du milieu dans l'axe horizontal entre la face de haut et la face du bas au sens horaire.
- **Tapez Y** pour tourner les petits cubes du milieu dans l'axe vertical entre la face de droite et la face de gauche au sens horaire.
- **Tapez Z** pour tourner les petits cubes du milieu dans l'axe vertical entre la face de devant et la face de derrière au sens horaire.

- **Pour les mouvements anti-horaires dans le mode texte** : Tapez les touches précédentes en minuscules (r,l,u,d,f,b,x,y,z).

- **Pour mélanger** le cube, appuyer sur le bouton 1.
- **Pour le réinitialiser**, appuyer sur le bouton 0.
- **Pour quitter le jeu**, appuyer sur q.

- **En mode graphique avec SDL**: la console de jeu affiche le patron de cube avec des images, un cube en 3D fait en perspective avec des losanges et des carrés ainsi que deux boutons "Mélanger" et "Reset".

- **Pour mélanger** le cube, appuyer sur le bouton "MELANGER".
- **Pour le réinitialiser**, appuyer sur le bouton "RESET".
- **Pour quitter** le jeu, appuyer sur ESC ou bien sur la croix de la fenêtre.

- **Pour les mouvements horaires dans le mode SDL** : 
- **Tapez r** (right ) pour tourner les petits cubes de droite au sens horaire.
- **Tapez l** (left) pour tourner les petits cubes de gauche au sens horaire.
- **Tapez u** (up) pour tourner les petits cubes du haut au sens horaire.
- **Tapez d** (down) pour tourner les petits cubes du bas au sens horaire.
- **Tapez f** (front) pour tourner les petits cubes de devant au sens horaire.
- **Tapez b** (behind) pour tourner les petits cubes de derrière au sens horaire.
- **Tapez x** pour tourner les petits cubes du milieu dans l'axe horizontal entre la face de haut et la face du bas au sens horaire.
- **Tapez y** pour tourner les petits cubes du milieu dans l'axe vertical entre la face de droite et la face de gauche au sens horaire.
- **Tapez z** pour tourner les petits cubes du milieu dans l'axe vertical entre la face de devant et la face de derrière au sens horaire.

- **Pour les mouvements anti-horaires dans le mode SDL** : Effectuer les mouvements avec des chiffres.
- **1** :up
- **2** :down
- **3** :left
- **4** :right
- **5** :front
- **6** :behind
- **7** :x
- **8** :y
- **9** :z
