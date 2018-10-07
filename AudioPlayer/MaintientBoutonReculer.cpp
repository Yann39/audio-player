#include "StdAfx.h"
#include "MaintientBoutonReculer.h"
#include "LecteurAudio.h"
#include "LecteurAudioDlg.h"

MaintientBoutonReculer::MaintientBoutonReculer(void)
{
}

MaintientBoutonReculer::~MaintientBoutonReculer(void)
{
}

BEGIN_MESSAGE_MAP(MaintientBoutonReculer, CBitmapButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

void MaintientBoutonReculer::OnLButtonDown(UINT nFlags, CPoint point)
{
	CLecteurAudioDlg* pParent = (CLecteurAudioDlg*)GetParent();
	pParent->FonctionsFmodEnCours.ReglerVitesse(-120000);
	CButton::OnLButtonDown(nFlags, point);
}

void MaintientBoutonReculer::OnLButtonUp(UINT nFlags, CPoint point)
{
	CLecteurAudioDlg* pParent = (CLecteurAudioDlg*)GetParent();
	pParent->FonctionsFmodEnCours.ReglerVitesse(44000);
	CButton::OnLButtonDown(nFlags, point);
}
