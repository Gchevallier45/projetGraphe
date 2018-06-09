#pragma once

// -------------------------------------------------------------------------------------------
// Classe CArc
// Impl�mente la structure d'un objet arc repr�sentant la liaison entre deux sommets du graphe
// -------------------------------------------------------------------------------------------

class CArc
{
private :

	unsigned int uiARCNumeroSommetDestination;
	unsigned int uiARCPoids;
	unsigned int uiARCIdLiaison;

public:
	CArc(unsigned int uiNumeroSommetDestination, unsigned int uiIdArc, unsigned int uiPoids);

	void ARCModifierDestination(unsigned int uiNumeroSommetDestination);
	unsigned int ARCObtenirSommet();
	unsigned int ARCObtenirIdLiaison();
	unsigned int ARCObtenirPoids();
};

