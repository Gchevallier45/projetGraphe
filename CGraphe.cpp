#include "stdafx.h"
#include "CGraphe.h"

/**
 * Constructeur par défaut
 */
CGraphe::CGraphe() {
	uiGRACompteurLiaisons = 0;
}

/**
 * Méthode permettant d'ajouter un CSommet au CGraphe
 * @param uiPoint le numéro que prendra le CSommet
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
 * Méthode permettant de modifier le numéro d'un CSommet
 * @param uiNumeroAvant le numéro du CSommet à changer
 * @param uiNumeroApres le numéro que prendra le CSommet
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
 * Méthode permettant de retirer un point du CGraphe
 * @param uiPoint le numéro du point à retirer
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
 * Modifie une liaison du graphe
 * @param uiIdLiaison l'id de la liaison à modifier
 * @param uiSommetARemplacer le numéro du sommet à remplacer
 * @param uiNouveauSommet le numéro du nouveau sommet de la liaison
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
		CSommet& SOMNouveauSommet = *GRAObtenirSommet(uiNouveauSommet);
		for (CArc ARCBoucle : SOMSommetLiaison.SOMObtenirArcs()) {
			if (ARCBoucle.ARCObtenirIdLiaison() == uiIdLiaison) {
				CSommet& SOMSommetDestinationLiaison = *GRAObtenirSommet(ARCBoucle.ARCObtenirSommet());
				unsigned int uiPoidsLiaison = ARCBoucle.ARCObtenirPoids();
				SOMSommetLiaison.SOMRetirerArc(uiIdLiaison);
				SOMSommetDestinationLiaison.SOMRetirerArc(uiIdLiaison);
				SOMNouveauSommet.SOMAjouterArcVers(SOMSommetDestinationLiaison, uiIdLiaison, uiPoidsLiaison);
				SOMSommetDestinationLiaison.SOMAjouterArcVers(SOMNouveauSommet, uiIdLiaison, uiPoidsLiaison);
				break;
			}
		}
	}

}

/**
 * Retire la liaison entre deux sommets dans le graphe 
 * @param uiIdLiaison l'id de la liaison à supprimer
 */
void CGraphe::GRARetirerLiaison(unsigned int uiIdLiaison)
{
	for (CSommet& SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMArcExiste(uiIdLiaison)) {
			CSommet& SOMSommetDestination = *GRAObtenirSommet(SOMBoucle.SOMObtenirArc(uiIdLiaison)->ARCObtenirSommet());
			SOMBoucle.SOMRetirerArc(uiIdLiaison);
			SOMSommetDestination.SOMRetirerArc(uiIdLiaison);
		}
	}
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
 * Retourne une liste ! en lecture seule ! des sommets du graphe
 * @return vSOMGRAlist la liste des sommets du graphe
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
 * @return true si on trouve un CSommet ayant le numéro uiNumeroSommet, false sinon
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
 * Retourne dans le tableau passé en paramètre les numéros des sommets de la liaison
 * @param puiTabSommets le tableau pour stocker les numéros des sommets
 * @param uiIdLiaison l'id de la liaison à rechercher
 */
void CGraphe::GRAObtenirSommetsLiaison(unsigned int *puiTabSommets, unsigned int uiIdLiaison) {
	unsigned int uiIndice = 0;
	for (CSommet& SOMBoucle : vSOMGRAlist) {
		if (SOMBoucle.SOMArcExiste(uiIdLiaison)) {
			puiTabSommets[uiIndice] = SOMBoucle.SOMObtenirNumero();
			uiIndice++;
		}
	}
}

/**
 * Implementation de l'algorithme de Boruvka, retourne l'arbre couvrant de poids minimal du graphe courant
 * (l'utilisateur doit se charger de désallouer le graphe retournée par la fonction)
 * @return un graphe contenant l'arbre couvrant T de l'objet graphe actuel
 */
