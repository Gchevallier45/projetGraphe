#pragma once

class CSommet;

class CArc
{
private :
	CSommet * pSOMARCDestination;
public:
	CArc();
	CArc(CSommet * pSOMDestination);
	~CArc();
	void ARCAjouterDestination(CSommet* pSOMSommetParam);
	CSommet *ARCObtenirSommet();
};

