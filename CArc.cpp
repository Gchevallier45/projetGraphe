#include "stdafx.h"
#include "CArc.h"

/**
 * Construit un arc avec un sommet de destination

 */
CArc::CArc(unsigned int uiNumeroSommetDestination,unsigned int uiIdArc, unsigned int uiPoids) {
	uiARCNumeroSommetDestination = uiNumeroSommetDestination;
	uiARCIdLiaison = uiIdArc;
	uiARCPoids = uiPoids;
}

/**
 * Modifie la destination de l'arc

 */
void CArc::ARCModifierDestination(unsigned int uiNumeroSommetDestination)
{
	uiARCNumeroSommetDestination = uiNumeroSommetDestination;
}

/**
 * Retourne la destination de l'arc
 * @return le numéro du sommet correspondant à la destination de l'arc
 */
unsigned int CArc::ARCObtenirSommet() {
	return uiARCNumeroSommetDestination;
}

unsigned int CArc::ARCObtenirIdLiaison() {
	return uiARCIdLiaison;
}

unsigned int CArc::ARCObtenirPoids() {
	return uiARCPoids;
}
