#pragma once
#include "CArc.h"

class CSommet
{
private :
	unsigned int uiNumero;
	CArc ** pARCArrivant;
	CArc ** pARCPartant;

public:
	CSommet();
	~CSommet();
	void ajouterArrivant();
	void retirerArrivant();
	void ajouterPartant();
	void retirerPartant();
};

