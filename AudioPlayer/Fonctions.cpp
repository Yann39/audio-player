#include "Fonctions.h"
#include "stdafx.h"

//=====================================
//=== Convertit un CString en char* ===
//=====================================
void CStringToChar(char* _c, CString _cs)
{
	strcpy_s(_c,2048,(const char*)_cs.GetBuffer(_cs.GetLength()));
}

//===========================================================================
//=== R�cup�re le nom et le chemin du fichier musical dans le fichier txt ===
//===========================================================================
bool RecupNomEtChemin(CString* _csNom, CString* _csChemin, CString _csChaineSrc)
{
	bool bRes=true;
	//recherche du caract�re de tabulation
	int iPosTab=_csChaineSrc.Find('\t');
	//longueur de la cha�ne source	
	int iLgChaineSrc=_csChaineSrc.GetLength();	
	//si rien trouv�, on arr�te
	if(iPosTab==-1 || iLgChaineSrc<3)	
		return(false);
	//partie � gauche de tab : nom
	*_csNom=_csChaineSrc.Left(iPosTab);
	//partie � droite de tab : chemin
	*_csChemin=_csChaineSrc.Right(iLgChaineSrc-iPosTab-1);
	return bRes;
}

//=================================================
//=== Gen�re un nombre al�atoire entre 0 et max ===
//=================================================
int NbAleatoire(unsigned int max)
{
	float val;
	// on appele la fonction rand(), elle retourne un int entre 0 et la constante RAND_MAX
	// il suffit de diviser rand() par RAND_MAX pour avoir un nombre entre 0 et 1.
	// il faut penser � caster rand() et RAND_MAX en float sinon on aura une division entiere
	// dont le resultat sera quasiment tout le temps 0;
	// ensuite on le multiplie par max pour avoir un nombe aleatoire entre 0 et max
	val=(float)rand()/(float)RAND_MAX*max;
	// on arrondi la valeur de val � l'entier le plus proche
	// si la partie decimale de val est > 5, alors on retourne la partie entiere de val +1
	// sinon on retourne la partie entiere de val
	if(val-(int)val>.5)
		return (int)val+1;
	else
		return (int)val;
}
