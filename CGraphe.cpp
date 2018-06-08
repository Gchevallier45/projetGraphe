#include "stdafx.h"
#include "CGraphe.h"

/**
 * M�thode permettant d'ajouter un CSommet au CGraphe
 * @param uiPoint le num�ro que prendra le CSommet
 */
void CGraphe::GRAAjouterPoint(unsigned int uiPoint)
{
	if (GRASommetExiste(uiPoint)) {
		throw CException("Le point " + to_string(uiPoint) + " existe deja");
	}
	else {
		vSOMGRAlist.push_back(CSommet(uiPoint));
	}
}

/**
 * M�thode permettant de modifier le num�ro d'un CSommet
 * @param uiNumeroAvant le num�ro du CSommet � changer
 * @param uiNumeroApres le num�ro que prendra le CSommet
 */
void CGraphe::GRAModifierPoint(unsigned int uiNumeroAvant, unsigned int uiNumeroApres)
{
	if (GRASommetExiste(uiNumeroAvant) == false) {
		throw CException("Le point " + to_string(uiNumeroAvant) + " n'existe pas");
	}
	else if (GRASommetExiste(uiNumeroApres)) {
		throw CException("Le point " + to_string(uiNumeroApres) + " existe deja");
	}
	else {
		for (CSommet &SOMBoucle : vSOMGRAlist) {
			if (SOMBoucle.SOMObtenirNumero() == uiNumeroAvant) {
				SOMBoucle.SOMModifierNumero(uiNumeroApres);//retire le point de la liste du graphe
				break;
			}
		}
	}
}

/**
 * M�thode permettant de retirer un point du CGraphe
 * @param uiPoint le num�ro du point � retirer
 */
void CGraphe::GRARetirerPoint(unsigned int uiPoint)
{
	if (GRASommetExiste(uiPoint) == false) {
		throw CException("Le point " + to_string(uiPoint) + " n'existe pas");
	}
	else {
		for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
			if (vSOMGRAlist[uiBoucle].SOMObtenirNumero() == uiPoint) {
				vSOMGRAlist.erase(vSOMGRAlist.begin() + uiBoucle);//retire le point de la liste du graphe
				break;
			}
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
		throw CException("Le point " + to_string(uiSommetDepart) + " n'existe pas");
	}
	else if (GRASommetExiste(uiSommetArrivee) == false) {
		throw CException("Le point " + to_string(uiSommetArrivee) + " n'existe pas");
	}
	else {
		CSommet& SOMSommetDepart = *GRAObtenirSommet(uiSommetDepart);
		CSommet& SOMSommetArrivee = *GRAObtenirSommet(uiSommetArrivee);

		if (SOMSommetDepart.SOMArcExiste(SOMSommetArrivee)) {
			throw CException("La liaison du point " + to_string(SOMSommetDepart.SOMObtenirNumero()) + " vers le sommet "
				+ to_string(SOMSommetArrivee.SOMObtenirNumero()) + " existe deja");
		}
		else {
			SOMSommetDepart.SOMAjouterPartant(SOMSommetArrivee);
			SOMSommetArrivee.SOMAjouterArrivant(SOMSommetDepart);
		}
	}
}


/**
 * M�thode permettant la modification de la partie d�part d'un lien. Il faut que tous les sommets pass�s en param�tre existe
 * @param uiSommetDepart le num�ro du sommet de d�part d'un liaison
 * @param uiSommetArrivee le num�ro du sommet d'arriv�e d'une liaison
 * @param uiNewSommetDepart le num�ro du nouveau sommet de d�part de la liaison des sommet pr�c�dents
 */
void CGraphe::GRAModifierDepartLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee, unsigned int uiNewSommetDepart)
{
	if (GRASommetExiste(uiSommetDepart) == false) {
		throw CException("Le point " + to_string(uiSommetDepart) + " n'existe pas");
	}
	else if (GRASommetExiste(uiSommetArrivee) == false) {
		throw CException("Le point " + to_string(uiSommetArrivee) + " n'existe pas");
	}
	else if (GRASommetExiste(uiNewSommetDepart) == false) {
		throw CException("Le point " + to_string(uiNewSommetDepart) + " n'existe pas");
	}
	else {
		GRARetirerLiaison(uiSommetDepart, uiSommetArrivee);
		GRAAjouterLiaison(uiNewSommetDepart, uiSommetArrivee);
	}

}

