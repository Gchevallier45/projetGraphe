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
	for (unsigned int uiBoucle = 0; uiBoucle < SOMlist.size(); uiBoucle++) {

		if (SOMlist[uiBoucle].SOMObtenirNumero() == uiPoint) {
			SOMlist.erase(SOMlist.begin()+ uiBoucle);
		}	
	}
}

void CGraphe::GRAAjouterLiaison(unsigned int uiPoint1, unsigned int uiPoint2)
{
	unsigned int uiPlaceSommet1, uiPlaceSommet2;
	for (unsigned int uiBoucle = 0; uiBoucle < SOMlist.size(); uiBoucle++) {
		if (SOMlist[uiBoucle].SOMObtenirNumero() == uiPoint1) {
			uiPlaceSommet1 = uiBoucle;
		 }
		if (SOMlist[uiBoucle].SOMObtenirNumero() == uiPoint2) {
			uiPlaceSommet2 = uiBoucle;
		}
	}
	SOMlist[uiPlaceSommet1].SOMAjouterArrivant(&SOMlist[uiPlaceSommet2]);
	SOMlist[uiPlaceSommet1].SOMAjouterPartant(&SOMlist[uiPlaceSommet2]);
	
	SOMlist[uiPlaceSommet2].SOMAjouterArrivant(&SOMlist[uiPlaceSommet1]);
	SOMlist[uiPlaceSommet2].SOMAjouterPartant(&SOMlist[uiPlaceSommet1]);

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
