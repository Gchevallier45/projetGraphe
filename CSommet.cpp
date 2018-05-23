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
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		if (pARCArrivant == &vARCSOMArrivant[i]) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + i);
		}
	}
	
}

void CSommet::SOMAjouterPartant(CSommet* pSOMArrivant)
{
	vARCSOMArrivant.push_back(CArc(pSOMArrivant));
}

void CSommet::SOMRetirerPartant(CArc* pARCArrivant)
{
	for (int i = 0; i < vARCSOMArrivant.size(); i++) {
		if (pARCArrivant == &vARCSOMArrivant[i]) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + i);
		}
	}
}

void CSommet::SOMRetirerSommet(){


}

void CSommet::SOMVisualiserSommet()
{
	cout << "Le point " << uiSOMNumero << "est relié ";
	for (int i = 0; i < vARCSOMArrivant.size()-1; i++) {
		cout << "au point " << vARCSOMArrivant[i].ARCObtenirSommet() << " " << endl;
	}
	
}
