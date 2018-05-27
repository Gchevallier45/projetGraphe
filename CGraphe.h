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
	void GRAModifierPoint(unsigned int uiNumeroAvant, unsigned int uiNumeroApres);
	void GRARetirerPoint(unsigned int uiPoint);
	void GRAAjouterLiaison(CSommet &SOMSommetDepart, CSommet &SOMSommetArrivee);
	void GRAModifierDepartLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee, unsigned int uiNewSommetDepart);
	void GRAModifierFinLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee, unsigned int uiNewSommetDepart);
	void GRARetirerLiaison(CSommet &SOMSommetDepart, CSommet &SOMSommetArrivee);
	void GRAInverserGraphe();
	const vector<CSommet>& GRAObtenirListeSommets();
	bool GRASommetExiste(const CSommet& SOMSommet);
	friend ostream& operator<<(ostream& os, CGraphe &GRAParam);
	CSommet* GRAObtenirSommet(unsigned int uiNumeroSommet);
};
