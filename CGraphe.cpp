#include "stdafx.h"
#include "CGraphe.h"

/**
* Méthode permettant d'ajouter un CSommet au CGraphe
* @Param uiPoint le numéro que prendra le CSommet
*/
void CGraphe::GRAAjouterPoint(unsigned int uiPoint)
{
	if (GRASommetExiste(uiPoint)) {
		cout << "Le point " << uiPoint << " existe deja" << endl;
		return;
	}
	vSOMGRAlist.push_back(CSommet(uiPoint));
}

/**
* Méthode permettant de modifier le numéro d'un CSommet
* @Param uiNumeroAvant le numéro du CSommet à changer
* @Param uiNumeroApres le numéro que prendra le CSommet
*/
void CGraphe::GRAModifierPoint(unsigned int uiNumeroAvant, unsigned int uiNumeroApres)
{
	if (GRASommetExiste(uiNumeroAvant) == false) {
		cout << "Le point " << uiNumeroAvant << " n'existe pas" << endl;
		return;
	}

	if (GRASommetExiste(uiNumeroApres)) {
		cout << "Le point " << uiNumeroApres << " existe deja" << endl;
		return;
	}

	for (CSommet &SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMObtenirNumero() == uiNumeroAvant) {
			SOMBoucle.SOMModifierNumero(uiNumeroApres);//retire le point de la liste du graphe
			break;
		}
	}
	
}

/**
* Méthode permettant de retirer un point du CGraphe
* @Param uiPoint le numéro du point à retirer
*/
void CGraphe::GRARetirerPoint(unsigned int uiPoint)
{
	if (GRASommetExiste(uiPoint) == false) {
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
 * @param uiSommetDepart le sommet de départ de la liaison
 * @param uiSommetArrivee le sommet d'arrivée de la liaison
 */
void CGraphe::GRAAjouterLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee)
{
	if (GRASommetExiste(uiSommetDepart) == false) {
		cout << "Le point " << uiSommetDepart << " n'existe pas" << endl;
		return;
	}
	if (GRASommetExiste(uiSommetArrivee) == false) {
		cout << "Le point " << uiSommetArrivee << " n'existe pas" << endl;
		return;
	}

	CSommet& SOMSommetDepart = *GRAObtenirSommet(uiSommetDepart);
	CSommet& SOMSommetArrivee = *GRAObtenirSommet(uiSommetArrivee);

	if (SOMSommetDepart.SOMArcExiste(SOMSommetArrivee)) {
		cout << "La liaison du point " << SOMSommetDepart.SOMObtenirNumero() << " vers le sommet "
			<< SOMSommetArrivee.SOMObtenirNumero() << " existe deja" << endl;
		return;
	}

	SOMSommetDepart.SOMAjouterPartant(SOMSommetArrivee);
	SOMSommetArrivee.SOMAjouterArrivant(SOMSommetDepart);
}


/**
* Méthode permettant la modification de la partie départ d'un lien. Il faut que tous les sommets passés en paramètre existe
* @Param uiSommetDepart le numéro du sommet de départ d'un liaison
* @Param uiSommetArrivee le numéro du sommet d'arrivée d'une liaison
* @Param uiNewSommetDepart le numéro du nouveau sommet de départ de la liaison des sommet précédents
*/
void CGraphe::GRAModifierDepartLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee, unsigned int uiNewSommetDepart)
{
	if (GRASommetExiste(uiSommetDepart) == false) {
		cout << "Le point " << uiSommetDepart << " n'existe pas" << endl;
		return;
	}
	if (GRASommetExiste(uiSommetArrivee) == false) {
		cout << "Le point " << uiSommetArrivee << " n'existe pas" << endl;
		return;
	}
	if (GRASommetExiste(uiNewSommetDepart) == false) {
		cout << "Le point " << uiNewSommetDepart << " n'existe pas" << endl;
		return;
	}


	GRARetirerLiaison(uiSommetDepart, uiSommetArrivee);
	GRAAjouterLiaison(uiNewSommetDepart, uiSommetArrivee);

}