/**
 * M�thode permettant la modification de la partie arriv�e d'un lien. Il faut que tous les sommets pass�s en param�tre existe
 * @param uiSommetDepart le num�ro du sommet de d�part d'un liaison
 * @param uiSommetArrivee le num�ro du sommet d'arriv�e d'une liaison
 * @param uiNewSommetArrivee le num�ro du nouveau sommet de d'arriv�e de la liaison des sommet pr�c�dents
 */
void CGraphe::GRAModifierFinLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee, unsigned int uiNewSommetArrivee)
{
	if (GRASommetExiste(uiSommetDepart) == false) {
		throw CException("Le point " + to_string(uiSommetDepart) + " n'existe pas");
	} 
	else if (GRASommetExiste(uiSommetArrivee) == false) {
		throw CException("Le point " + to_string(uiSommetArrivee) + " n'existe pas");
	}
	else if (GRASommetExiste(uiNewSommetArrivee) == false) {
		throw CException("Le point " + to_string(uiNewSommetArrivee) + " n'existe pas");
	}
	else {
		GRARetirerLiaison(uiSommetDepart, uiSommetArrivee);
		GRAAjouterLiaison(uiSommetDepart, uiNewSommetArrivee);
	}
}

/*
void CGraphe::GRARetirerLiaison(CArc ARCParam)
{
	if (GRASommetExiste(uiSommetDepart) == false) {
		throw CException("Le point " + to_string(uiSommetDepart) + " n'existe pas");
	}
	else if (GRASommetExiste(uiSommetArrivee) == false) {
		throw CException("Le point " + to_string(uiSommetArrivee) + " n'existe pas");
	}
	else {
		CSommet& SOMSommetDepart = *GRAObtenirSommet(uiSommetDepart);
		CSommet& SOMSommetArrivee = *GRAObtenirSommet(uiSommetArrivee);

		if (SOMSommetDepart.SOMArcExiste(SOMSommetArrivee) == false)
		{
			throw CException("La liaison du point " + to_string(SOMSommetDepart.SOMObtenirNumero()) + " vers le sommet "
				+ to_string(SOMSommetArrivee.SOMObtenirNumero()) + "n'existe pas");
		}
		else {
			SOMSommetDepart.SOMRetirerPartant(SOMSommetArrivee);
			SOMSommetArrivee.SOMRetirerArrivant(SOMSommetDepart);
		}
	}
}*/

/**
 * Retire la liaison entre deux sommets dans le graphe 
 * @param uiSommetDepart le sommet de d�part de la liaison
 * @param uiSommetArrivee le sommet d'arriv�e de la liaison
 */
void CGraphe::GRARetirerLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee)
{
	if (GRASommetExiste(uiSommetDepart) == false) {
		throw CException("Le point " + to_string(uiSommetDepart) + " n'existe pas");
	}
	else if (GRASommetExiste(uiSommetArrivee) == false) {
		throw CException("Le point " + to_string(uiSommetArrivee) + " n'existe pas");
	}
	else {
		CSommet& SOMSommetDepart = *GRAObtenirSommet(uiSommetDepart);
		CSommet& SOMSommetArrivee = *GRAObtenirSommet(uiSommetArrivee);

		if (SOMSommetDepart.SOMArcExiste(SOMSommetArrivee) == false)
		{
			throw CException("La liaison du point " + to_string(SOMSommetDepart.SOMObtenirNumero()) + " vers le sommet "
				+ to_string(SOMSommetArrivee.SOMObtenirNumero()) + "n'existe pas");
		}
		else {
			SOMSommetDepart.SOMRetirerPartant(SOMSommetArrivee);
			SOMSommetArrivee.SOMRetirerArrivant(SOMSommetDepart);
		}
	}
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
 * @return true si on trouve un CSommet ayant le num�ro uiNumeroSommet, false sinon
 */
bool CGraphe::GRASommetExiste(unsigned int uiNumeroSommet) {
	for (CSommet &SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMObtenirNumero() == uiNumeroSommet) {
			return true;
		}
	}
	return false;
}

