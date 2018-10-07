#include "StdAfx.h"
#include "ModifSliderAvancement.h"
#include "LecteurAudio.h"
#include "LecteurAudioDlg.h"

ModifSliderAvancement::ModifSliderAvancement(void)
{
}

ModifSliderAvancement::~ModifSliderAvancement(void)
{
}
BEGIN_MESSAGE_MAP(ModifSliderAvancement, CSliderCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

void ModifSliderAvancement::OnLButtonDown(UINT nFlags, CPoint point)
{
	CLecteurAudioDlg* pParent = (CLecteurAudioDlg*)GetParent();
	//on arrête de mettre à jour la position du curseur
	pParent->enDeplacement = true;
	CSliderCtrl::OnLButtonDown(nFlags, point);
}

void ModifSliderAvancement::OnLButtonUp(UINT nFlags, CPoint point)
{
	CLecteurAudioDlg* pParent = (CLecteurAudioDlg*)GetParent();
	//On calcul la nouvelle position dans le titre et on l'applique
	int posTitre = (pParent->cslSliderAvancement.GetPos()*pParent->FonctionsFmodEnCours.GetDureeTitre())/pParent->cslSliderAvancement.GetRangeMax();
	pParent->FonctionsFmodEnCours.uiSetPositionDansTitre(posTitre);
	//on peut remttre à jour la position du curseur dans le timer
	pParent->enDeplacement = false;
	CSliderCtrl::OnLButtonUp(nFlags, point);
}
