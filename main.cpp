// main.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "CParseur.h"
#include "CGraphe.h"
#include <iostream>

using namespace std;

int main()
{
	CParseur mdr("C:/logs/graphe.txt");
	CGraphe graphe;
	graphe.GRAAjouterPoint(1);
	cout << graphe;
    return 0;
}

