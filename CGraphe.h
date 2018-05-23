#pragma once
#include "CSommet.h"
#include <vector>

using namespace std;

class CGraphe
{
private:
	vector<CSommet> vSOMGRAlist;
public:
	CGraphe();
	~CGraphe();
	void GRAAjouterPoint(unsigned int uiNumero);
	void GRAModifierPoint();
	void GRARetirerPoint(unsigned int uiPoint);
	void GRAAjouterLiaison(CSommet *SOMSommetDepart, CSommet *SOMSommetArrivee);
	void GRAModifierLiaison();
	void GRARetirerLiaison();
	void GRAVisualiserGraphe();
	CSommet* GRAObtenirSommet(unsigned int uiNumeroGraphe);
};
