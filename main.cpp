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
	unsigned int uiNumeroPoint, uiPointArrivee, uiModif;
	bool bSortie = false;
	//CParseur mdr("C:/logs/graphe.txt");
	try {
		CParseur mdr("C:/logs/graphe.txt");
		cout << mdr.PARGetGraphe();
		CParseur mdr2("C:/logs/graphe1.txt");
		cout << mdr2.PARGetGraphe();
	}
	catch (CException &EXCParam) {
		cout << EXCParam;
	}
	CGraphe carte = CGraphe();

	while (bSortie == false) {

		cout << endl << "Que faire ?" << endl << endl;
		cout << "1.Ajouter un point au graphe" << endl;
		cout << "2.Retirer un point au graphe" << endl;
		cout << "3.Visualiser le graphe" << endl;
		cout << "4.Lier 2 points" << endl;
		cout << "5.Retirer une liaison entre 2 points" << endl;
		cout << "6.Modifier le numero d'un point" << endl;
		cout << "7.Modifier le depart d'une liaison" << endl;
		cout << "8.Modifier la fin d'une liaison" << endl;
		cout << "9.Sortir" << endl;

		cin >> uiChoix;
		
		switch (uiChoix) {
		case 1:
			cout << "Ajouter quel point ? ";
			cin >> uiNumeroPoint;
			carte.GRAAjouterPoint(uiNumeroPoint);
			break;
		case 2:
			cout << "Retirer quel point ? ";
			cin >> uiNumeroPoint;
			carte.GRARetirerPoint(uiNumeroPoint);
			break;
		case 3:
			cout << carte;
			break;
		case 4:
			cout << "lier quel point ? ";
			cin >> uiNumeroPoint;
			cout << "le lier vers quel point ? ";
			cin >> uiPointArrivee;
			carte.GRAAjouterLiaison(*carte.GRAObtenirSommet(uiNumeroPoint), *carte.GRAObtenirSommet(uiPointArrivee));
			break;
		case 5 :
			cout << "liaison partant de quel point ? ";
			cin >> uiNumeroPoint;
			cout << "liaison allant vers quel point ? ";
			cin >> uiPointArrivee;
			carte.GRARetirerLiaison(*carte.GRAObtenirSommet(uiNumeroPoint), *carte.GRAObtenirSommet(uiPointArrivee));
			break;
		case 6:
			cout << "Quel point doit changer ? ";
			cin >> uiNumeroPoint;
			cout << "Le changer en quel numero ? ";
			cin >> uiPointArrivee;
			carte.GRAModifierPoint(uiNumeroPoint, uiPointArrivee);
			break;
		case 7:
			cout << "Quel point de depart ? ";
			cin >> uiNumeroPoint;
			cout << "Quel point d'arrivee ? ";
			cin >> uiPointArrivee;
			cout << "Quel nouveau point de depart ? ";
			cin >> uiModif;
			carte.GRAModifierDepartLiaison(uiNumeroPoint, uiPointArrivee, uiModif);
			break;
		case 8:
			cout << "Quel point de depart ? ";
			cin >> uiNumeroPoint;
			cout << "Quel point d'arrivee ? ";
			cin >> uiPointArrivee;
			cout << "Quel nouveau point d'arrivee ? ";
			cin >> uiModif;
			carte.GRAModifierFinLiaison(uiNumeroPoint, uiPointArrivee, uiModif);
			break;
		case 9:
			bSortie = true;
			break;
		}

	}
    return 0;
}

