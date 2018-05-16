#include "stdafx.h"
#include "CArc.h"


CArc::CArc()
{
}


CArc::CArc(CSommet* SOMSommetParam) {
	ARCAjouterDestination(SOMSommetParam);
}

CArc::~CArc()
{
}

void CArc::ARCAjouterDestination(CSommet* SOMSommetParam)
{
	pARCSOMDestination = SOMSommetParam;
}

int CArc::ARCObtenirNumero() {
	return pARCSOMDestination->SOMObtenirNumero;
}
