#pragma once
#include "CArc.h"
#include <vector>
#include <iostream>

using namespace std;

// -------------------------------------------------------------------------------------------
// Classe CSommet
// Impl�mente la structure d'un objet sommet du graphe
// -------------------------------------------------------------------------------------------

class CSommet
{
private :
	unsigned int uiSOMNumero;
	vector<CArc> vARCSOMArcs;
	CSommet(); //D�sactive le constructeur par d�faut et oblige l'utilisateur � construire un sommet avec un num�ro

public:
	CSommet(unsigned int uiNumeroParam);
	int SOMObtenirNumero();
	void SOMAjouterArcVers(CSommet& SOMPoint, unsigned int idArc, unsigned int uiPoids);
	void SOMRetirerArc(unsigned int idArc);
	//void SOMSupprimerLiaisons();
	bool SOMArcExiste(unsigned int uiIdLiaison);
	void SOMModifierNumero(unsigned int uiNumero);
	CArc* SOMObtenirArc(unsigned int uiIdLiaison);
	vector<CArc>& SOMObtenirArcs();
	friend ostream& operator<<(ostream& os, CSommet &SOMParam);
};