/**
* Méthode permettant la modification de la partie arrivée d'un lien. Il faut que tous les sommets passés en paramètre existe
* @Param uiSommetDepart le numéro du sommet de départ d'un liaison
* @Param uiSommetArrivee le numéro du sommet d'arrivée d'une liaison
* @Param uiNewSommetArrivee le numéro du nouveau sommet de d'arrivée de la liaison des sommet précédents
*/
void CGraphe::GRAModifierFinLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee, unsigned int uiNewSommetArrivee)
{
	if (GRASommetExiste(uiSommetDepart) == false) {
		cout << "Le point " << uiSommetDepart << " n'existe pas" << endl;
		return;
	}
	if (GRASommetExiste(uiSommetArrivee) == false) {
		cout << "Le point " << uiSommetArrivee << " n'existe pas" << endl;
		return;
	}
	if (GRASommetExiste(uiNewSommetArrivee) == false) {
		cout << "Le point " << uiNewSommetArrivee << " n'existe pas" << endl;
		return;
	}

	GRARetirerLiaison(uiSommetDepart, uiSommetArrivee);
	GRAAjouterLiaison(uiSommetDepart, uiNewSommetArrivee);
}


/**
 * Retire la liaison entre deux sommets dans le graphe 
 * @param uiSommetDepart le sommet de départ de la liaison
 * @param uiSommetArrivee le sommet d'arrivée de la liaison
 */
void CGraphe::GRARetirerLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee)
{
	if (GRASommetExiste(uiSommetDepart) == false) {
		cout << "Le point " << uiSommetDepart << " n'existe pas" << endl;
		return;
	}
	if (GRASommetExiste(uiSommetArrivee) == false) {
		cout << "Le point " << uiSommetArrivee << " n'existe pas" << endl;
		return;
	}

	CSommet& SOMSommetDepart = *GRAObtenirSommet(uiSommetDepart);
	CSommet& SOMSommetArrivee = *GRAObtenirSommet(uiSommetArrivee);

	if (SOMSommetDepart.SOMArcExiste(SOMSommetArrivee) == false) 
	{
		cout << "La liaison du point " << SOMSommetDepart.SOMObtenirNumero() << " vers le sommet "
			<< SOMSommetArrivee.SOMObtenirNumero() << "n'existe pas" << endl;
		return;
	}

	SOMSommetDepart.SOMRetirerPartant(SOMSommetArrivee);
	SOMSommetArrivee.SOMRetirerArrivant(SOMSommetDepart);
}

/**
 * Retourne l'objet sommet correspondant au numéro du sommet passé en paramètre
 * @param uiNumeroSommet le numéro du sommet à chercher
 * @return un pointeur sur le sommet correspondant si celui-ci est trouvé dans le graphe, null sinon
 */
CSommet* CGraphe::GRAObtenirSommet(unsigned int uiNumeroSommet) {
	for (CSommet &SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMObtenirNumero() == uiNumeroSommet)
			return &SOMBoucle;
	}
	return NULL;
}

/**
* Méthode permettant d'inverser le sens des liaisons du graphe
*/
void CGraphe::GRAInverserGraphe()
{
	for (CSommet &SOMBoucle : vSOMGRAlist) {
		SOMBoucle.SOMInverserLiens();
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
ostream& operator<<(ostream& os, CGraphe &GRAParam) {
	vector<CSommet> listeSommets = GRAParam.GRAObtenirListeSommets();

	for (CSommet &SOMBoucle : listeSommets) {
		os << SOMBoucle;
	}

	return os;
}

/**
* Méthode permettant de vérifier si un point existe ou non
* @param uiNumeroSommet le numéro du sommet dont on cherche à vérifier l'existence
* return true si on trouve un CSommet ayant le numéro uiNumeroSommet, return false sinon
*/
bool CGraphe::GRASommetExiste(unsigned int uiNumeroSommet) {
	for (CSommet &SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMObtenirNumero() == uiNumeroSommet) {
			return true;
		}
	}
	return false;
}

