#include "stdafx.h"
#include "CGraphe.h"

/**
*/
void CGraphe::GRAAjouterPoint(unsigned int uiPoint)
{
	if (this->GRASommetExiste(this->GRAObtenirSommet(uiPoint))) {
		cout << "Le point " << uiPoint << " existe deja" << endl;
		return;
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
	if (this->GRASommetExiste(this->GRAObtenirSommet(uiPoint)) == false) {
		cout << "Le point " << uiPoint << " n'existe pas" << endl;
		return;
	}
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
	if (this->GRASommetExiste(SOMSommetDepart) == false) {
		cout << "Le point " << SOMSommetDepart->SOMObtenirNumero() << " n'existe pas" << endl;
		return;
	}
	if (this->GRASommetExiste(SOMSommetArrivee) == false) {
		cout << "Le point " << SOMSommetArrivee->SOMObtenirNumero() << " n'existe pas" << endl;
		return;
	}
	if (SOMSommetDepart->SOMArcExiste(SOMSommetArrivee)) {
		cout << "La liaison du point " << SOMSommetDepart->SOMObtenirNumero() << " vers le sommet "
			<< SOMSommetArrivee->SOMObtenirNumero() << " existe deja" << endl;
		return;
	}

	SOMSommetDepart->SOMAjouterPartant(&CArc(SOMSommetArrivee));
	SOMSommetArrivee->SOMAjouterArrivant(&CArc(SOMSommetDepart));
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
	if (this->GRASommetExiste(SOMSommetDepart) == false) {
		cout << "Le point " << SOMSommetDepart->SOMObtenirNumero() << " n'existe pas" << endl;
		return;
	}
	if (this->GRASommetExiste(SOMSommetArrivee) == false) {
		cout << "Le point " << SOMSommetArrivee->SOMObtenirNumero() << " n'existe pas" << endl;
		return;
	}
	if (SOMSommetDepart->SOMArcExiste(SOMSommetArrivee) == false) 
	{
		cout << "La liaison du point " << SOMSommetDepart->SOMObtenirNumero() << " vers le sommet "
			<< SOMSommetArrivee->SOMObtenirNumero() << "n'existe pas" << endl;
		return;
	}

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
		if (vSOMGRAlist[uiBoucle].SOMObtenirNumero() == uiNumeroSommet)
			return &vSOMGRAlist[uiBoucle];
	}
	return NULL;
}

void CGraphe::GRAInverserGraphe()
{
	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		vSOMGRAlist[uiBoucle].SOMInverserLiens();
	}
	
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

void CGraphe::GRAVisualiser() {
	
	//vector<CSommet> listeSommets = vSOMGRAlist.GRAObtenirListeSommets();

	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
			cout << vSOMGRAlist[uiBoucle];
	}


}


ostream& operator<<(ostream& os, CGraphe &GRAParam) {
//void CGraphe::GRAVisualiserGraphe()
	vector<CSommet> listeSommets = GRAParam.GRAObtenirListeSommets();
	os << "Vu du Graphe" << endl;

	for (unsigned int uiBoucle = 0; uiBoucle < listeSommets.size(); uiBoucle++) {
		os << listeSommets[uiBoucle];
	}
	return os;
}

bool CGraphe::GRASommetExiste(CSommet *SOMSommet) {

	bool bExiste = false;

	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		if (&vSOMGRAlist[uiBoucle] == SOMSommet) {
			bExiste = true;
		}
	}
	return bExiste;
}

