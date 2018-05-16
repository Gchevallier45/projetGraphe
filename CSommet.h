#pragma once
#include "CArc.h"
#include <vector>


using namespace std;

class CSommet
{
private :
	unsigned int uiSOMNumero;
	vector<CArc> vARCSOMArrivant;
	vector<CArc> vARCSOMPartant;

public:
	CSommet();
	CSommet(unsigned int uiNumeroParam);
	~CSommet();
	int SOMObtenirNumero();
	void SOMAjouterArrivant(CSommet* pSOMArrivant);
	void SOMRetirerArrivant(CArc* pARCArrivant);
	void SOMAjouterPartant(CSommet* pSOMArrivant);
	void SOMRetirerPartant(CArc* pARCArrivant);
	void SOMVisualiserSommet();
};

