#pragma once
#include "CSommet.h"
#include "CException.h"
#include "CArc.h"
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
	void GRAAjouterLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee);
	void GRAModifierDepartLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee, unsigned int uiNewSommetDepart);
	void GRAModifierFinLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee, unsigned int uiNewSommetArrivee);
	void GRARetirerLiaison(unsigned int uiSommetDepart, unsigned int uiSommetArrivee);
	void GRARetirerLiaison(CArc CarcParam);
	void GRAInverserGraphe();
	const vector<CSommet>& GRAObtenirListeSommets();
	bool GRASommetExiste(unsigned int uiNumeroSommet);
	friend ostream& operator<<(ostream& os, CGraphe &GRAParam);
	CSommet* GRAObtenirSommet(unsigned int uiNumeroSommet);
};
