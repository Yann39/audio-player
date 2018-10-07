#pragma once
#include "afx.h"
/*
class CFonctionsFmod:
	public CObject // Dérivation de CObject pour tenir dans un CObArray
*/
class CFonctionsFmod 
{

//
// Constructeur / Destructeur
//
public:
	CFonctionsFmod(void);
public:
	~CFonctionsFmod(void);
//
// Données
//
private:
	FMOD::System*	system;		// Interface avec le matériel (gestion carte son, pilotes, etc)
	FMOD::Sound*	sound;		// Jouer les fichiers musicaux  (play/pause/stop, etc)
	FMOD::Channel*	channel;	// Manipuler la piste (modifier le volume sonore, nb. de canaux, etc)
	CString			csCheminFichierSon;	// Chemin du fichier musical
	bool			bEnPause;	// Lecture en pause ou non
//
// Méthodes
//
protected:
	int iInitialisation(void);
public:
	void ChargerCheminFichier(CString);
	void Arret(void);
	int JouerTitre(void);
	int JouerTitre(CString cCheminTitre);
	void ReglerVolume(int iVolume);
	void ReglerVitesse(float Vitesse);
	void PauseOuReprise(void);
	unsigned int GetDureeTitre(void);
	unsigned int GetPositionDansTitre(void);
	void uiSetPositionDansTitre(unsigned int pos);
	bool EcouteEnCours(void);
	bool EstEnPause(void);
};
