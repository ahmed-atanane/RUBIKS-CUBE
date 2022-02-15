#include "Actions.h"
#include "Cube.h"
#include <iostream>
using namespace std;


int main()
{
    Actions A;
    Cube C;

    A.TestRegressionActions(); //Appel des tests de régression de la classe Actions.
    C.TestRegressionCube(); //Appel des tests de régression de la classe Cube.
    
    return 0;
}