/**
* Implementation de l'algorithme de Boruvka
* @return un graphe contenant l'arbre couvrant T de l'objet graphe actuel
*/
CGraphe * CGraphe::GRABoruvka() //Remplacer ArcsArrivant par Arc
{
	CGraphe GRATmp = CGraphe(*this);
	CGraphe *GRAArbreCouvrant = new CGraphe();

	while (GRATmp.GRAObtenirListeSommets().size() != 1) {
		
		//Suppression des boucles
		for (CSommet SOMBoucle : GRATmp.GRAObtenirListeSommets()) {
			for (int uiBoucle = 0; uiBoucle < SOMBoucle.SOMObtenirArcsArrivant().size(); uiBoucle++) {
				CArc ARCBoucle = SOMBoucle.SOMObtenirArcsArrivant()[uiBoucle];
				CSommet SOMSommetDestination = ARCBoucle.ARCObtenirSommet();
				if (SOMSommetDestination.SOMObtenirNumero() == SOMBoucle.SOMObtenirNumero()) {
					//supprimer l'arc qui boucle
					uiBoucle--;
				}
			}
		}

		//Suppression des doublons
		for (CSommet SOMBoucle : GRATmp.GRAObtenirListeSommets()) {
			for (int uiBoucle = 0; uiBoucle < SOMBoucle.SOMObtenirArcsArrivant().size(); uiBoucle++) {
				CArc ARC1 = SOMBoucle.SOMObtenirArcsArrivant()[uiBoucle];
				for (int uiBoucle1 = uiBoucle+1; uiBoucle < SOMBoucle.SOMObtenirArcsArrivant().size(); uiBoucle++) {
					CArc ARC2 = SOMBoucle.SOMObtenirArcsArrivant()[uiBoucle1];
					if (ARC1.ARCObtenirSommet().SOMObtenirNumero() == ARC2.ARCObtenirSommet().SOMObtenirNumero()) {
						if (ARC1.ARCObtenirPoids() < ARC2.ARCObtenirPoids()) {
							//Supprimer arc2
						}
						else {
							//Supprimer arc1
						}
						uiBoucle--;
						uiBoucle1--;
					}
				}
			}
		}

		CGraphe GRATmpBoucle = CGraphe(GRATmp); //On utilise un graphe temporaire
		for (CSommet SOMBoucle : GRATmpBoucle.GRAObtenirListeSommets()) {
		/*for(int uiBoucle = 0; uiBoucle < GRATmp.GRAObtenirListeSommets().size()){
			CSommet SOMBoucle = GRATmp.GRAObtenirListeSommets()[uiBoucle];*/

			//Recherche de l'ar�te avec poids minimal
			CArc ARCArcPoidsMin = SOMBoucle.SOMObtenirArcsArrivant()[0];
			for (CArc ARCBoucle : SOMBoucle.SOMObtenirArcsArrivant()) {
				if (ARCBoucle.ARCObtenirPoids() < ARCArcPoidsMin.ARCObtenirPoids()) {
					ARCArcPoidsMin = ARCBoucle;
				}
			}

			//Ajout de l'ar�te � l'arbre
			if (!GRAArbreCouvrant->GRASommetExiste(SOMBoucle.SOMObtenirNumero()))
				GRAArbreCouvrant->GRAAjouterPoint(SOMBoucle.SOMObtenirNumero());
			if (!GRAArbreCouvrant->GRASommetExiste(ARCArcPoidsMin.ARCObtenirSommet().SOMObtenirNumero()))
				GRAArbreCouvrant->GRAAjouterPoint(ARCArcPoidsMin.ARCObtenirSommet().SOMObtenirNumero());
			GRAArbreCouvrant->GRAAjouterLiaison(SOMBoucle.SOMObtenirNumero(), ARCArcPoidsMin.ARCObtenirSommet().SOMObtenirNumero(), ARCArcPoidsMin.ARCObtenirPoids());

			//Fusion des sommets
			//for(SOMBoucle.SOMObtenirArcsArrivant())
		}

	}

	return GRAArbreCouvrant;
}
