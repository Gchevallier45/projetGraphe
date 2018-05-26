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
	vector<CArc> vARCSOMArrivant;
	vector<CArc> vARCSOMPartant;
	CSommet(); //D�sactive le constructeur par d�faut et oblige l'utilisateur � construire un sommet avec un num�ro

public:
	CSommet(unsigned int uiNumeroParam);
	~CSommet();
	int SOMObtenirNumero();
	void SOMAjouterArrivant(CArc* pSOMArrivant);
	void SOMRetirerArrivant(CArc* pARCArrivant);
	void SOMRetirerToutArrivant(CSommet * pSOMPoint);
	void SOMAjouterPartant(CArc* pSOMPartant);
	void SOMRetirerPartant(CArc* pARCPartant);
	void SOMRetirerToutPartant(CSommet* pSOMPoint);
	const vector<CArc>& SOMObtenirArcsPartant();
	const vector<CArc>& SOMObtenirArcsArrivant();
	friend ostream& operator<<(ostream& os, CSommet &SOMParam);
};

