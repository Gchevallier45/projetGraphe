#include "stdafx.h"
#include "CGraphe.h"

/**
*/
void CGraphe::GRAAjouterPoint(unsigned int uiPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		if (vSOMGRAlist[uiBoucle].SOMObtenirNumero() == uiPoint) {
			cout << "Point déjà existant"<<endl;
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
 * @param SOMSommetDepart le sommet de départ de la liaison
 * @param SOMSommetArrivee le sommet d'arrivée de la liaison
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
 * @param SOMSommetDepart le sommet de départ de la liaison
 * @param SOMSommetArrivee le sommet d'arrivée de la liaison
 */
void CGraphe::GRARetirerLiaison(CSommet *SOMSommetDepart, CSommet *SOMSommetArrivee)
{
	SOMSommetDepart->SOMRetirerToutPartant(SOMSommetArrivee);
	SOMSommetArrivee->SOMRetirerToutArrivant(SOMSommetDepart);
}

/**
 * Retourne l'objet sommet correspondant au numéro du sommet passé en paramètre
 * @param uiNumeroSommet le numéro du sommet à chercher
 * @return un pointeur sur le sommet correspondant si celui-ci est trouvé dans le graphe, null sinon
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
 * Surcharge de l'opérateur << pour afficher un graphe à l'écran
 * @param os le flux dans lequel écrire les données du graphe
 * @param GRAParam le graphe à afficher
 * @return le flux passé en paramètre
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
