#include "stdafx.h"
#include "CGraphe.h"

/**
*/
void CGraphe::GRAAjouterPoint(unsigned int uiPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		if (vSOMGRAlist[uiBoucle].SOMObtenirNumero() == uiPoint) {
			cout << "Point d�j� existant"<<endl;
			return;
		}
	}
	vSOMGRAlist.push_back(CSommet(uiPoint));
}

/**
*/
void CGraphe::GRAModifierPoint()
{

}

/**
*/
void CGraphe::GRARetirerPoint(unsigned int uiPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		if (vSOMGRAlist[uiBoucle].SOMObtenirNumero() == uiPoint){ 
			vSOMGRAlist.erase(vSOMGRAlist.begin() + uiBoucle);//retire le point de la liste du graphe
			break;
		}
	}
}

/**
 * Ajoute une liaison entre deux sommets dans le graphe
 * @param SOMSommetDepart le sommet de d�part de la liaison
 * @param SOMSommetArrivee le sommet d'arriv�e de la liaison
 */
void CGraphe::GRAAjouterLiaison(CSommet *SOMSommetDepart, CSommet *SOMSommetArrivee)
{
	SOMSommetDepart->SOMAjouterPartant(&CArc(SOMSommetArrivee));
	SOMSommetArrivee->SOMAjouterArrivant(&CArc(SOMSommetArrivee));
}

/**
 */
void CGraphe::GRAModifierLiaison()
{

}

/**
 * Retire la liaison entre deux sommets dans le graphe 
 * @param SOMSommetDepart le sommet de d�part de la liaison
 * @param SOMSommetArrivee le sommet d'arriv�e de la liaison
 */
void CGraphe::GRARetirerLiaison(CSommet *SOMSommetDepart, CSommet *SOMSommetArrivee)
{
	SOMSommetDepart->SOMRetirerToutPartant(SOMSommetArrivee);
	SOMSommetArrivee->SOMRetirerToutArrivant(SOMSommetDepart);
}

/**
 * Retourne l'objet sommet correspondant au num�ro du sommet pass� en param�tre
 * @param uiNumeroSommet le num�ro du sommet � chercher
 * @return un pointeur sur le sommet correspondant si celui-ci est trouv� dans le graphe, null sinon
 */
CSommet* CGraphe::GRAObtenirSommet(unsigned int uiNumeroSommet) {
	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		if (vSOMGRAlist[uiNumeroSommet].SOMObtenirNumero() == uiNumeroSommet)
			return &vSOMGRAlist[uiNumeroSommet];
	}
	return NULL;
}

/**
 * Retourne une liste ! en lecture seule ! des sommets du graphe
 * @param vSOMGRAlist la liste des sommets du graphe
 */
const vector<CSommet>& CGraphe::GRAObtenirListeSommets()
{
	return vSOMGRAlist;
}

/**
 * Surcharge de l'op�rateur << pour afficher un graphe � l'�cran
 * @param os le flux dans lequel �crire les donn�es du graphe
 * @param GRAParam le graphe � afficher
 * @return le flux pass� en param�tre
 */
ostream& operator<<(ostream& os, CGraphe &GRAParam) {
//void CGraphe::GRAVisualiserGraphe()
	vector<CSommet> listeSommets = GRAParam.GRAObtenirListeSommets();
	os << "Vu du Graphe" << endl;

	for (unsigned int uiBoucle = 0; uiBoucle < listeSommets.size(); uiBoucle++) {
		os << listeSommets[uiBoucle] << endl;
	}
	return os;
}
