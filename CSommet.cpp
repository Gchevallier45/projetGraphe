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
//à voir si on garde pas que le retrait à partir de point parce que c'est plus simple que le retrait à partir d'arc on dirait
void CSommet::SOMRetirerToutArrivant(CSommet* pSOMPoint)
{
	for (int i = 0; i < vARCSOMArrivant.size(); i++) {
		if (pSOMPoint == vARCSOMArrivant[i].ARCObtenirSommet) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + i);
		}
	}

}

void CSommet::SOMAjouterPartant(CSommet* pARCPartant)
{
	pARCPartant->vARCSOMPartant.push_back(CArc(pARCPartant));
}


void CSommet::SOMRetirerPartant(CArc* pARCArrivant)
{
	for (int i = 0; i < vARCSOMPartant.size(); i++) {
		if (&vARCSOMPartant[i] == pARCArrivant) {
			vARCSOMPartant.erase(vARCSOMPartant.begin() + i);
		}
	}
}


void CSommet::SOMRetirerToutPartant(CSommet* pSOMPoint)
{
	for (int i = 0; i < vARCSOMPartant.size(); i++) {
		if (pSOMPoint == vARCSOMPartant[i].ARCObtenirSommet) {
			vARCSOMPartant.erase(vARCSOMPartant.begin() + i);
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

	//retire les arcs présents dans les sommets liés au point qui se fait supprimer
	for (unsigned int i = 0; i < vARCSOMArrivant.size(); i++) {
		vARCSOMArrivant[i].ARCObtenirSommet()->SOMRetirerToutArrivant(this);
	}
	for (unsigned int i = 0; i < vARCSOMArrivant.size(); i++) {
		vARCSOMPartant[i].ARCObtenirSommet()->SOMRetirerToutPartant(this);
	}

	//si besoin de supprimer les Arcs du sommet en court de suppression
	/*for (unsigned int i = vARCSOMArrivant.size(); i > 0 ; i--) {
		vARCSOMArrivant[i].erase;
	}
	for (unsigned int i = vARCSOMPartant.size(); i > 0 ; i--) {
		vARCSOMPartant[i].erase;
	}*/
}

void CSommet::SOMVisualiserSommet()
{
	cout << "Le point " << uiSOMNumero << "est relié ";
	for (int i = 0; i < vARCSOMArrivant.size()-1; i++) {
		cout << "au point " << vARCSOMArrivant[i].ARCObtenirSommet() << " " << endl;
	}
	
}
