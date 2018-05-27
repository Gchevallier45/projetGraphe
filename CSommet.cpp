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
 * Ajoute un arc vers le sommet de d�part
 * @param SOMPoint le sommet de d�part
 */
void CSommet::SOMAjouterArrivant(CSommet& SOMPoint)
{
	vARCSOMArrivant.push_back(CArc(SOMPoint));
}

/**
 * Ajoute un arc vers le sommet de destination
 * @param SOMPoint le sommet de destination
 */
void CSommet::SOMAjouterPartant(CSommet& SOMPoint)
{
	vARCSOMPartant.push_back(CArc(SOMPoint));
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
ostream& operator<<(ostream& os, CSommet &SOMParam) {
	vector<CArc> vARCArrivant = SOMParam.SOMObtenirArcsArrivant();
	vector<CArc> vARCPartant = SOMParam.SOMObtenirArcsPartant();

	os << "Point " << SOMParam.SOMObtenirNumero()<< endl;;

	unsigned int uiBoucle = 0;
	if (vARCArrivant.size() > 0) {
		os << "Point(s) venant vers " << SOMParam.SOMObtenirNumero() << " sont : "
			<< vARCArrivant[uiBoucle].ARCObtenirSommet().SOMObtenirNumero();
		while (uiBoucle < vARCArrivant.size()-1) {
			uiBoucle++;
			os << ", " << vARCArrivant[uiBoucle].ARCObtenirSommet().SOMObtenirNumero();

		}
		os << endl;
	}
	
	
	uiBoucle = 0;
	if (vARCPartant.size() > 0) {
		os << "Point(s) partant de " << SOMParam.SOMObtenirNumero() << " sont : " 
			<< vARCPartant[uiBoucle].ARCObtenirSommet().SOMObtenirNumero();
		while (uiBoucle < vARCPartant.size()-1) {
			uiBoucle++;
			os << ", " << vARCPartant[uiBoucle].ARCObtenirSommet().SOMObtenirNumero();
		}
		os << endl;
	}	

	return os;
}

/**
*/
void CSommet::SOMRetirerArrivant(const CSommet& SOMPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		if (&SOMPoint == &vARCSOMArrivant[uiBoucle].ARCObtenirSommet()) {
			vARCSOMArrivant.erase(vARCSOMArrivant.begin() + uiBoucle);
		}
	}
}

/**
*/
void CSommet::SOMRetirerPartant(const CSommet& SOMPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMPartant.size(); uiBoucle++) {
		if (&SOMPoint == &vARCSOMPartant[uiBoucle].ARCObtenirSommet()) {
			vARCSOMPartant.erase(vARCSOMPartant.begin() + uiBoucle);
		}
	}
}

bool CSommet::SOMArcExiste(const CSommet& SOMSommetArrivee)
{
	for (CArc& ARCBoucle : vARCSOMPartant) {
		if (&SOMSommetArrivee == &ARCBoucle.ARCObtenirSommet()) {
			return true;
		}
	}
	return false;
}

void CSommet::SOMInverserLiens()
{
	vector<CArc> vARCTampon = SOMObtenirArcsPartant();
	vARCSOMPartant = vARCSOMArrivant;
	vARCSOMArrivant = vARCTampon;
}

void CSommet::SOMModifierNumero(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
}

/**
 * D�truit un sommet ainsi que ses liaisons arrivantes et partantes
 */
void CSommet::SOMSupprimerLiaisons(){

	//retire les arcs pr�sents dans les sommets li�s au point qui se fait supprimer
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		vARCSOMArrivant[uiBoucle].ARCObtenirSommet().SOMRetirerArrivant(*this);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		vARCSOMPartant[uiBoucle].ARCObtenirSommet().SOMRetirerPartant(*this);
	}

	//si besoin de supprimer les Arcs du sommet en court de suppression
	/*for (unsigned int i = vARCSOMArrivant.size(); i > 0 ; i--) {
	vARCSOMArrivant[i].erase;
	}
	for (unsigned int i = vARCSOMPartant.size(); i > 0 ; i--) {
	vARCSOMPartant[i].erase;
	}*/
}
