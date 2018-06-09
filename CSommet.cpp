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
 * Surcharge de l'op�rateur << pour afficher un sommet � l'�cran
 * @param os le flux dans lequel �crire les donn�es du sommet
 * @param SOMParam le sommet � afficher
 * @return le flux pass� en param�tre
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
 * M�thode permettant de retirer un CArc de la liste des CArc arrivant du CSommet en cours
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
 * M�thode permettant de v�rifier qu'un CArc existe
 * @param idArc l'id de la liaison � v�rifier
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
* Retourne l'objet arc correspondant au num�ro de liaison pass� en param�tre
* @param uiIdLiaison l'id de la liaison � chercher
* @return un pointeur sur l'arc correspondant si celui-ci est trouv� dans le sommet, null sinon
*/
CArc* CSommet::SOMObtenirArc(unsigned int uiIdLiaison) {
	for (CArc &ARCBoucle : vARCSOMArcs) {
		if (ARCBoucle.ARCObtenirIdLiaison() == uiIdLiaison)
			return &ARCBoucle;
	}
	return NULL;
}

/**
 * Modifie le num�ro du CSommet
 * @Param uiNumero Nouveau num�ro du sommet
 */
void CSommet::SOMModifierNumero(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
}

/**
 * Retire les arcs pr�sents dans les sommets reli�s au sommet courant
 */
/*void CSommet::SOMSupprimerLiaisons(){
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		vARCSOMArrivant[uiBoucle].ARCObtenirSommet().SOMRetirerArrivant(*this);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < vARCSOMArrivant.size(); uiBoucle++) {
		vARCSOMPartant[uiBoucle].ARCObtenirSommet().SOMRetirerPartant(*this);
	}
}*/
