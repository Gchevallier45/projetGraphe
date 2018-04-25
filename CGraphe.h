#pragma once
#include "CSommet.h"
#include <vector>

using namespace std;

class CGraphe
{
private:
	vector<CSommet> SOMlist;
public:
	CGraphe();
	~CGraphe();
	void ajouterPoint();
	void modifierPoint();
	void retirerPoint();
	void ajouterLiaison();
	void modifierLiaison();
	void retirerLiaison();
	void visualiserGraphe();
};