CGraphe * CGraphe::GRABoruvka()
{
	CGraphe GRATmp = CGraphe(*this); //Copie du graphe courant qui sera utilisée pour l'algo
	CGraphe *GRAArbreCouvrant = new CGraphe(); //Le graphe qui contient l'arbre couvrant
	
	while (GRATmp.GRAObtenirListeSommets().size() != 1) {
		//Suppression des boucles
		for (CSommet SOMBoucle : GRATmp.GRAObtenirListeSommets()) {
			for(CArc &ARCBoucle : SOMBoucle.SOMObtenirArcs()){
				CSommet SOMSommetDestination = ARCBoucle.ARCObtenirSommet();
				if (SOMSommetDestination.SOMObtenirNumero() == SOMBoucle.SOMObtenirNumero()) {
					GRATmp.GRARetirerLiaison(ARCBoucle.ARCObtenirIdLiaison()); //Suppression de l'arc qui boucle
				}
			}
		}

		//Suppression des doublons
		for (CSommet SOMBoucle : GRATmp.GRAObtenirListeSommets()) {
			for (int uiBoucle = 0; uiBoucle < SOMBoucle.SOMObtenirArcs().size(); uiBoucle++) {
				CArc& ARC1 = SOMBoucle.SOMObtenirArcs()[uiBoucle];
				for (int uiBoucle1 = uiBoucle + 1; uiBoucle < SOMBoucle.SOMObtenirArcs().size() - 1; uiBoucle++) {
					CArc& ARC2 = SOMBoucle.SOMObtenirArcs()[uiBoucle1];
					if (ARC1.ARCObtenirSommet() == ARC2.ARCObtenirSommet()) {
						if (ARC1.ARCObtenirPoids() < ARC2.ARCObtenirPoids()) {
							GRATmp.GRARetirerLiaison(ARC2.ARCObtenirIdLiaison()); //Suppression de l'arc2
						}
						else {
							GRATmp.GRARetirerLiaison(ARC1.ARCObtenirIdLiaison()); //Suppression de l'arc1
						}
					}
				}
			}
		}

		vector<CSommet> vSOMSommetsAvantModif = GRATmp.GRAObtenirListeSommets(); //On copie la liste des sommets avant de boucler dessus sinon elle est modifiée et on ne peut pas boucler correctement
		for(CSommet& SOMBoucle:vSOMSommetsAvantModif){
			//Recherche de l'arête avec poids minimal
			CArc ARCArcPoidsMin = SOMBoucle.SOMObtenirArcs()[0];
			for (CArc &ARCBoucle : SOMBoucle.SOMObtenirArcs()) {
				if (ARCBoucle.ARCObtenirPoids() < ARCArcPoidsMin.ARCObtenirPoids()) {
					ARCArcPoidsMin = ARCBoucle;
				}
			}

			CSommet SOMDestinationArcPoidsMin = ARCArcPoidsMin.ARCObtenirSommet();

			//Permet d'obtenir les sommets de la liaison sur le graphe original pour ensuite l'ajouter dans l'arbre
			unsigned int puiSommetsLiaisonsReels[2];
			GRAObtenirSommetsLiaison(puiSommetsLiaisonsReels, ARCArcPoidsMin.ARCObtenirIdLiaison());

			if (GRATmp.GRASommetExiste(SOMBoucle.SOMObtenirNumero()) && GRATmp.GRASommetExiste(SOMDestinationArcPoidsMin.SOMObtenirNumero())) { //Evite d'ajouter des liaisons en double
				//Ajout de l'arête à l'arbre
				if (!GRAArbreCouvrant->GRASommetExiste(puiSommetsLiaisonsReels[0]))
					GRAArbreCouvrant->GRAAjouterPoint(puiSommetsLiaisonsReels[0]);
				if (!GRAArbreCouvrant->GRASommetExiste(puiSommetsLiaisonsReels[1]))
					GRAArbreCouvrant->GRAAjouterPoint(puiSommetsLiaisonsReels[1]);
				GRAArbreCouvrant->GRAAjouterLiaison(puiSommetsLiaisonsReels[0], puiSommetsLiaisonsReels[1], ARCArcPoidsMin.ARCObtenirPoids());
				
				//Fusion des sommets sur la copie du graphe, on supprime le sommet en cours et on redirige ses arêtes vers le sommet de destination
				for (CArc &ARCBoucle : SOMBoucle.SOMObtenirArcs()) {
					GRATmp.GRAModifierLiaison(ARCBoucle.ARCObtenirIdLiaison(), SOMBoucle.SOMObtenirNumero(), SOMDestinationArcPoidsMin.SOMObtenirNumero());
				}
				GRATmp.GRARetirerLiaison(ARCArcPoidsMin.ARCObtenirIdLiaison());
				GRATmp.GRARetirerPoint(SOMBoucle.SOMObtenirNumero());
			}
		}
	}

	return GRAArbreCouvrant;
}