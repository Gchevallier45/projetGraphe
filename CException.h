#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <string>
#include <iostream>

// --------------------------------------------------------------------------------------
// Classe CException
// Cette classe permet d'ajouter le support des exceptions à notre programme
// --------------------------------------------------------------------------------------

using namespace std;

class CException
{
private:
    string sEXCErreur;
public:
    CException();
    CException(string sErreur);
	string EXCObtenirMessage();
	friend ostream& operator<<(ostream& os, CException& EXCParam);
};

#endif // CEXCEPTION_H