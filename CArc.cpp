#include "stdafx.h"
#include "CArc.h"

/**
 * Construit un arc avec un sommet de destination
 * @param uiNumeroSommetDestination le numéro du sommet de destination
 * @param uiIdArc l'id de la liaison
 * @param uiPoids le poids de la liaison
 */
CArc::CArc(unsigned int uiNumeroSommetDestination, unsigned int uiIdArc, unsigned int uiPoids) {
	uiARCNumeroSommetDestination = uiNumeroSommetDestination;
	uiARCIdLiaison = uiIdArc;
	uiARCPoids = uiPoids;
}

/**
 * Modifie la destination de l'arc
 * @param uiNumeroSommetDestination le nouveau sommet de destination
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

/**
 * Retourne l'id de liaison de l'arc
 * @return l'id de la liaison
 */
unsigned int CArc::ARCObtenirIdLiaison() {
	return uiARCIdLiaison;
}

/**
 * Retourne le poids de l'arc
 * @return le poids de l'arc
 */
unsigned int CArc::ARCObtenirPoids() {
	return uiARCPoids;
}
