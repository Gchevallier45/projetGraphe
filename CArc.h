#pragma once
#include "CSommet.h"

class CArc
{
private :
	//CSommet * pSOMDestination;
public:
	CArc();
	CArc(CSommet * pSOMDestination);
	~CArc();
	void ARCAjouterDestination(CSommet* SOMSommetParam);
	int ARCObtenirNumero();
};

