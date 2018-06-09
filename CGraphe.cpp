#include "stdafx.h"
#include "CGraphe.h"

CGraphe::CGraphe() {
	uiGRACompteurLiaisons = 0;
}

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
 * @param uiSommet1 le sommet 1 de la liaison
 * @param uiSommet2 le sommet 2 de la liaison
 * @param uiPoidsLiaison le poids de la liaison
 */
void CGraphe::GRAAjouterLiaison(unsigned int uiSommet1, unsigned int uiSommet2, unsigned int uiPoidsLiaison)
{
	if (GRASommetExiste(uiSommet1) == false) {
		throw CException("Le point " + to_string(uiSommet1) + " n'existe pas");
	}
	else if (GRASommetExiste(uiSommet2) == false) {
		throw CException("Le point " + to_string(uiSommet2) + " n'existe pas");
	}
	else {
		CSommet& SOMSommetDepart = *GRAObtenirSommet(uiSommet1);
		CSommet& SOMSommetArrivee = *GRAObtenirSommet(uiSommet2);

		SOMSommetDepart.SOMAjouterArcVers(SOMSommetArrivee, uiGRACompteurLiaisons, uiPoidsLiaison);
		SOMSommetArrivee.SOMAjouterArcVers(SOMSommetDepart, uiGRACompteurLiaisons, uiPoidsLiaison);
		uiGRACompteurLiaisons++;
	}
}


/**
 * 

 */
void CGraphe::GRAModifierLiaison(unsigned int uiIdLiaison, unsigned int uiSommetARemplacer, unsigned int uiNouveauSommet)
{
	if (GRASommetExiste(uiSommetARemplacer) == false) {
		throw CException("Le point " + to_string(uiSommetARemplacer) + " n'existe pas");
	}
	else if (GRASommetExiste(uiNouveauSommet) == false) {
		throw CException("Le point " + to_string(uiNouveauSommet) + " n'existe pas");
	}
	else {
		CSommet& SOMSommetLiaison = *GRAObtenirSommet(uiSommetARemplacer);
		for (CArc ARCBoucle : SOMSommetLiaison.SOMObtenirArcs()) {
			if (ARCBoucle.ARCObtenirIdLiaison() == uiIdLiaison) {
				CSommet& SOMSommetDestinationLiaison = ARCBoucle.ARCObtenirSommet();
				unsigned int uiPoidsLiaison = ARCBoucle.ARCObtenirPoids();
				SOMSommetLiaison.SOMRetirerArc(uiIdLiaison);
				SOMSommetDestinationLiaison.SOMRetirerArc(uiIdLiaison);
				SOMSommetLiaison.SOMAjouterArcVers(SOMSommetDestinationLiaison, uiIdLiaison, uiPoidsLiaison);
				SOMSommetDestinationLiaison.SOMAjouterArcVers(SOMSommetLiaison, uiIdLiaison, uiPoidsLiaison);
				break;
			}
		}
	}

}


/**
 * Retire la liaison entre deux sommets dans le graphe 
 * @param uiIdLiaison l'id de la liaison � supprimer
 */
