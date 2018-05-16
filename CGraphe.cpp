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
			vSOMGRAlist.erase(vSOMGRAlist.begin()+ uiBoucle);
		}	
	}
}

void CGraphe::GRAAjouterLiaison(unsigned int uiPoint1, unsigned int uiPoint2)
{
	unsigned int uiPlaceSommet1, uiPlaceSommet2;
	for (unsigned int uiBoucle = 0; uiBoucle < vSOMGRAlist.size(); uiBoucle++) {
		if (vSOMGRAlist[uiBoucle].SOMObtenirNumero() == uiPoint1) {
			uiPlaceSommet1 = uiBoucle;
		 }
		if (vSOMGRAlist[uiBoucle].SOMObtenirNumero() == uiPoint2) {
			uiPlaceSommet2 = uiBoucle;
		}
	}
	vSOMGRAlist[uiPlaceSommet1].SOMAjouterArrivant(&vSOMGRAlist[uiPlaceSommet2]);
	vSOMGRAlist[uiPlaceSommet1].SOMAjouterPartant(&vSOMGRAlist[uiPlaceSommet2]);
	
	vSOMGRAlist[uiPlaceSommet2].SOMAjouterArrivant(&vSOMGRAlist[uiPlaceSommet1]);
	vSOMGRAlist[uiPlaceSommet2].SOMAjouterPartant(&vSOMGRAlist[uiPlaceSommet1]);

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
