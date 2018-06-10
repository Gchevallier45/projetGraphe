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
	unsigned int uiGRACompteurLiaisons;
public:
	CGraphe();
	void GRAAjouterPoint(unsigned int uiNumero);
	void GRAModifierPoint(unsigned int uiNumeroAvant, unsigned int uiNumeroApres);
	void GRARetirerPoint(unsigned int uiPoint);
	void GRAAjouterLiaison(unsigned int uiSommet1, unsigned int uiSommet2, unsigned int uiPoidsLiaison);
	void GRAModifierLiaison(unsigned int uiIdLiaison, unsigned int uiSommetARemplacer, unsigned int uiNouveauSommet);
	void GRARetirerLiaison(unsigned int uiIdLiaison);
	void GRAObtenirSommetsLiaison(unsigned int *puiTabSommets, unsigned int uiIdLiaison);
	CGraphe* GRABoruvka();
	const vector<CSommet>& GRAObtenirListeSommets();
	bool GRASommetExiste(unsigned int uiNumeroSommet);
	friend ostream& operator<<(ostream& os, CGraphe &GRAParam);
	CSommet* GRAObtenirSommet(unsigned int uiNumeroSommet);
};
