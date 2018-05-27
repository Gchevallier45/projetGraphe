// main.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "CParseur.h"
#include "CGraphe.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc > 1) {
		for (unsigned int uiArg = 1; uiArg < (unsigned int)argc; uiArg++) {
			try {
				CParseur parser(argv[uiArg]);
				CGraphe& graphe = parser.PARGetGraphe();
				cout << "Affichage du graphe" << endl << graphe << endl;
				graphe.GRAInverserGraphe();
				cout << "Affichage du graphe inverse" << endl << graphe << endl << endl;
			}
			catch (CException &EXCParam) {
				cout << EXCParam;
			}
		}
	}
	else {
		cout << "Aucun fichier passe en parametre" << endl;
	}
    return 0;
}

