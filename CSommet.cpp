#include "stdafx.h"
#include "CSommet.h"

/**
 * Construit un sommet avec un num�ro pass� en param�tre
 * @param uiNumeroParam le num�ro du sommet
 */
CSommet::CSommet(unsigned int uiNumeroParam)
{
	uiSOMNumero = uiNumeroParam;
}

/**
 * Retourne le num�ro du sommet
 * @return le num�ro du sommet
 */
int CSommet::SOMObtenirNumero() {
	return uiSOMNumero;
}

/**
 * Ajoute un arc arrivant sur le sommet
 * @param pSOMArrivant l'arc arrivant sur le sommet
 */
void CSommet::SOMAjouterArrivant(CArc* pSOMArrivant)
{
	vARCSOMArrivant.push_back(*pSOMArrivant);
}

/**
 * Ajoute un arc partant du sommet
 * @param pSOMArrivant l'arc partant du sommet
 */
void CSommet::SOMAjouterPartant(CArc* pARCPartant)
{
	vARCSOMPartant.push_back(*pARCPartant);
}

/**
 * Retourne une liste ! en lecture seule ! des arcs partant du sommet
 * @param vARCSOMPartant la liste des arcs partant du sommet
 */
const vector<CArc>& CSommet::SOMObtenirArcsPartant()
{
	return vARCSOMPartant;
}

/**
 * Retourne une liste ! en lecture seule ! des arcs arrivant sur le sommet
 * @param vARCSOMPartant la liste des arcs arrivant sur le sommet
 */
const vector<CArc>& CSommet::SOMObtenirArcsArrivant()
{
	return vARCSOMArrivant;
}

/**
 * Surcharge de l'op�rateur << pour afficher un sommet � l'�cran
 * @param os le flux dans lequel �crire les donn�es du sommet
 * @param SOMParam le sommet � afficher
 * @return le flux pass� en param�tre
 */
ostream& operator<<(ostream& os, CSommet &SOMParam) { //Ca permet d'utiliser direct cout<< pour afficher un sommet
	//void CSommet::SOMVisualiserSommet(){
	vector<CArc> vARCArrivant = SOMParam.SOMObtenirArcsArrivant();
	vector<CArc> vARCPartant = SOMParam.SOMObtenirArcsPartant();

	os << SOMParam.SOMObtenirNumero();

	unsigned int uiBoucle = 0;
	if (vARCArrivant.size() > 0) {
		os << "Point(s) venant vers " << SOMParam.SOMObtenirNumero() << " sont : "<< vARCArrivant[uiBoucle].ARCObtenirSommet() << endl;
		while (uiBoucle < vARCArrivant.size()) {
			uiBoucle++;
			os << ", " << vARCArrivant[uiBoucle].ARCObtenirSommet()->SOMObtenirNumero() << endl;
		}
	}
	
	uiBoucle = 0;
	if (vARCPartant.size() > 0) {
		os << "Point(s) partant de " << SOMParam.SOMObtenirNumero() << " sont : " << vARCPartant[uiBoucle].ARCObtenirSommet() << endl;
		while (uiBoucle < vARCPartant.size()) {
			uiBoucle++;
			os << ", " << vARCPartant[uiBoucle].ARCObtenirSommet()->SOMObtenirNumero() << endl;
		}
	}	

	return os;
}

/**
*/
void CSommet::SOMRetirerArrivant(CArc* pARCArrivant)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		if (pARCArrivant == &vARCSOMArrivant[uiBoucle]) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + uiBoucle);
		}
	}

}

/**
*/
//� voir si on garde pas que le retrait � partir de point parce que c'est plus simple que le retrait � partir d'arc on dirait
void CSommet::SOMRetirerToutArrivant(CSommet* pSOMPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		if (pSOMPoint == vARCSOMArrivant[uiBoucle].ARCObtenirSommet()) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + uiBoucle);
		}
	}
}

/**
*/
void CSommet::SOMRetirerPartant(CArc* pARCPartant)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMPartant.size(); uiBoucle++) {
		if (&vARCSOMPartant[uiBoucle] == pARCPartant) {
			vARCSOMPartant.erase(vARCSOMPartant.begin() + uiBoucle);
		}
	}
}

/**
*/
void CSommet::SOMRetirerToutPartant(CSommet* pSOMPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMPartant.size(); uiBoucle++) {
		if (pSOMPoint == vARCSOMPartant[uiBoucle].ARCObtenirSommet()) {
			vARCSOMPartant.erase(vARCSOMPartant.begin() + uiBoucle);
		}
	}
}

/**
 * D�truit un sommet ainsi que ses liaisons arrivantes et partantes
 */
CSommet::~CSommet() {
	//void CSommet::SOMRetirerSommet(){
	//Ca correspond pas mal a un destructeur la fonction du coup j'ai mis le code dans le destructeur

	//retire les arcs pr�sents dans les sommets li�s au point qui se fait supprimer
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
