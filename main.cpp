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
				cout << "Affichage du graphe : " << graphe;
				/*CGraphe *graphe = new CGraphe();
				graphe->GRAAjouterPoint(1);
				graphe->GRAAjouterPoint(2);
				graphe->GRAAjouterPoint(3);
				graphe->GRAAjouterLiaison(1, 2, 10);
				CGraphe graphe2 = CGraphe(*graphe);
				graphe->GRARetirerPoint(2);
				//delete graphe;
				cout << "Affichage du graphe" << endl << *graphe << endl << graphe2 << endl;*/
				CGraphe *grapheBoruvka = graphe.GRABoruvka();
				cout << "Affichage du graphe inverse" << endl << *grapheBoruvka << endl << endl;
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