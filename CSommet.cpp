#include "stdafx.h"
#include "CSommet.h"
#include "iostream"


CSommet::CSommet()
{
}

CSommet::CSommet(unsigned int uiNumeroParam)
{
	uiNumero = uiNumeroParam;
}


CSommet::~CSommet()
{

}

int CSommet::SOMObtenirNumero() {
	return uiNumero;
}

void CSommet::SOMAjouterArrivant(CSommet* SOMArrivant)
{
	pARCArrivant.push_back(CArc(SOMArrivant));
}

void CSommet::SOMRetirerArrivant(CArc* ARCArrivant)
{
	for (int i = 0; i < pARCArrivant.size(); i++) {
		if (ARCArrivant == &pARCArrivant[i]) {
			pARCArrivant.erase(pARCArrivant.begin() + i);
		}
	}
	
}

void CSommet::SOMAjouterPartant(CSommet* SOMArrivant)
{
	pARCPartant.push_back(CArc(SOMArrivant));
}

void CSommet::SOMRetirerPartant(CArc* ARCArrivant)
{
	for (int i = 0; i < pARCArrivant.size(); i++) {
		if (ARCArrivant == &pARCArrivant[i]) {
			pARCArrivant.erase(pARCArrivant.begin() + i);
		}
	}
}

void CSommet::SOMVisualiserSommet()
{
	cout << "Le point " << uiNumero << "est relié ";
	for (int i = 0; i < pARCArrivant.size()-1; i++) {
		cout << "au point " << pARCArrivant[i].ARCObtenirNumero() << " " << endl;
	}
	
}
