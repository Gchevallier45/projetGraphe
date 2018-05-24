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

void CSommet::SOMAjouterArrivant(CArc* pSOMArrivant)
{
	vARCSOMArrivant.push_back(*pSOMArrivant);
}

void CSommet::SOMRetirerArrivant(CArc* pARCArrivant)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		if (pARCArrivant == &vARCSOMArrivant[uiBoucle]) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + uiBoucle);
		}
	}
	
}
//à voir si on garde pas que le retrait à partir de point parce que c'est plus simple que le retrait à partir d'arc on dirait
void CSommet::SOMRetirerToutArrivant(CSommet* pSOMPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		if (pSOMPoint == vARCSOMArrivant[uiBoucle].ARCObtenirSommet()) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + uiBoucle);
		}
	}
}

void CSommet::SOMAjouterPartant(CArc* pARCPartant)
{
	vARCSOMPartant.push_back(*pARCPartant);
}


void CSommet::SOMRetirerPartant(CArc* pARCPartant)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMPartant.size(); uiBoucle++) {
		if (&vARCSOMPartant[uiBoucle] == pARCPartant) {
			vARCSOMPartant.erase(vARCSOMPartant.begin() + uiBoucle);
		}
	}
}


void CSommet::SOMRetirerToutPartant(CSommet* pSOMPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMPartant.size(); uiBoucle++) {
		if (pSOMPoint == vARCSOMPartant[uiBoucle].ARCObtenirSommet()) {
			vARCSOMPartant.erase(vARCSOMPartant.begin() + uiBoucle);
		}
	}
}

void CSommet::SOMRetirerSommet(){

	//retire les arcs présents dans les sommets liés au point qui se fait supprimer
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		vARCSOMArrivant[uiBoucle].ARCObtenirSommet()->SOMRetirerToutArrivant(this);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		vARCSOMPartant[uiBoucle].ARCObtenirSommet()->SOMRetirerToutPartant(this);
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
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size()-1; uiBoucle++) {
		cout << "au point " << vARCSOMArrivant[uiBoucle].ARCObtenirSommet() << " " << endl;
	}
	
}
