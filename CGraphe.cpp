#include "stdafx.h"
#include "CGraphe.h"


CGraphe::CGraphe()
{
}

CGraphe::~CGraphe()
{
}

void CGraphe::GRAAjouterPoint(unsigned int uiNumero)
{
	vSOMGRAlist.push_back(CSommet(uiNumero));
}

void CGraphe::GRAModifierPoint()
{

}

void CGraphe::GRARetirerPoint(unsigned int uiPoint)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		if (vSOMGRAlist[uiBoucle].SOMObtenirNumero() == uiPoint) {
			vSOMGRAlist[uiBoucle].SOMRetirerSommet();//retire les arcs liés au point
			vSOMGRAlist.erase(vSOMGRAlist.begin() + uiBoucle);//retire le point de la liste du graphe
		}
	}
}

void CGraphe::GRAAjouterLiaison(CSommet *SOMSommetDepart, CSommet *SOMSommetArrivee)
{
	SOMSommetDepart->SOMAjouterArrivant(&CArc(SOMSommetArrivee));
	SOMSommetArrivee->SOMAjouterPartant(&CArc(SOMSommetArrivee));
}

CSommet* CGraphe::GRAObtenirSommet(unsigned int uiNumeroGraphe) {
	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		if (vSOMGRAlist[uiNumeroGraphe].SOMObtenirNumero() == uiNumeroGraphe)
			return &vSOMGRAlist[uiNumeroGraphe];
	}
}

void CGraphe::GRAModifierLiaison()
{

}

void CGraphe::GRARetirerLiaison()
{

}

void CGraphe::GRAVisualiserGraphe()
{

}
