#include "stdafx.h"
#include "CException.h"

// --------------------------------------------------------------------------------------
// Classe CException
// Cette classe permet d'ajouter le support des exceptions � notre programme
// --------------------------------------------------------------------------------------

using namespace std;

/**
 * Construit une CException avec un message vide
 */
CException::CException(){
    sEXCErreur = "";
}

/**
 * Construit une CException depuis une chaine de caract�re
 * @param sErreur le chaine de caract�res contenant le message d'erreur
 */
CException::CException(string sErreur) {
	sEXCErreur = sErreur;
}

/**
 * Retourne une chaine de caract�res contenant le message d'une CException
 * @return sEXCErreur la chaine de caract�res contenant le message d'erreur
 */
string CException::EXCObtenirMessage() {
	return sEXCErreur;
}

/**
* Surcharge de l'op�rateur << pour afficher l'exception � l'�cran
* @param os le flux dans lequel �crire les donn�es de l'exception
* @param EXCParam l'exception � afficher
* @return le flux pass� en param�tre
*/
ostream & operator<<(ostream & os, CException & EXCParam)
{
	if (EXCParam.EXCObtenirMessage().length() != 0) {
		os << "Exception : " << EXCParam.EXCObtenirMessage() << endl;
	}
	else {
		os << "Exception inconnue." << endl;
	}
	return os;
}
