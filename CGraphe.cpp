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
	for (int i = 0; i < SOMlist.size(); i++) {
		if (SOMlist[i].SOMObtenirNumero == uiPoint) {

			SOMlist.erase(SOMlist.begin()+i);
		}
		
	}
}

void CGraphe::GRAAjouterLiaison(unsigned int uiPoint1, unsigned int uiPoint2)
{
	unsigned int uiPlaceSommet1, uiPlaceSommet2;
	for (int i = 0; i < SOMlist.size(); i++) {
		if (SOMlist[i].SOMObtenirNumero == uiPoint1) {
			uiPlaceSommet1 = i;
		 }
		if (SOMlist[i].SOMObtenirNumero == uiPoint2) {
			uiPlaceSommet2 = i;
			
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
