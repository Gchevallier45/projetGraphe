#include "stdafx.h"
#include "CSommet.h"

/**
 * Construit un sommet avec un numéro passé en paramètre
 * @param uiNumeroParam le numéro du sommet
 */
CSommet::CSommet(unsigned int uiNumeroParam)
{
	uiSOMNumero = uiNumeroParam;
}

/**
 * Retourne le numéro du sommet
 * @return le numéro du sommet
 */
int CSommet::SOMObtenirNumero() {
	return uiSOMNumero;
}

/**
 * Ajoute un arc vers le sommet de départ
 * @param SOMPoint le sommet de départ
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
 * Surcharge de l'opérateur << pour afficher un sommet à l'écran
 * @param os le flux dans lequel écrire les données du sommet
 * @param SOMParam le sommet à afficher
 * @return le flux passé en paramètre
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
 * Détruit un sommet ainsi que ses liaisons arrivantes et partantes
 */
void CSommet::SOMSupprimerLiaisons(){

	//retire les arcs présents dans les sommets liés au point qui se fait supprimer
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
