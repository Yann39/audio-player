#include "StdAfx.h"
#include "FonctionsFmod.h"

CFonctionsFmod::CFonctionsFmod(void)
{
	bEnPause=false;
}

CFonctionsFmod::~CFonctionsFmod(void)
{	
	system->release();
}

//=================================================
//=== Pour charger le chemin d'acc�s au fichier ===
//=================================================
void CFonctionsFmod::ChargerCheminFichier(CString cCheminFichier)
{
	csCheminFichierSon=cCheminFichier;
}


//===========================================
//=== Initialisation : Mat�riel & pilotes ===
//===========================================
int CFonctionsFmod::iInitialisation(void)
{
	int iRes=RES_OK;
	FMOD_RESULT fmResult;
	const char* cCheminFichierSon;
	
	// V�rif. de la longueur du nom/chemin de fichier
	if(csCheminFichierSon.GetLength()<2048)
		cCheminFichierSon = (CT2A)csCheminFichierSon;
	else
		return(RES_FICHIER_CHEMIN_TROP_LONG);

	// Initialisation FModex
	fmResult = FMOD::System_Create(&system);
	if(fmResult != FMOD_OK)
		return(RES_ERR_FMODSystem_Create);

	// Initialisation du syst�me sonore
	fmResult = system->init(100, FMOD_INIT_NORMAL, 0);
	if(fmResult != FMOD_OK)
		return(RES_ERR_FMODinit);

	// On charge le fichier musical
	fmResult = system->createSound(cCheminFichierSon, FMOD_SOFTWARE, 0, &sound);
	if(fmResult != FMOD_OK)
		return(RES_FICHIER_MAUVAIS_FORMAT);

	return iRes;
}


//==============================================
//=== Arr�te la lecture et lib�re la m�moire ===
//==============================================
void CFonctionsFmod::Arret(void)
{
	system->release();
}


//=======================================
//=== Joue un fichier depuis le d�but ===
//=======================================
int CFonctionsFmod::JouerTitre(void)
{
	FMOD_RESULT fmResult;
	if(this->iInitialisation()==RES_OK)
	{
		// On joue le fichier musical
		fmResult = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);	
		if(fmResult == FMOD_OK)
		{
			bEnPause=false;
			return(RES_OK);
		}
	}
	return(this->iInitialisation());
}


//==========================================================
//=== Joue un fichier pass� en param�tre depuis le d�but ===
//==========================================================
int CFonctionsFmod::JouerTitre(CString cCheminTitre)
{
	this->ChargerCheminFichier(cCheminTitre);
	return(this->JouerTitre());
}


//=======================
//=== R�gle le volume ===
//=======================
void CFonctionsFmod::ReglerVolume(int iVolume)
{
	channel->setVolume(iVolume/(float)100.0);
}

//========================
//=== R�gle la vitesse ===
//========================
void CFonctionsFmod::ReglerVitesse(float Vitesse)
{
	channel->setFrequency(Vitesse);
}

//========================================
//=== R�cup�re la dur�e du titre en ms ===
//========================================
unsigned int CFonctionsFmod::GetDureeTitre(void)
{	unsigned int uiRes=0;
	sound->getLength(&uiRes,FMOD_TIMEUNIT_MS);
	return(uiRes);
}


//================================================
//=== R�cup�re la position dans le titre en ms ===
//================================================
unsigned int CFonctionsFmod::GetPositionDansTitre(void)
{	unsigned int uiRes=0;
	channel->getPosition(&uiRes,FMOD_TIMEUNIT_MS);
	return(uiRes);
}

//=================================================================
//=== Permet de se placer � une certaine position dans le titre ===
//=================================================================
void CFonctionsFmod::uiSetPositionDansTitre(unsigned int pos)
{
	channel->setPosition(pos,FMOD_TIMEUNIT_MS);
}


//==============================================================
//=== Permet de savoir si le fichier est en cours de lecture ===
//==============================================================
bool CFonctionsFmod::EcouteEnCours(void)
{	
	bool bRes=false;
	channel->isPlaying(&bRes);
	return(bRes);
}


//===================================================
//=== Permet de savoir si le fichier est en pause ===
//===================================================
bool CFonctionsFmod::EstEnPause(void)
{	
	return(bEnPause);
}


//============================================================
//=== Permet de mettre en pause ou de reprendre la lecture ===
//============================================================
void CFonctionsFmod::PauseOuReprise(void)
{	
	bEnPause=!bEnPause;
	channel->setPaused(EstEnPause());
}