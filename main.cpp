#include "stdafx.h"
#include "CParseur.h"
#include "CGraphe.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "--- Graphe ---" << endl;
	if (argc > 1) {
		for (unsigned int uiArg = 1; uiArg < (unsigned int)argc; uiArg++) {
			try {
				CParseur parser(argv[uiArg]);
				CGraphe& graphe = parser.PARGetGraphe();
				cout << "Affichage du graphe : " << endl << graphe << endl;
				CGraphe *grapheBoruvka = graphe.GRABoruvka();
				cout << "Affichage de l'arbre de Boruvka" << endl << *grapheBoruvka << endl << endl;
				delete grapheBoruvka;
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