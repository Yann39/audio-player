#include "StdAfx.h"
#include "MaintientBoutonAvancer.h"
#include "LecteurAudio.h"
#include "LecteurAudioDlg.h"

MaintientBoutonAvancer::MaintientBoutonAvancer(void)
{
}

MaintientBoutonAvancer::~MaintientBoutonAvancer(void)
{
}

BEGIN_MESSAGE_MAP(MaintientBoutonAvancer, CBitmapButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

void MaintientBoutonAvancer::OnLButtonDown(UINT nFlags, CPoint point)
{
	CLecteurAudioDlg* pParent = (CLecteurAudioDlg*)GetParent();
	pParent->FonctionsFmodEnCours.ReglerVitesse(120000);
	CButton::OnLButtonDown(nFlags, point);
}

void MaintientBoutonAvancer::OnLButtonUp(UINT nFlags, CPoint point)
{
	CLecteurAudioDlg* pParent = (CLecteurAudioDlg*)GetParent();
	pParent->FonctionsFmodEnCours.ReglerVitesse(44100);
	CButton::OnLButtonUp(nFlags, point);
}