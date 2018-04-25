#include "stdafx.h"
#include "CException.h"

// --------------------------------------------------------------------------------------
// Classe CException
// Cette classe permet d'ajouter le support des exceptions à notre programme
// --------------------------------------------------------------------------------------

using namespace std;

/**
 * Construit une CException avec un message vide
 */
CException::CException(){
    sEXCErreur = "";
}

/**
 * Construit une CException depuis une chaine de caractère
 * @param sErreur le chaine de caractères contenant le message d'erreur
 */
CException::CException(string sErreur) {
	sEXCErreur = sErreur;
}

/**
 * Retourne une chaine de caractères contenant le message d'une CException
 * @return sEXCErreur la chaine de caractères contenant le message d'erreur
 */
string CException::EXCObtenirMessage() {
	return sEXCErreur;
}

/**
* Surcharge de l'opérateur << pour afficher l'exception à l'écran
* @param os le flux dans lequel écrire les données de l'exception
* @param EXCParam l'exception à afficher
* @return le flux passé en paramètre
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
