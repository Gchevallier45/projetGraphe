#include "stdafx.h"
#include "CGraphe.h"

/**
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
	if (GRASommetExiste(uiNewSommetDepart)) {
		cout << "Le point " << uiNewSommetDepart << " existe deja" << endl;
		return;
	}

	GRARetirerLiaison(uiSommetDepart, uiSommetArrivee);
	GRAAjouterLiaison(uiNewSommetDepart, uiSommetArrivee);

}

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
	if (GRASommetExiste(uiNewSommetArrivee)) {
		cout << "Le point " << uiNewSommetArrivee << " existe deja" << endl;
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

bool CGraphe::GRASommetExiste(unsigned int uiNumeroSommet) {
	for (CSommet &SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMObtenirNumero() == uiNumeroSommet) {
			return true;
		}
	}
	return false;
}

