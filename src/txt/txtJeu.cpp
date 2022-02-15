#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "./winTxt.h"
#include "../core/Jeu.h"

void txtAff(WinTXT &win, const Jeu& jeu)
{
    const Cube &cube=jeu.getconstCube();

    win.clear();

    for(int i=0; i<cube.getdimX();i++)
    {
        for(int j=0; j<cube.getdimY();j++)
        {
            win.print(j,i,cube.getXY(i,j));
        }
    }

    win.draw();
}

void txtBoucle(Jeu &jeu)
{
    // Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getconstCube().getdimY(),jeu.getconstCube().getdimX());

    
    jeu.AffichageDepart();
    bool ok=true;
    int c;

    do
    {
        txtAff(win,jeu);
        #ifdef _WIN32
        Sleep(100);
        #else
        usleep(100000);
        #endif //WIN32

        c=win.getCh();

        switch(c)
        {
        case '0':
        jeu.Reinitialiser();
        break;

        case '1':
        jeu.MelangerCube();
        break;

        case 'q':
        ok=false;
        break;

        case 'R':
        jeu.ActionClavier('R');
        break;

        case 'L':
        jeu.ActionClavier('L');
        break;

        case 'U':
        jeu.ActionClavier('U');
        break;

        case 'D':
        jeu.ActionClavier('D');
        break;

        case 'F':
        jeu.ActionClavier('F');
        break;

        case 'B':
        jeu.ActionClavier('B');
        break;

        case 'X':
        jeu.ActionClavier('X');
        break;

        case 'Y':
        jeu.ActionClavier('Y');
        break;

        case 'Z':
        jeu.ActionClavier('Z');
        break;

        case 'r':
        jeu.ActionClavier('r');
        break;

        case 'l':
        jeu.ActionClavier('l');
        break;

        case 'u':
        jeu.ActionClavier('u');
        break;

        case 'd':
        jeu.ActionClavier('d');
        break;

        case 'f':
        jeu.ActionClavier('f');
        break;

        case 'b':
        jeu.ActionClavier('b');
        break;

        case 'x':
        jeu.ActionClavier('x');
        break;

        case 'y':
        jeu.ActionClavier('y');
        break;

        case 'z':
        jeu.ActionClavier('z');
        break;
        }
    }while(ok);
}
