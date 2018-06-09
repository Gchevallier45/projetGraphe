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
void CSommet::SOMAjouterArcVers(CSommet& SOMPoint, unsigned int uiIdArc, unsigned int uiPoids)
{
	vARCSOMArcs.push_back(CArc(SOMPoint, uiIdArc, uiPoids));
}

/**
 * Retourne une liste ! en lecture seule ! des arcs partant du sommet
 * @param vARCSOMPartant la liste des arcs partant du sommet
 */
const vector<CArc>& CSommet::SOMObtenirArcs()
{
	return vARCSOMArcs;
}

/**
 * Surcharge de l'opérateur << pour afficher un sommet à l'écran
 * @param os le flux dans lequel écrire les données du sommet
 * @param SOMParam le sommet à afficher
 * @return le flux passé en paramètre
 */
ostream& operator<<(ostream& os, CSommet &SOMParam) {
	vector<CArc> vARCArcs = SOMParam.SOMObtenirArcs();

	os << "Point " << SOMParam.SOMObtenirNumero()<< endl;;

	unsigned int uiBoucle = 0;
	if (vARCArcs.size() > 0) {
		os << "Point(s) partant de " << SOMParam.SOMObtenirNumero() << " sont : " 
			<< vARCArcs[uiBoucle].ARCObtenirSommet().SOMObtenirNumero() << " (poids " << vARCArcs[uiBoucle].ARCObtenirPoids() << ")";
		while (uiBoucle < vARCArcs.size()-1) {
			uiBoucle++;
			os << ", " << vARCArcs[uiBoucle].ARCObtenirSommet().SOMObtenirNumero() << " (poids " << vARCArcs[uiBoucle].ARCObtenirPoids() << ")";
		}
		os << endl;
	}	

	return os;
}

/**
 * Méthode permettant de retirer un CArc de la liste des CArc arrivant du CSommet en cours
 * @param
 */
void CSommet::SOMRetirerArc(unsigned int idLiaison)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArcs.size(); uiBoucle++) {
		if (idLiaison == vARCSOMArcs[uiBoucle].ARCObtenirIdLiaison()) {
			vARCSOMArcs.erase(vARCSOMArcs.begin() + uiBoucle);
		}
	}
}


/**
 * Méthode permettant de vérifier qu'un CArc existe
 * @param idArc l'id de la liaison à vérifier
 * @return true si la liaison est dans la liste des CArc, false sinon
 */
bool CSommet::SOMArcExiste(unsigned int uiIdLiaison)
{
	for (CArc& ARCBoucle : vARCSOMArcs) {
		if (ARCBoucle.ARCObtenirIdLiaison() == uiIdLiaison) {
			return true;
		}
	}
	return false;
}

/**
* Retourne l'objet arc correspondant au numéro de liaison passé en paramètre
* @param uiIdLiaison l'id de la liaison à chercher
* @return un pointeur sur l'arc correspondant si celui-ci est trouvé dans le sommet, null sinon
*/
CArc* CSommet::SOMObtenirArc(unsigned int uiIdLiaison) {
	for (CArc &ARCBoucle : vARCSOMArcs) {
		if (ARCBoucle.ARCObtenirIdLiaison() == uiIdLiaison)
			return &ARCBoucle;
	}
	return NULL;
}

/**
 * Modifie le numéro du CSommet
 * @Param uiNumero Nouveau numéro du sommet
 */
void CSommet::SOMModifierNumero(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
}

/**
 * Retire les arcs présents dans les sommets reliés au sommet courant
 */
/*void CSommet::SOMSupprimerLiaisons(){
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		vARCSOMArrivant[uiBoucle].ARCObtenirSommet().SOMRetirerArrivant(*this);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		vARCSOMPartant[uiBoucle].ARCObtenirSommet().SOMRetirerPartant(*this);
	}
}*/
