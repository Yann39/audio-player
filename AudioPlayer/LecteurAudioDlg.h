// LecteurAudioDlg.h : fichier d'en-tête
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "MaintientBoutonAvancer.h"
#include "MaintientBoutonReculer.h"
#include "ModifSliderAvancement.h"
#include <string>

// boîte de dialogue CLecteurAudioDlg
class CLecteurAudioDlg : public CDialog
{
// Construction
public:
	CLecteurAudioDlg(CWnd* pParent = NULL);	// constructeur standard
	CFonctionsFmod FonctionsFmodEnCours;

// Données de boîte de dialogue
	enum { IDD = IDD_LecteurAudio_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV

// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void OnTimer(UINT nIDEvent);
	bool JouerPiste(void);
	int iNiveauVolume; //niveau du volume
	bool enDeplacement; //pour savoir si on est en train de déplacer le curseur d'avancement
public:
	afx_msg void OnBnClickedBtnJouer();
	afx_msg void OnBnClickedBtnPause();
	afx_msg void OnBnClickedBtnArret();
	afx_msg void OnBnClickedBtnPrecedent();
	afx_msg void OnBnClickedBtnSuivant();
	afx_msg void OnBnClickedBtnAvant();
	afx_msg void OnBnClickedBtnArriere();
	afx_msg void OnBnClickedBtnAjouterUnTitre();
	afx_msg void OnBnClickedBtnEnleverLeTitreSelectionne();
	afx_msg void OnBnClickedBtnAide();
	afx_msg void OnBnClickedBtnQuitter();
	afx_msg void OnBnClickedBtnTrierAz();
	afx_msg void OnBnClickedBtnTrierZa();
	afx_msg void OnBnClickedBtnRetirerTout();
	afx_msg void OnBnClickedBtnSauvegarder();
	afx_msg void OnBnClickedBtnCharger();
	afx_msg void OnBnClickedLectureBoucle();
	afx_msg void OnBnClickedLectureHasard();
	afx_msg void OnBnClickedPasserAutoSuiv();
	afx_msg void OnBnClickedBtnUp();
	afx_msg void OnBnClickedBtnDown();
	afx_msg void OnLButtonDown();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNMCustomdrawVolume(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureAvancement(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureVolume(NMHDR *pNMHDR, LRESULT *pResult);
public:
	CBitmapButton btnArret;
	CBitmapButton btnPrecedent;
	CBitmapButton btnSuivant;
	CBitmapButton btnPause;
	CBitmapButton btnAjouterTitre;
	CBitmapButton btnEnleverTitre;
	CBitmapButton btnTrierAz;
	CBitmapButton btnTrierZa;
	CBitmapButton btnUp;
	CBitmapButton btnDown;
	CBitmapButton btnJouer;
	CBitmapButton btnQuitter;
	CBitmapButton btnRetirerTout;
	CBitmapButton btnCharger;
	CBitmapButton btnSauvegarder;
	CBitmapButton btnAide;
public:
	MaintientBoutonReculer btnArriere;
	MaintientBoutonAvancer btnAvant;
public:
	CButton btnLectureAuto;
	CButton btnLectureBoucle;
	CButton btnLectureHasard;
public:
	CListBox clbListeDeLecture;
	CListBox clbListeDeLectureDossier;
	CListBox clbListeTrieCache;
public:
	CStatic libAvancement;
public:
	CSliderCtrl cslSliderVolume;
public:
	ModifSliderAvancement cslSliderAvancement;
};
