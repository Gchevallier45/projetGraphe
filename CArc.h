#pragma once

class CSommet; //Permet d'utiliser d'avoir une d�pendance circulaire entre CArc et CSommet

// -------------------------------------------------------------------------------------------
// Classe CArc
// Impl�mente la structure d'un objet arc repr�sentant la liaison entre deux sommets du graphe
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

