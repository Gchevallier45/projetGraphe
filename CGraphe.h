#pragma once
#include "CSommet.h"
#include <vector>

using namespace std;

// -------------------------------------------------------------------------------------------
// Classe CGraphe
// Implémente la structure du graphe
// -------------------------------------------------------------------------------------------

class CGraphe
{
private:
	vector<CSommet> vSOMGRAlist;
public:
	void GRAAjouterPoint(unsigned int uiNumero);
	void GRAModifierPoint();
	void GRARetirerPoint(unsigned int uiPoint);
	void GRAAjouterLiaison(CSommet *SOMSommetDepart, CSommet *SOMSommetArrivee);
	void GRAModifierLiaison();
	void GRARetirerLiaison(CSommet *SOMSommetDepart, CSommet *SOMSommetArrivee);
	CSommet* GRAObtenirSommet(unsigned int uiNumeroSommet);
	const vector<CSommet>& GRAObtenirListeSommets();
	bool GRASommetExiste(CSommet * SOMSommet);
	friend ostream& operator<<(ostream& os, CGraphe &GRAParam);
};
