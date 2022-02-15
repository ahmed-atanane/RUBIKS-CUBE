#include <cassert>
#include "SDLJeu.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

Image::Image()
{
    surface=NULL;
    texture=NULL;
    has_changed=false;
}

void Image::loadFromFile(const char* filename, SDL_Renderer* renderer)
{
    surface=IMG_Load(filename);
    if(surface==NULL)
    {
        string nfn=string("../")+filename;
        std::cout<<"Error: cannot load "<<filename<<". Trying"<<nfn<<std::endl;
        surface=IMG_Load(nfn.c_str());
        if(surface==NULL)
        {
            nfn=string("../")+nfn;
            surface=IMG_Load(nfn.c_str());
        }
    }
    if(surface==NULL)
    {
        std::cout<<"Error: cannot load "<<filename<<std::endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface* surfaceCorrectPixelFormat=SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface=surfaceCorrectPixelFormat;

    texture=SDL_CreateTextureFromSurface(renderer, surfaceCorrectPixelFormat);
    if(texture==NULL)
    {
        std::cout<<"Error: problem to create the texture of"<<filename<<std::endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface(SDL_Renderer* renderer)
{
    texture=SDL_CreateTextureFromSurface(renderer,surface);
    if(texture==NULL)
    {
        std::cout<<"Error: problem to create the texture from surface"<<std::endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw(SDL_Renderer* renderer, int x, int y, int w, int h)
{
    int ok;
    SDL_Rect r;
    r.x=x;
    r.y=y;
    r.w=(w<0)?surface->w:w;
    r.h=(h<0)?surface->h:h;

    if(has_changed)
    {
        ok=SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok==0);
        has_changed=false;
    }
    ok=SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok==0);
}

SDL_Texture* Image::getTexture() const
{
    return texture;
}

void Image::setSurface(SDL_Surface* surf)
{
    surface=surf;
}


SDLJeu::SDLJeu() : jeu()
{
    if (SDL_Init(SDL_INIT_VIDEO)<0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if(TTF_Init()!=0)
    {
        std::cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    int imFlags=IMG_INIT_PNG | IMG_INIT_JPG;
    if(!(IMG_Init(imFlags) & imFlags))
    {
        std::cout<< "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() <<std::endl;
        SDL_Quit();
        exit(1);
    }

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
    {
        std::cout<<"SDL_mixer could not initialize! SDL_mixer Error: "<<Mix_GetError()<<std::endl;
        std::cout<<"No sound!"<<std::endl;
        withsound=false;
    }
    else
    {
        withsound=true;
    }

    int dimensionx,dimensiony;
    dimensionx=600;
    dimensiony=600;

    window = SDL_CreateWindow("Rubik's Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimensionx, dimensiony, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() <<std::endl;
        SDL_Quit();
        exit(1);
    }
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    //IMAGES
    carre_blanc.loadFromFile("data/Images/carre_blanc.png",renderer);
    carre_rouge.loadFromFile("data/Images/carre_rouge.png",renderer);
    carre_vert.loadFromFile("data/Images/carre_vert.png",renderer);
    carre_bleu.loadFromFile("data/Images/carre_bleu.png",renderer);
    carre_jaune.loadFromFile("data/Images/carre_jaune.png",renderer);
    carre_orange.loadFromFile("data/Images/carre_orange.png",renderer);

    losange_blanc.loadFromFile("data/Images/losange_blanc.png", renderer);
    losange_rouge.loadFromFile("data/Images/losange_rouge.png", renderer);
    losange_vert.loadFromFile("data/Images/losange_vert.png", renderer);
    losange_orange.loadFromFile("data/Images/losange_orange.png", renderer);
    losange_jaune.loadFromFile("data/Images/losange_jaune.png", renderer);
    losange_bleu.loadFromFile("data/Images/losange_bleu.png", renderer);

    losange_bas_blanc.loadFromFile("data/Images/losange2_blanc.png", renderer);
    losange_bas_rouge.loadFromFile("data/Images/losange2_rouge.png", renderer);
    losange_bas_vert.loadFromFile("data/Images/losange2_vert.png", renderer);
    losange_bas_orange.loadFromFile("data/Images/losange2_orange.png", renderer);
    losange_bas_jaune.loadFromFile("data/Images/losange2_jaune.png", renderer);
    losange_bas_bleu.loadFromFile("data/Images/losange2_bleu.png", renderer);

    melanger.loadFromFile("data/Images/melanger_button.png",renderer);
    reset.loadFromFile("data/Images/reset_button.png",renderer);

    //FONTS
    font=TTF_OpenFont("data/Fonts/Game.ttf",65);
    if(font==NULL)
    {
        font=TTF_OpenFont("data/Fonts/Game.ttf",65);
    }
    if(font==NULL)
    {
        std::cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    font_color.r = 255;font_color.g = 110;font_color.b = 60;
    font_im.setSurface(TTF_RenderText_Solid(font,"Rubik's Cube",font_color));
    font_im.loadFromCurrentSurface(renderer);

    //SON
    if (withsound)
    {
        sound = Mix_LoadWAV("data/Son/pac_bonus.wav");
        if (sound == NULL)
        {
            sound = Mix_LoadWAV("data/Son/pac_bonus.wav");
        }
        if (sound == NULL)
        {
            std::cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() <<std::endl;
            SDL_Quit();
            exit(1);
        }
    }
}

SDLJeu::~SDLJeu()
{
    if (withsound)
    {
        Mix_Quit();
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//Dessin d'une représentation d'un cube en 3 dimensions grâce à des carrés et des losanges.
void SDLJeu::DrawCube3D()
{
    const Cube& cube=jeu.getconstCube();

    //Dessiner les carrés pour la face avant.
    for(int x=3; x<6; x++) //x correspond aux lignes du tableau 2D du cube ainsi que l'axe des ordonnées du cube dans l'affichage graphique.
    {
        for(int y=3; y<6; y++) //y correspond aux colonnes du tableau 2D du cube ainsi que l'axe des abscisses du cube dans l'affichage graphique.
        {
            if(cube.getXY(x,y)=='R')
            {
                carre_rouge.draw(renderer,y*30+320,x*30+150,30,30);
            }
            else if(cube.getXY(x,y)=='W')
            {
                carre_blanc.draw(renderer,y*30+320,x*30+150,30,30);
            }
            else if(cube.getXY(x,y)=='G')
            {
                carre_vert.draw(renderer,y*30+320,x*30+150,30,30);
            }
            else if(cube.getXY(x,y)=='Y')
            {
                carre_jaune.draw(renderer,y*30+320,x*30+150,30,30);
            }
            else if(cube.getXY(x,y)=='B')
            {
                carre_bleu.draw(renderer,y*30+320,x*30+150,30,30);
            }
            else if(cube.getXY(x,y)=='O')
            {
                carre_orange.draw(renderer,y*30+320,x*30+150,30,30);
            }
        }
    }

    //Dessiner les losanges pour la face du bas.
    for(int x=3; x<6; x++)
    {
        for(int y=6; y<9; y++)
        {
            if(cube.getXY(x,y)=='R')
            {
                losange_rouge.draw(renderer,y*15+355+y*6,x*15+20+y*18+x*18,60,60);
            }
            else if(cube.getXY(x,y)=='W')
            {
                losange_blanc.draw(renderer,y*15+355+y*6,x*15+20+y*18+x*18,60,60);
            }
            else if(cube.getXY(x,y)=='G')
            {
                losange_vert.draw(renderer,y*15+355+y*6,x*15+20+y*18+x*18,60,60);
            }
            else if(cube.getXY(x,y)=='Y')
            {
                losange_jaune.draw(renderer,y*15+355+y*6,x*15+20+y*18+x*18,60,60);
            }
            else if(cube.getXY(x,y)=='B')
            {
               losange_bleu.draw(renderer,y*15+355+y*6,x*15+20+y*18+x*18,60,60);
            }
            else if(cube.getXY(x,y)=='O')
            {
                losange_orange.draw(renderer,y*15+355+y*6,x*15+20+y*18+x*18,60,60);
            }
        }
    }

    //Dessiner les losanges pour la face de droite.
    for(int x=6; x<9; x++)
    {
        for(int y=3; y<6; y++)
        {
            if(cube.getXY(x,y)=='R')
            {
                losange_bas_rouge.draw(renderer,y*15+185+y*18+x*20,x*15+190+x*5,60,60);
            }
            else if(cube.getXY(x,y)=='W')
            {
                losange_bas_blanc.draw(renderer,y*15+185+y*18+x*20,x*15+190+x*5,60,60);
            }
            else if(cube.getXY(x,y)=='G')
            {
                losange_bas_vert.draw(renderer,y*15+185+y*18+x*20,x*15+190+x*5,60,60);
            }
            else if(cube.getXY(x,y)=='Y')
            {
                losange_bas_jaune.draw(renderer,y*15+185+y*18+x*20,x*15+190+x*5,60,60);
            }
            else if(cube.getXY(x,y)=='B')
            {
               losange_bas_bleu.draw(renderer,y*15+185+y*18+x*20,x*15+190+x*5,60,60);
            }
            else if(cube.getXY(x,y)=='O')
            {
                losange_bas_orange.draw(renderer,y*15+185+y*18+x*20,x*15+190+x*5,60,60);
            }
        }
    }
}

void SDLJeu::SDLAffichage()
{
    SDL_SetRenderDrawColor(renderer, 50, 10, 10, 255);
    SDL_RenderClear(renderer);

    int x,y;
    const Cube& cube=jeu.getconstCube();

    //Dessin du patron de cube.
    for(x=0;x<cube.getdimX(); x++) //x correspond aux lignes du tableau 2D du cube ainsi que l'axe des ordonnées du cube dans l'affichage graphique.
    {
        for(y=0;y<cube.getdimY(); y++) //y correspond aux colonnes du tableau 2D du cube ainsi que l'axe des abscisses du cube dans l'affichage graphique.
        {
            if(cube.getXY(x,y)=='R')
            {
                carre_rouge.draw(renderer,y*30+40,x*30+40,30,30);
            }
            else if(cube.getXY(x,y)=='W')
            {
                carre_blanc.draw(renderer,y*30+40,x*30+40,30,30);
            }
            else if(cube.getXY(x,y)=='G')
            {
                carre_vert.draw(renderer,y*30+40,x*30+40,30,30);
            }
            else if(cube.getXY(x,y)=='Y')
            {
                carre_jaune.draw(renderer,y*30+40,x*30+40,30,30);
            }
            else if(cube.getXY(x,y)=='B')
            {
                carre_bleu.draw(renderer,y*30+40,x*30+40,30,30);
            }
            else if(cube.getXY(x,y)=='O')
            {
                carre_orange.draw(renderer,y*30+40,x*30+40,30,30);
            }
        }
    }

    //Dessiner les boutons de jeu "Mélanger" et "Reset".
    melanger.draw(renderer,30,400,200,80);
    reset.draw(renderer,300,400,200,80);

    SDLJeu::DrawCube3D();

    SDL_Rect Titre;
    Titre.x=100;
    Titre.y=10;
    Titre.w=400;
    Titre.h=30;

    //Affichage du titre du jeu.
    SDL_RenderCopy(renderer, font_im.getTexture(),NULL,&Titre);
}

void SDLJeu::SDLBoucle()
{
    SDL_Event events;
    bool isOpen{true};
    withsound=false;
    jeu.AffichageDepart();
    while(isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch(events.type)
            {
                case SDL_QUIT:
                isOpen=false;
                break;

                case SDL_KEYDOWN:
                withsound=true;
                if(events.key.keysym.sym==SDLK_ESCAPE)
                {
                  SDL_Log("a quitté le programme");
                  isOpen=false;
                }
                if(events.key.keysym.sym==SDLK_u)
                {
                    SDL_Log("a effectué le Mouvement U");
                    jeu.ActionClavier('U');
                }
                if(events.key.keysym.sym==SDLK_d)
                {
                    SDL_Log("a effectué le Mouvement D");
                    jeu.ActionClavier('D');
                }
                if(events.key.keysym.sym==SDLK_l)
                {
                    SDL_Log("a effectué le Mouvement L");
                    jeu.ActionClavier('L');
                }
                if(events.key.keysym.sym==SDLK_r)
                {
                    SDL_Log("a effectué le Mouvement R");
                    jeu.ActionClavier('R');
                }
                if(events.key.keysym.sym==SDLK_f)
                {
                    SDL_Log("a effectué le Mouvement F");
                    jeu.ActionClavier('F');
                }
                if(events.key.keysym.sym==SDLK_b)
                {
                    SDL_Log("a effectué le Mouvement B");
                    jeu.ActionClavier('B');
                }
                if(events.key.keysym.sym==SDLK_x)
                {
                    SDL_Log("a effectué le Mouvement X");
                    jeu.ActionClavier('X');
                }
                if(events.key.keysym.sym==SDLK_y)
                {
                    SDL_Log("a effectué le Mouvement Y");
                    jeu.ActionClavier('Y');
                }
                if(events.key.keysym.sym==SDLK_z)
                {
                    SDL_Log("a effectué le Mouvement Z");
                    jeu.ActionClavier('Z');
                }
                if(events.key.keysym.sym==SDLK_1)
                {
                    SDL_Log("a effectué le Mouvement u");
                    jeu.ActionClavier('u');
                }
                if(events.key.keysym.sym==SDLK_2)
                {
                    SDL_Log("a effectué le Mouvement d");
                    jeu.ActionClavier('d');
                }
                if(events.key.keysym.sym==SDLK_3)
                {
                    SDL_Log("a effectué le Mouvement l");
                    jeu.ActionClavier('l');
                }
                if(events.key.keysym.sym==SDLK_4)
                {
                    SDL_Log("a effectué le Mouvement r");
                    jeu.ActionClavier('r');
                }
                if(events.key.keysym.sym==SDLK_5)
                {
                    SDL_Log("a effectué le Mouvement f");
                    jeu.ActionClavier('f');
                }
                if(events.key.keysym.sym==SDLK_6)
                {
                    SDL_Log("a effectué le Mouvement b");
                    jeu.ActionClavier('b');
                }
                if(events.key.keysym.sym==SDLK_7)
                {
                    SDL_Log("a effectué le Mouvement x");
                    jeu.ActionClavier('x');
                }
                if(events.key.keysym.sym==SDLK_8)
                {
                    SDL_Log("a effectué le Mouvement y");
                    jeu.ActionClavier('y');
                }
                if(events.key.keysym.sym==SDLK_9)
                {
                    SDL_Log("a effectué le Mouvement z");
                    jeu.ActionClavier('z');
                }
                break;

                case SDL_KEYUP:
                withsound=false;
                break;

                case SDL_MOUSEBUTTONDOWN:
                if(events.button.y>=400 && events.button.y<480 && events.button.x>=30 && events.button.x<230)
                {
                    SDL_Log("a mélangé le cube");
                    jeu.MelangerCube();
                    withsound=true;
                }
                else if(events.button.y>=400 && events.button.y<480 && events.button.x>=300 && events.button.x<500)
                {
                    SDL_Log("a réinitialisé le cube");
                    jeu.Reinitialiser();
                    withsound=true;
                }
                break;

                case SDL_MOUSEBUTTONUP:
                withsound=false;
                break;
            }
            if(withsound)
            {
                Mix_PlayChannel(-1,sound,0);
            }
        }
        SDLJeu::SDLAffichage();
        SDL_RenderPresent(renderer);
    }
}
