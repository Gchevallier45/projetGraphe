// main.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "CParseur.h"
#include "CGraphe.h"
#include <iostream>

using namespace std;

int main()
{
	unsigned int uiChoix;
	unsigned int uiNumeroPoint;
	bool bSortie = false;
	CParseur mdr("C:/logs/graphe.txt");
	cout << mdr.PARGetGraphe();
	CGraphe carte = CGraphe();

	while (bSortie == false) {

		cout << endl << "Que faire ?" << endl << endl;
		cout << "1.Ajouter un point au graphe" << endl;
		cout << "2.Retirer un point au graphe" << endl;
		cout << "3.Visualiser le graphe" << endl;
		cout << "4.Sortir" << endl;

		cin >> uiChoix;
		
		switch (uiChoix) {
		case 1:
			cout << "Ajouter quel point ?" << endl;
			cin >> uiNumeroPoint;
			carte.GRAAjouterPoint(uiNumeroPoint);
			break;
		case 2:
			cout << "Retirer quel point ?" << endl;
			cin >> uiNumeroPoint;
			carte.GRARetirerPoint(uiNumeroPoint);
			break;
		case 3:
			cout << carte;
			break;
		case 4:
			bSortie = true;
		}

	}
    return 0;
}

