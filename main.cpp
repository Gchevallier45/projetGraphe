// main.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "CParseur.h"
#include <iostream>

using namespace std;

int main()
{
	//CParseur mdr("C:/logs/graphe.txt");
	bool sortie = false;
	int choix;

	do {
		cout << "1.Ajouter point" << endl;
		cout << "2.Visualiser le graphe" << endl;
		cout << "3.Sortie" << endl;
		cin >> choix;
		switch (choix) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				sortie = true;
				break;
		}
	} while (sortie == false);

    return 0;
}

