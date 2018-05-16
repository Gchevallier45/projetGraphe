#include "stdafx.h"
#include "CArc.h"


CArc::CArc()
{
}


CArc::CArc(CSommet* pSOMSommetParam) {
	ARCAjouterDestination(pSOMSommetParam);
}

CArc::~CArc()
{
}

void CArc::ARCAjouterDestination(CSommet* pSOMSommetParam)
{
	pSOMARCDestination = pSOMSommetParam;
}

CSommet* CArc::ARCObtenirSommet() {
	return pSOMARCDestination;
}
