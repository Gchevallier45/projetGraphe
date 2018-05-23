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
	CSommet point(uiNumero);

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

void CGraphe::GRAAjouterLiaison(unsigned int uiPoint1, unsigned int uiPoint2)
{
	CSommet *uiPlaceSommet1, *uiPlaceSommet2;
	uiPlaceSommet1 = GRAObtenirSommet(uiPoint1);
	uiPlaceSommet2 = GRAObtenirSommet(uiPoint2);

	uiPlaceSommet1->SOMAjouterArrivant(uiPlaceSommet2);
	uiPlaceSommet1->SOMAjouterPartant(uiPlaceSommet2);
	
	uiPlaceSommet2->SOMAjouterArrivant(uiPlaceSommet1);
	uiPlaceSommet2->SOMAjouterPartant(uiPlaceSommet1);

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
