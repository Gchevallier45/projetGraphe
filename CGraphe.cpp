#include "stdafx.h"
#include "CGraphe.h"

/**
* M�thode permettant d'ajouter un CSommet au CGraphe
* @Param uiPoint le num�ro que prendra le CSommet
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
* M�thode permettant de modifier le num�ro d'un CSommet
* @Param uiNumeroAvant le num�ro du CSommet � changer
* @Param uiNumeroApres le num�ro que prendra le CSommet
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
* M�thode permettant de retirer un point du CGraphe
* @Param uiPoint le num�ro du point � retirer
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
 * @param uiSommetDepart le sommet de d�part de la liaison
 * @param uiSommetArrivee le sommet d'arriv�e de la liaison
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
* M�thode permettant la modification de la partie d�part d'un lien. Il faut que tous les sommets pass�s en param�tre existe
* @Param uiSommetDepart le num�ro du sommet de d�part d'un liaison
* @Param uiSommetArrivee le num�ro du sommet d'arriv�e d'une liaison
* @Param uiNewSommetDepart le num�ro du nouveau sommet de d�part de la liaison des sommet pr�c�dents
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
* M�thode permettant la modification de la partie arriv�e d'un lien. Il faut que tous les sommets pass�s en param�tre existe
* @Param uiSommetDepart le num�ro du sommet de d�part d'un liaison
* @Param uiSommetArrivee le num�ro du sommet d'arriv�e d'une liaison
* @Param uiNewSommetArrivee le num�ro du nouveau sommet de d'arriv�e de la liaison des sommet pr�c�dents
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
 * @param uiSommetDepart le sommet de d�part de la liaison
 * @param uiSommetArrivee le sommet d'arriv�e de la liaison
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
 * Retourne l'objet sommet correspondant au num�ro du sommet pass� en param�tre
 * @param uiNumeroSommet le num�ro du sommet � chercher
 * @return un pointeur sur le sommet correspondant si celui-ci est trouv� dans le graphe, null sinon
 */
CSommet* CGraphe::GRAObtenirSommet(unsigned int uiNumeroSommet) {
	for (CSommet &SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMObtenirNumero() == uiNumeroSommet)
			return &SOMBoucle;
	}
	return NULL;
}

/**
* M�thode permettant d'inverser le sens des liaisons du graphe
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
 * Surcharge de l'op�rateur << pour afficher un graphe � l'�cran
 * @param os le flux dans lequel �crire les donn�es du graphe
 * @param GRAParam le graphe � afficher
 * @return le flux pass� en param�tre
 */
ostream& operator<<(ostream& os, CGraphe &GRAParam) {
	vector<CSommet> listeSommets = GRAParam.GRAObtenirListeSommets();

	for (CSommet &SOMBoucle : listeSommets) {
		os << SOMBoucle;
	}

	return os;
}

/**
* M�thode permettant de v�rifier si un point existe ou non
* @param uiNumeroSommet le num�ro du sommet dont on cherche � v�rifier l'existence
* return true si on trouve un CSommet ayant le num�ro uiNumeroSommet, return false sinon
*/
bool CGraphe::GRASommetExiste(unsigned int uiNumeroSommet) {
	for (CSommet &SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMObtenirNumero() == uiNumeroSommet) {
			return true;
		}
	}
	return false;
}