void CGraphe::GRARetirerLiaison(unsigned int uiIdLiaison)
{
	for (CSommet SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMArcExiste(uiIdLiaison)) {
			CSommet& SOMSommetDestination = SOMBoucle.SOMObtenirArc(uiIdLiaison)->ARCObtenirSommet();
			SOMBoucle.SOMRetirerArc(uiIdLiaison);
			SOMSommetDestination.SOMRetirerArc(uiIdLiaison);
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
 * (l'utilisateur doit se charger de d�sallouer la matrice retourn�e par la fonction)
 * @return un graphe contenant l'arbre couvrant T de l'objet graphe actuel
 */
CGraphe * CGraphe::GRABoruvka()
{
	CGraphe GRATmp = CGraphe(*this); //Copie du graphe courant qui sera utilis�e pour l'algo
	CGraphe *GRAArbreCouvrant = new CGraphe(); //Le graphe qui contient l'arbre couvrant

	while (GRATmp.GRAObtenirListeSommets().size() != 1) {
		
		//Suppression des boucles
		for (CSommet SOMBoucle : GRATmp.GRAObtenirListeSommets()) {
			for (int uiBoucle = 0; uiBoucle < SOMBoucle.SOMObtenirArcs().size(); uiBoucle++) {
				CArc ARCBoucle = SOMBoucle.SOMObtenirArcs()[uiBoucle];
				CSommet SOMSommetDestination = ARCBoucle.ARCObtenirSommet();
				if (SOMSommetDestination.SOMObtenirNumero() == SOMBoucle.SOMObtenirNumero()) {
					GRATmp.GRARetirerLiaison(ARCBoucle.ARCObtenirIdLiaison()); //Suppression de l'arc qui boucle
					uiBoucle--;
				}
			}
		}

		//Suppression des doublons
		for (CSommet SOMBoucle : GRATmp.GRAObtenirListeSommets()) {
			for (int uiBoucle = 0; uiBoucle < SOMBoucle.SOMObtenirArcs().size(); uiBoucle++) {
				CArc ARC1 = SOMBoucle.SOMObtenirArcs()[uiBoucle];
				for (int uiBoucle1 = uiBoucle+1; uiBoucle < SOMBoucle.SOMObtenirArcs().size()-1; uiBoucle++) {
					CArc ARC2 = SOMBoucle.SOMObtenirArcs()[uiBoucle1];
					if (ARC1.ARCObtenirSommet().SOMObtenirNumero() == ARC2.ARCObtenirSommet().SOMObtenirNumero()) {
						if (ARC1.ARCObtenirPoids() < ARC2.ARCObtenirPoids()) {
							GRATmp.GRARetirerLiaison(ARC2.ARCObtenirIdLiaison()); //Suppression de l'arc2
						}
						else {
							GRATmp.GRARetirerLiaison(ARC1.ARCObtenirIdLiaison()); //Suppression de l'arc1
						}
						uiBoucle--;
						uiBoucle1--;
					}
				}
			}
		}

		for (int uiBoucle = 0; uiBoucle < GRATmp.GRAObtenirListeSommets().size(); uiBoucle++) {
			CSommet SOMBoucle = GRATmp.GRAObtenirListeSommets()[uiBoucle];

			//Recherche de l'ar�te avec poids minimal
			CArc ARCArcPoidsMin = SOMBoucle.SOMObtenirArcs()[0];
			for (CArc ARCBoucle : SOMBoucle.SOMObtenirArcs()) {
				if (ARCBoucle.ARCObtenirPoids() < ARCArcPoidsMin.ARCObtenirPoids()) {
					ARCArcPoidsMin = ARCBoucle;
				}
			}

			//Ajout de l'ar�te � l'arbre
			CSommet SOMDestinationArcPoidsMin = ARCArcPoidsMin.ARCObtenirSommet();
			if (!GRAArbreCouvrant->GRASommetExiste(SOMBoucle.SOMObtenirNumero()))
				GRAArbreCouvrant->GRAAjouterPoint(SOMBoucle.SOMObtenirNumero());
			if (!GRAArbreCouvrant->GRASommetExiste(SOMDestinationArcPoidsMin.SOMObtenirNumero()))
				GRAArbreCouvrant->GRAAjouterPoint(SOMDestinationArcPoidsMin.SOMObtenirNumero());
			GRAArbreCouvrant->GRAAjouterLiaison(SOMBoucle.SOMObtenirNumero(), SOMDestinationArcPoidsMin.SOMObtenirNumero(), ARCArcPoidsMin.ARCObtenirPoids());

			//Fusion des sommets, on supprime le sommet en cours et on redirige ses ar�tes vers le sommet de destination
			for (CArc ARCBoucle : SOMBoucle.SOMObtenirArcs()) {
				GRATmp.GRAModifierLiaison(ARCBoucle.ARCObtenirIdLiaison(), SOMBoucle.SOMObtenirNumero(), SOMDestinationArcPoidsMin.SOMObtenirNumero());
			}
			GRATmp.GRARetirerPoint(SOMBoucle.SOMObtenirNumero());
			uiBoucle--; //Car on a supprim� le sommet en cours
		}

	}

	return GRAArbreCouvrant;
}
