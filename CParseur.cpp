#include "stdafx.h"
#include "CParseur.h"

// -----------------------------------------------------------------------------------------------------
// Classe CParseur
// Cette classe permet de construire un objet CGraphe depuis un fichier contenant une matrice de double
// 
// Le fichier doit �tre de la forme suivante :
//
// NBSommets =
// NBArcs =
// Matrice = [
// <Num�ro_sommet>
// ]
// Arcs = [
// <Sommet_d�part_arc1> <Sommet_arriv�e_arc1>
// ]
//
// -----------------------------------------------------------------------------------------------------

/**
 * Construit un CParseur vide
 */
CParseur::CParseur()
{
}

/**
 * Construit un CParseur depuis une chaine de caract�re et stocke le graphe du fichier sCheminFichier dans un objet CGraphe
 * @param sErreur le chaine de caract�res contenant le chemin du fichier
 * @throws CException si le fichier n'existe pas ou si il ne peut pas �tre ouvert
 */
CParseur::CParseur(string sCheminFichier)
{
	/*cout << "Lecture de " << sCheminFichier << endl;
	ifPARFichier.open(sCheminFichier, ios::in);
	if (ifPARFichier)
	{
		string sLigne;
		unsigned int uiLigne = 0;
		unsigned int uiNbSommets = 0;
		unsigned int uiNbArcs = 0;
		bool sommetParse = false;
		//CArc ARCarcs;
		//CSommet SOMsommets;
		while (getline(ifPARFichier, sLigne))
		{
			if (sLigne.find("]") != -1) { //Si la derni�re ligne est atteinte on arr�te le parser
				break;
			}
			else {
				switch (uiLigne) {
				case 0:
					sLigne = sLigne.substr(sLigne.find("=") + 1, sLigne.size());
					uiNbSommets = (unsigned int)std::stod(sLigne);
					break;
				case 1:
					sLigne = sLigne.substr(sLigne.find("=") + 1, sLigne.size());
					uiNbArcs = (unsigned int)std::stod(sLigne);
					break;
				case 2:
					break;
				default:
					char *pcEnd = new char[sLigne.length() + 1];
					strcpy_s(pcEnd, sLigne.length()+1,sLigne.c_str());
					for (unsigned int uiBoucle = 0; uiBoucle<uiNbColonnes; uiBoucle++) {
						double test = strtod(pcEnd, &pcEnd);
						MATPARmatrice.MATSetElement(uiLigne - 4,uiBoucle,test);
					}
					break;
				}
				uiLigne++;
			}
		}
		ifPARFichier.close();
	}
	else {
		throw CException("Impossible d'ouvrir le fichier");
	}*/
}

/**
 * Retourne une r�f�rence de l'objet CGraphe contenant le graphe pars� par le parseur
 * @return l'objet CGraphe contenant le graphe pr�sent dans le fichier
 */
/*CGraphe& CParseur::PARGetGraphe()
{
	return GRAPARgraphe;
}*/
