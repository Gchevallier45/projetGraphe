#ifndef CPARSEUR_H
#define CPARSEUR_H

#include <string>
#include <iostream>
#include <fstream>

#include "CException.h"
#include "CGraphe.h"

// -----------------------------------------------------------------------------------------------------
// Classe CParseur
// Cette classe permet de construire un objet CGraphe depuis un fichier contenant une matrice de double
// 
// Le fichier doit être de la forme suivante :
//
// NBSommets =
// NBArcs =
// Matrice = [
// <Numéro_sommet>
// ]
// Arcs = [
// <Sommet_départ_arc1> <Sommet_arrivée_arc1>
// ]
//
// -----------------------------------------------------------------------------------------------------

using namespace std;

class CParseur
{
	CGraphe GRAPARgraphe;
	ifstream ifPARFichier;
public:
	CParseur();
	CParseur(string sCheminFichier);
	CGraphe& PARGetGraphe();
};

#endif //CPARSEUR_H