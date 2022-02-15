/** @brief Module gérant le mode gaphique du jeu Rubik's Cube.
 *  @file SDLJeu.h
 *  @author AHMED ATANANE-L2 INFORMATIQUE
 */
#ifndef _SDL_JEU_H

/** @def Définition de la macro _SDLJEU_H.
 */
#define _SDL_JEU_H

/** @brief Inclure les librairies SDL2 nécessaires
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../core/Jeu.h"

/** @class La classe Image permettant de gérer une image avec SDL2.
 */
class Image
{
    private:
    SDL_Surface *surface;
    SDL_Texture *texture;
    bool has_changed;

    public:
    Image();
    void loadFromFile(const char* filename, SDL_Renderer* renderer);
    void loadFromCurrentSurface(SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};

/** @class La classe SDLJeu permettant de gérer le jeu avec un affichage SDL.
 */
class SDLJeu
{
    private:
    Jeu jeu;

    SDL_Window* window;
    SDL_Renderer* renderer;

    TTF_Font* font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk* sound;
    bool withsound;

    /** @brief Les différentes images pour l'affichage du cube.
     */
    Image carre_rouge;
    Image carre_bleu;
    Image carre_vert;
    Image carre_blanc;
    Image carre_orange;
    Image carre_jaune;

    Image melanger;
    Image reset;

    Image losange_blanc;
    Image losange_rouge;
    Image losange_bleu;
    Image losange_orange;
    Image losange_jaune;
    Image losange_vert;

    Image losange_bas_blanc;
    Image losange_bas_rouge;
    Image losange_bas_bleu;
    Image losange_bas_orange;
    Image losange_bas_jaune;
    Image losange_bas_vert;

    public:
    SDLJeu();
    ~SDLJeu();
    void SDLBoucle();
    void DrawCube3D();
    void SDLAffichage();
};

/** @brief Fin de la directive de préprocesseur _SDLJEU_H
 */
#endif
