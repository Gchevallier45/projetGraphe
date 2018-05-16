#pragma once
#include "CArc.h"
#include <vector>


using namespace std;

class CSommet
{
private :
	unsigned int uiNumero;
	vector<CArc> pARCArrivant;
	vector<CArc> pARCPartant;

public:
	CSommet();
	CSommet(unsigned int uiNumeroParam);
	~CSommet();
	int SOMObtenirNumero();
	void SOMAjouterArrivant(CSommet* SOMArrivant);
	void SOMRetirerArrivant(CArc* ARCArrivant);
	void SOMAjouterPartant(CSommet* SOMArrivant);
	void SOMRetirerPartant(CArc* ARCArrivant);
	void SOMVisualiserSommet();
};

