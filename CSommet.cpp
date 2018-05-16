#include "stdafx.h"
#include "CSommet.h"
#include "iostream"


CSommet::CSommet()
{
}

CSommet::CSommet(unsigned int uiNumeroParam)
{
	uiSOMNumero = uiNumeroParam;
}


CSommet::~CSommet()
{

}

int CSommet::SOMObtenirNumero() {
	return uiSOMNumero;
}

void CSommet::SOMAjouterArrivant(CSommet* pSOMArrivant)
{
	vARCSOMArrivant.push_back(CArc(pSOMArrivant));
}

void CSommet::SOMRetirerArrivant(CArc* pARCArrivant)
{
	for (int i = 0; i < vARCSOMArrivant.size(); i++) {
		if (pARCArrivant == &vARCSOMArrivant[i]) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + i);
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

void CSommet::SOMRetirerSommet(){


}

void CSommet::SOMVisualiserSommet()
{
	cout << "Le point " << uiNumero << "est relié ";
	for (int i = 0; i < pARCArrivant.size()-1; i++) {
		cout << "au point " << pARCArrivant[i].ARCObtenirNumero() << " " << endl;
	}
	
}
