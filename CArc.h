#pragma once

class CSommet; //Permet d'utiliser d'avoir une dépendance circulaire entre CArc et CSommet

// -------------------------------------------------------------------------------------------
// Classe CArc
// Implémente la structure d'un objet arc représentant la liaison entre deux sommets du graphe
// -------------------------------------------------------------------------------------------

class CArc
{
private :
	CSommet* pSOMARCDestination;

public:
	CArc(CSommet& SOMSommetParam);

	void ARCModifierDestination(CSommet& SOMSommetParam);
	CSommet& ARCObtenirSommet();
};

