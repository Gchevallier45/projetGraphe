#include "stdafx.h"
#include "CArc.h"

/**
 * Construit un arc avec un sommet de destination
 * @param pSOMSommetParam le sommet de destination de l'arc
 */
CArc::CArc(CSommet& SOMSommetParam) {
	ARCModifierDestination(SOMSommetParam);
}

/**
 * Modifie la destination de l'arc
 * @param pSOMSommetParam la nouvelle destination de l'arc
 */
void CArc::ARCModifierDestination(CSommet& SOMSommetParam)
{
	pSOMARCDestination = &SOMSommetParam;
}

/**
 * Retourne la destination de l'arc
 * @return un pointeur sur l'objet CSommet correspondant à la destination de l'arc
 */
CSommet& CArc::ARCObtenirSommet() {
	return *pSOMARCDestination;
}

unsigned int CArc::ARCObtenirId() {
	return uiId;
}

