#pragma once

class CSommet; //Permet d'utiliser d'avoir une d�pendance circulaire

class CArc
{
private :
	CSommet * pSOMARCDestination;

public:
	CArc(CSommet *pSOMDestination);
	~CArc();
	void ARCAjouterDestination(CSommet* pSOMSommetParam);
	CSommet *ARCObtenirSommet();
};

