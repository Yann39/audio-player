// LecteurAudioDlg.cpp : fichier d'impl�mentation

#include "stdafx.h"
#include "LecteurAudio.h"
#include "LecteurAudioDlg.h"
#include <string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma region Variables globales

int					NumTitreEnCours;
unsigned int		DureeFonctionsFmodEnCours;

#pragma endregion

#pragma region Bo�te de dialogue A propos de
// Bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de'
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Donn�es de bo�te de dialogue
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
protected:
	DECLARE_MESSAGE_MAP()

};


CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()
#pragma endregion


// bo�te de dialogue CLecteurAudioDlg

CLecteurAudioDlg::CLecteurAudioDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLecteurAudioDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLecteurAudioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_VOLUME, iNiveauVolume);
	DDV_MinMaxInt(pDX, iNiveauVolume, 0, 100);
	DDX_Control(pDX, IDC_VOLUME, cslSliderVolume);
	DDX_Control(pDX, ID_BTN_ARRET, btnArret);
	DDX_Control(pDX, ID_BTN_PRECEDENT, btnPrecedent);
	DDX_Control(pDX, ID_BTN_SUIVANT, btnSuivant);
	DDX_Control(pDX, ID_BTN_PAUSE, btnPause);
	DDX_Control(pDX, ID_BTN_AJOUTER_UN_TITRE, btnAjouterTitre);
	DDX_Control(pDX, ID_BTN_ENLEVER_LE_TITRE_SELECTIONNE, btnEnleverTitre);
	DDX_Control(pDX, ID_BTN_JOUER, btnJouer);
	DDX_Control(pDX, ID_BTN_QUITTER, btnQuitter);
	DDX_Control(pDX, IDC_BTN_AVANT, btnAvant);
	DDX_Control(pDX, IDC_BTN_ARRIERE, btnArriere);
	DDX_Control(pDX, ID_BTN_AIDE, btnAide);
	DDX_Control(pDX, IDC_LIST1, clbListeDeLecture);
	DDX_Control(pDX, IDC_LIST2, clbListeDeLectureDossier);
	DDX_Control(pDX, IDC_LIST3, clbListeTrieCache);
	DDX_Control(pDX, IDC_AVANCEMENT, cslSliderAvancement);
	DDX_Control(pDX, IDC_PASSER_AUTO_SUIV, btnLectureAuto);
	DDX_Control(pDX, IDC_LIB_AVANCEMENT, libAvancement);
	DDX_Control(pDX, IDC_LECTURE_BOUCLE, btnLectureBoucle);
	DDX_Control(pDX, IDC_LECTURE_HASARD, btnLectureHasard);
	DDX_Control(pDX, ID_BTN_RETIRER_TOUT, btnRetirerTout);
	DDX_Control(pDX, IDC_BTN_CHARGER, btnCharger);
	DDX_Control(pDX, IDC_BTN_SAUVEGARDER, btnSauvegarder);
	DDX_Control(pDX, IDC_BTN_TRIER_AZ, btnTrierAz);
	DDX_Control(pDX, IDC_BTN_TRIER_ZA, btnTrierZa);
	DDX_Control(pDX, IDC_BTN_UP, btnUp);
	DDX_Control(pDX, IDC_BTN_DOWN, btnDown);
}

BEGIN_MESSAGE_MAP(CLecteurAudioDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(ID_BTN_JOUER, &CLecteurAudioDlg::OnBnClickedBtnJouer)
	ON_BN_CLICKED(ID_BTN_PAUSE, &CLecteurAudioDlg::OnBnClickedBtnPause)
	ON_BN_CLICKED(ID_BTN_ARRET, &CLecteurAudioDlg::OnBnClickedBtnArret)
	ON_BN_CLICKED(ID_BTN_PRECEDENT, &CLecteurAudioDlg::OnBnClickedBtnPrecedent)
	ON_BN_CLICKED(ID_BTN_SUIVANT, &CLecteurAudioDlg::OnBnClickedBtnSuivant)
	ON_BN_CLICKED(IDC_BTN_AVANT, &CLecteurAudioDlg::OnBnClickedBtnAvant)
	ON_BN_CLICKED(IDC_BTN_ARRIERE, &CLecteurAudioDlg::OnBnClickedBtnArriere)
	ON_BN_CLICKED(ID_BTN_AJOUTER_UN_TITRE, &CLecteurAudioDlg::OnBnClickedBtnAjouterUnTitre)
	ON_BN_CLICKED(ID_BTN_ENLEVER_LE_TITRE_SELECTIONNE, &CLecteurAudioDlg::OnBnClickedBtnEnleverLeTitreSelectionne)
	ON_BN_CLICKED(ID_BTN_AIDE, &CLecteurAudioDlg::OnBnClickedBtnAide)
	ON_BN_CLICKED(ID_BTN_QUITTER, &CLecteurAudioDlg::OnBnClickedBtnQuitter)
	ON_BN_CLICKED(IDC_BTN_SAUVEGARDER, &CLecteurAudioDlg::OnBnClickedBtnSauvegarder)
	ON_BN_CLICKED(IDC_BTN_CHARGER, &CLecteurAudioDlg::OnBnClickedBtnCharger)
	ON_BN_CLICKED(IDC_LECTURE_BOUCLE, &CLecteurAudioDlg::OnBnClickedLectureBoucle)
	ON_BN_CLICKED(IDC_LECTURE_HASARD, &CLecteurAudioDlg::OnBnClickedLectureHasard)
	ON_BN_CLICKED(IDC_PASSER_AUTO_SUIV, &CLecteurAudioDlg::OnBnClickedPasserAutoSuiv)
	ON_BN_CLICKED(IDC_BTN_TRIER_AZ, &CLecteurAudioDlg::OnBnClickedBtnTrierAz)
	ON_BN_CLICKED(IDC_BTN_TRIER_ZA, &CLecteurAudioDlg::OnBnClickedBtnTrierZa)
	ON_BN_CLICKED(IDC_BTN_RETIRER_TOUT, &CLecteurAudioDlg::OnBnClickedBtnRetirerTout)
	ON_BN_CLICKED(IDC_BTN_UP, &CLecteurAudioDlg::OnBnClickedBtnUp)
	ON_BN_CLICKED(IDC_BTN_DOWN, &CLecteurAudioDlg::OnBnClickedBtnDown)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_VOLUME, &CLecteurAudioDlg::OnNMReleasedcaptureVolume)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_AVANCEMENT, &CLecteurAudioDlg::OnNMReleasedcaptureAvancement)
END_MESSAGE_MAP()


// gestionnaires de messages pour CLecteurAudioDlg

BOOL CLecteurAudioDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Ajouter l'�l�ment de menu "� propos de..." au menu Syst�me.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes syst�me.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// D�finir l'ic�ne de cette bo�te de dialogue. L'infrastructure effectue cela automatiquement
	// lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	// Association des images aux �tats des boutons (BitmapButton)
	btnQuitter.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP4, IDB_BITMAP2, IDB_BITMAP1);
	btnAide.LoadBitmaps(IDB_BITMAP11, IDB_BITMAP12, IDB_BITMAP10, IDB_BITMAP9);
	btnPrecedent.LoadBitmaps(IDB_BITMAP15, IDB_BITMAP16, IDB_BITMAP14, IDB_BITMAP13);
	btnSuivant.LoadBitmaps(IDB_BITMAP19, IDB_BITMAP20, IDB_BITMAP18, IDB_BITMAP17);
	btnPause.LoadBitmaps(IDB_BITMAP28, IDB_BITMAP29, IDB_BITMAP27, IDB_BITMAP26);
	btnArret.LoadBitmaps(IDB_BITMAP31, IDB_BITMAP32, IDB_BITMAP30, IDB_BITMAP33);
	btnAvant.LoadBitmaps(IDB_BITMAP7, IDB_BITMAP8, IDB_BITMAP6, IDB_BITMAP5);
	btnArriere.LoadBitmaps(IDB_BITMAP23, IDB_BITMAP24, IDB_BITMAP22, IDB_BITMAP21);
	btnJouer.LoadBitmaps(IDB_BITMAP37, IDB_BITMAP34, IDB_BITMAP36, IDB_BITMAP35);
	btnAjouterTitre.LoadBitmaps(IDB_BITMAP40, IDB_BITMAP41, IDB_BITMAP39, IDB_BITMAP38);
	btnEnleverTitre.LoadBitmaps(IDB_BITMAP48, IDB_BITMAP49, IDB_BITMAP47, IDB_BITMAP46);
	btnRetirerTout.LoadBitmaps(IDB_BITMAP52, IDB_BITMAP53, IDB_BITMAP51, IDB_BITMAP50);
	btnCharger.LoadBitmaps(IDB_BITMAP44, IDB_BITMAP45, IDB_BITMAP43, IDB_BITMAP42);
	btnSauvegarder.LoadBitmaps(IDB_BITMAP56, IDB_BITMAP57, IDB_BITMAP55, IDB_BITMAP54);
	btnTrierAz.LoadBitmaps(IDB_BITMAP60, IDB_BITMAP61, IDB_BITMAP59, IDB_BITMAP58);
	btnTrierZa.LoadBitmaps(IDB_BITMAP64, IDB_BITMAP65, IDB_BITMAP63, IDB_BITMAP62);
	btnUp.LoadBitmaps(IDB_BITMAP68, IDB_BITMAP69, IDB_BITMAP67, IDB_BITMAP66);
	btnDown.LoadBitmaps(IDB_BITMAP72, IDB_BITMAP73, IDB_BITMAP71, IDB_BITMAP70);

	// Initialisation du slider de son
	cslSliderVolume.SetRangeMax(100, true);
	cslSliderVolume.SetRangeMin(0, true);
	cslSliderVolume.SetPos(50);

	// initialisation du slider d'avancement dans le fichier misical
	cslSliderAvancement.SetRangeMax(100, true);
	cslSliderAvancement.SetRangeMin(0, true);
	cslSliderAvancement.SetPos(0);

	// Initialisation de l'�tat des contr�les
	btnJouer.EnableWindow(false);
	btnAjouterTitre.EnableWindow(true);
	btnQuitter.EnableWindow(true);
	btnAide.EnableWindow(true);
	btnEnleverTitre.EnableWindow(false);
	btnRetirerTout.EnableWindow(false);
	btnPrecedent.EnableWindow(false);
	btnSuivant.EnableWindow(false);
	btnSauvegarder.EnableWindow(false);
	btnPause.EnableWindow(false);
	btnArret.EnableWindow(false);
	btnAvant.EnableWindow(false);
	btnArriere.EnableWindow(false);
	btnTrierAz.EnableWindow(false);
	btnTrierZa.EnableWindow(false);
	btnUp.EnableWindow(false);
	btnDown.EnableWindow(false);
	clbListeDeLecture.EnableWindow(true);
	clbListeDeLectureDossier.EnableWindow(true);
	cslSliderAvancement.EnableWindow(false);
	cslSliderVolume.EnableWindow(true);
	libAvancement.SetWindowText((CString)"00:00 / 00:00");
	enDeplacement = false;

	UpdateData(true); // MAJ fen�tre

	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

void CLecteurAudioDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		// D�tection de la fin de l'application
		if (nID == SC_CLOSE)	FonctionsFmodEnCours.Arret();

		CDialog::OnSysCommand(nID, lParam);
	}
}

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne. Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CLecteurAudioDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
// la fen�tre r�duite.
HCURSOR CLecteurAudioDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLecteurAudioDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// on est plus sur les bouton avance rapide ou retour rapide, on remet donc la musique � sa fr�quence d'origine
	FonctionsFmodEnCours.ReglerVitesse(44100);
}

//=========================================================
//=== Fonction permettant de jouer un titre de la liste ===
//=========================================================
bool CLecteurAudioDlg::JouerPiste(void)
{
	//si pas de s�lection, alors on s�lectionne le premier titre dans la liste
	if (NumTitreEnCours < 1)
		NumTitreEnCours = 0;
	clbListeDeLecture.SetCurSel(NumTitreEnCours);
	CString csTitreAJouer;
	//on r�cup�re le chemin du fichier � jouer
	clbListeDeLectureDossier.GetText(NumTitreEnCours, csTitreAJouer);
	//on charge le fichier et on l'arr�te
	FonctionsFmodEnCours.ChargerCheminFichier(csTitreAJouer);
	size_t start_pos = 0;
	FonctionsFmodEnCours.Arret();
	//on tente de lire le fichier
	int res_lecture = FonctionsFmodEnCours.JouerTitre();
	//si le d�marrage de la lecture du fichier s'est bien pass�
	if (res_lecture == RES_OK) {
		//on r�gle le volume en fonction du slider de son
		FonctionsFmodEnCours.ReglerVolume(cslSliderVolume.GetPos());
		//on configure les bornes du slider d'avancement
		DureeFonctionsFmodEnCours = 0;
		DureeFonctionsFmodEnCours = FonctionsFmodEnCours.GetDureeTitre();
		DureeFonctionsFmodEnCours /= 100;
		cslSliderAvancement.SetRangeMax(DureeFonctionsFmodEnCours, true);
		cslSliderAvancement.SetRangeMin(0, true);
		cslSliderAvancement.SetPos(0);

		//on d�marre le timer pour afficher la progression de la piste audio (on actualise toutes les 1s)
		KillTimer(ID_AVANCEMENT_PISTE_TIMER);
		SetTimer(ID_AVANCEMENT_PISTE_TIMER, 1000, NULL);
		return(true);
	}
	//erreur lors de la tentative de lecture du fichier
	else {
		//gestion des erreurs
		CString csErrMsg, csTitreMsg;
		switch (res_lecture) {
		case RES_FICHIER_MAUVAIS_FORMAT:
			csErrMsg = "Erreur d'initialisation, le fichier sonore semble �tre incompatible.";
			csTitreMsg = "Erreur";
			break;
		case RES_FICHIER_CHEMIN_TROP_LONG:
			csErrMsg = "Erreur, le chemin du fichier sonore ne doit pas d�passer 2048 caract�res.";
			csTitreMsg = "Erreur";
			break;
		case RES_ERR_FMODSystem_Create:
			csErrMsg = "Erreur d'initialisation, le syst�me sonore ne s'est pas initialis� (�tape 'create').";
			csTitreMsg = "Erreur";
			break;
		case RES_ERR_FMODinit:
			csErrMsg = "Erreur d'initialisation, le syst�me sonore ne s'est pas initialis� (�tape 'init')";
			csTitreMsg = "Erreur";
			break;
		case RES_ERR_FMODcreateSound:
			csErrMsg = "Erreur d'initialisation, le fichier sonore est introuvable ou incompatible.";
			csTitreMsg = "Erreur";
			break;
		case Res_ERR_FMODplaySound:
			csErrMsg = "Erreur de lecture, impossible de trouver le fichier sonore '";
			csErrMsg += csTitreAJouer;
			csErrMsg += "'";
			csTitreMsg = "Erreur";
			break;
		default:
			csErrMsg = "Erreur inconnue. R�essayez et contactez le support technique.";
			csTitreMsg = "Erreur";
		}
		MessageBox(csErrMsg, csTitreMsg, MB_OK);
	}
	return(false);
}

//================================================================
//=== Timer permettant d'afficher l'avancement dans la musique ===
//================================================================
void CLecteurAudioDlg::OnTimer(UINT nIDEvent)
{
	//s�lection du Timer
	if (nIDEvent == ID_AVANCEMENT_PISTE_TIMER) {
		//on actualise l'avancement que si le titre est en cours de lecture
		if (!FonctionsFmodEnCours.EstEnPause()) {
			//si on est pas encore � la fin de la musique
			if (FonctionsFmodEnCours.EcouteEnCours()) {
				//on r�cup�re la position dans le titre en dixi�me de secondes
				unsigned int uiPositionPiste = FonctionsFmodEnCours.GetPositionDansTitre() / 100;
				//initialise le slider en fonction de la dur�e du titre
				cslSliderAvancement.SetRangeMax(DureeFonctionsFmodEnCours, true);
				cslSliderAvancement.SetRangeMin(0, true);
				if (enDeplacement == false)
					cslSliderAvancement.SetPos(uiPositionPiste);
				//on calcul la position dans le titre
				CString csAffPosSurDuree;
				CTime ctTempsPos(uiPositionPiste / 10), ctTempsDuree(DureeFonctionsFmodEnCours / 10);;
				csAffPosSurDuree = ctTempsPos.Format("%M:%S / ");
				//on calcul la dur�e du titre dans le bon format
				csAffPosSurDuree += ctTempsDuree.Format("%M:%S");
				//on affiche la dur�e et la position dans le titre
				libAvancement.SetWindowTextW((CString)csAffPosSurDuree);
			}
			//fin de la musique, on passe au titre suivant
			else {
				//si le bouton 'lecture au hasard' est coch�, on lit un titre au hasard dans la liste
				if (btnLectureHasard.GetCheck() == BST_CHECKED) {
					int PisteAleatoire = NbAleatoire(clbListeDeLecture.GetCount());
					clbListeDeLecture.SetCurSel(PisteAleatoire);
					this->OnBnClickedBtnJouer();
				}
				//si le bouton 'lecture en boucle' est coch�, on relit le titre que l'on vient de jouer
				else if (btnLectureBoucle.GetCheck() == BST_CHECKED)
					this->OnBnClickedBtnJouer();
				//si l'on n'est pas d�j� � la fin de la liste des titres et que le bouton 'passage automatique' est coch�, on joue le fichier suivant
				else if (NumTitreEnCours < clbListeDeLecture.GetCount() - 1 && (btnLectureAuto.GetCheck() == BST_CHECKED))
					this->OnBnClickedBtnSuivant();
				//sinon on arr�te la lecture des titres
				else
					this->OnBnClickedBtnArret();
			}
		}
	}
}

//========================================
//=== Clic sur bouton Ajouter un titre ===
//========================================
void CLecteurAudioDlg::OnBnClickedBtnAjouterUnTitre()
{
	CString csFichierAAjouter;
	CString csCheminFichierAAjouter;
	//on sp�cifie les types de fichiers accept�s
	CString csFiltreFichiers = "Fichier sonore MP3 (*.mp3)|*.mp3|";
	csFiltreFichiers += "Fichier sonore OGG Vorbis (*.ogg)|*.ogg|";
	csFiltreFichiers += "Fichier sonore RAW (*.raw)|*.raw|";
	csFiltreFichiers += "Fichier sonore WAV (*.wav)|*.wav|";
	csFiltreFichiers += "Fichier sonore WMA (*.wma)|*.wma|";
	csFiltreFichiers += "Tout type de fichier (*.*)|*.*||";
	CFileDialog fenOuvrirFichier(true, NULL, NULL, OFN_OVERWRITEPROMPT, csFiltreFichiers);
	//si un fichier est s�lectionn�
	if (fenOuvrirFichier.DoModal() == IDOK) {
		//on r�cup�re le nom du fichier
		csFichierAAjouter = fenOuvrirFichier.GetFileName();
		csCheminFichierAAjouter = fenOuvrirFichier.GetPathName();
		//on v�rifie si le fichier est bien accessible
		if (0 <= (INT_PTR)GetFileAttributesW((CString)csCheminFichierAAjouter)) {
			//on ajoute le titre et les chemin dans les ListBox
			clbListeDeLecture.AddString((CString)csFichierAAjouter);
			clbListeDeLectureDossier.AddString(csCheminFichierAAjouter);
			//on autorise les diverses fonctions
			btnEnleverTitre.EnableWindow(true);
			btnJouer.EnableWindow(true);
			btnRetirerTout.EnableWindow(true);
			btnSauvegarder.EnableWindow(true);
			btnTrierAz.EnableWindow(true);
			btnTrierZa.EnableWindow(true);
			btnUp.EnableWindow(true);
			btnDown.EnableWindow(true);
			if (clbListeDeLecture.GetCount() > 1) {
				btnPrecedent.EnableWindow(true);
				btnSuivant.EnableWindow(true);
			}
		}
		else
			MessageBox((CString)"Le fichier est inaccessible.", (CString)"Erreur", MB_OK);
		//si le fichier est en cours de lecture, on ne peut pas appuyer sur lecture
		if (FonctionsFmodEnCours.EcouteEnCours())
			btnJouer.EnableWindow(false);
	}
}

//========================================
//=== Clic sur bouton Retirer un titre ===
//========================================
void CLecteurAudioDlg::OnBnClickedBtnEnleverLeTitreSelectionne()
{
	//r�cup�ration du num�ro de la ligne du titre � enlever
	int iLigneAEnlever = clbListeDeLecture.GetCurSel();
	//on l'enl�ve des deux listes 
	clbListeDeLecture.DeleteString(iLigneAEnlever);
	clbListeDeLectureDossier.DeleteString(iLigneAEnlever);
	//si la liste est vide, pas de lecture possible
	if (clbListeDeLecture.GetCount() < 1) {
		btnEnleverTitre.EnableWindow(false);
		btnJouer.EnableWindow(false);
		btnUp.EnableWindow(false);
		btnDown.EnableWindow(false);
		btnTrierAz.EnableWindow(false);
		btnTrierZa.EnableWindow(false);
		btnRetirerTout.EnableWindow(false);
		btnSauvegarder.EnableWindow(false);
		//si il n'y a plus de lecture en cours, on rend innaccessibles les autres boutons
		if (!FonctionsFmodEnCours.EcouteEnCours()) {
			btnArret.EnableWindow(false);
			btnPause.EnableWindow(false);
			btnAvant.EnableWindow(false);
			btnArriere.EnableWindow(false);
		}
	}
}

//===============================================
//=== Clic sur le bouton sauvegarder la liste ===
//===============================================
void CLecteurAudioDlg::OnBnClickedBtnSauvegarder()
{
	int iNbTitresSauv = 0;
	//bo�te de dialogue permettant de sauver la liste
	CFileDialog fenSauverListe(FALSE, (CString)"afl", NULL, OFN_HIDEREADONLY, (CString)"Fichier texte (*.txt)|*.txt||");
	//si l'utilisateur � appuy� sur OK
	if (fenSauverListe.DoModal() == IDOK) {
		//on r�cup�re le nom du fichier indiqu�
		CString csCheminFicSauv = fenSauverListe.GetPathName();
		//on cr�� le fichier (il est vid� s'il existait d�j�)
		CStdioFile csfFichier(csCheminFicSauv, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		//on �crit les titres
		int iNbTitres = clbListeDeLecture.GetCount();
		CString csCheminTitre, csBuffer;
		for (int i = 0; i < iNbTitres; i++, iNbTitresSauv++) {
			//r�cup�ration du nom de fichier
			clbListeDeLecture.GetText(i, csBuffer);
			csCheminTitre = csBuffer;
			csCheminTitre += "\t";
			//r�cup�ration du chemin du fichier
			clbListeDeLectureDossier.GetText(i, csBuffer);
			csCheminTitre += csBuffer;
			csCheminTitre += "\r\n";
			//on �crit dans le fichier texte
			csfFichier.WriteString(csCheminTitre);
		}
		//on ferme le fichier
		csfFichier.Close();
		//message indiquant le nombre de fichiers enregistr�s
		char cNbTitresSauv[256];
		CString csMessage = "";
		_itoa_s(iNbTitresSauv, cNbTitresSauv, 10);
		csMessage = cNbTitresSauv;
		if (iNbTitresSauv < 1)
			csMessage += " titre enregistr�";
		else
			csMessage += " titres enregistr�s";
		MessageBox(csMessage, (CString)"Sauvegarde", MB_OK);
	}
}

//============================================
//=== Clic sur le bouton charger une liste ===
//============================================
void CLecteurAudioDlg::OnBnClickedBtnCharger()
{
	CString csCheminFicCharg;
	CFileDialog fenOuvrirFichier(true, NULL, NULL, OFN_OVERWRITEPROMPT, (CString)"Fichiers texte (*.txt)|*.txt||");

	if (fenOuvrirFichier.DoModal() == IDOK) // Si un fichier est choisi
	{
		//on arr�te une �ventuelle lecture d'un titre
		CLecteurAudioDlg::OnBnClickedBtnArret();
		int iNbTitresValides = 0, iNbTitresInvalides = 0, iNbTitreTotal = 0;
		//on r�cup�re le chemin du fichier
		csCheminFicCharg = fenOuvrirFichier.GetPathName();
		//on vide les listes
		clbListeDeLecture.ResetContent();
		clbListeDeLectureDossier.ResetContent();
		//on ouvre le fichier
		CStdioFile csfFichier(csCheminFicCharg, CFile::modeRead | CFile::typeText);
		CString csCheminTitre, csNomTitre, csLigneLue;
		//on lit le fichier ligne par ligne et on r�cup�re les informations
		while (csfFichier.ReadString(csLigneLue)) {
			//on r�cup�re le nom et le chemin du fichier
			if (RecupNomEtChemin(&csNomTitre, &csCheminTitre, csLigneLue)) {
				//retire le retour chariot dans le chemin
				csCheminTitre.Remove('\r');
				//on ajoute dans les listes
				clbListeDeLecture.AddString(csNomTitre);
				clbListeDeLectureDossier.AddString(csCheminTitre);
				iNbTitresValides++;
			}
		}
		//si au moins un fichier a �t� ajouter, on rend les boutons n�c�ssaires disponibles
		if (iNbTitresValides > 0) {
			btnEnleverTitre.EnableWindow(true);
			btnDown.EnableWindow(true);
			btnUp.EnableWindow(true);
			btnTrierAz.EnableWindow(true);
			btnTrierZa.EnableWindow(true);
			btnRetirerTout.EnableWindow(true);
			btnSauvegarder.EnableWindow(true);
			btnSuivant.EnableWindow(true);
			btnPrecedent.EnableWindow(true);
		}
		else
			btnEnleverTitre.EnableWindow(false);
		//on affiche le nombre de fichiers charg�s
		char cMessage[256];
		_itoa_s(iNbTitresValides, cMessage, 10);
		CString csMessage = cMessage;
		csMessage += " titres charg�s";
		MessageBox(csMessage, (CString)"Chargement", MB_OK);
		//on ferme le fichier
		csfFichier.Close();
		//si on a au moins un titre dans la liste, on autorise le bouton lecture
		if (clbListeDeLecture.GetCount() >= 1)
			btnJouer.EnableWindow(true);
	}
}

//=======================================
//=== Clic sur le bouton Retirer tout ===
//=======================================
void CLecteurAudioDlg::OnBnClickedBtnRetirerTout()
{
	//on efface la liste
	clbListeDeLecture.ResetContent();
	//on rend inutilisable les boutons qui suivent
	btnEnleverTitre.EnableWindow(false);
	btnJouer.EnableWindow(false);
	btnUp.EnableWindow(false);
	btnDown.EnableWindow(false);
	btnTrierAz.EnableWindow(false);
	btnTrierZa.EnableWindow(false);
	btnSauvegarder.EnableWindow(false);
	btnRetirerTout.EnableWindow(false);
	btnSuivant.EnableWindow(false);
	btnPrecedent.EnableWindow(false);
	if (!FonctionsFmodEnCours.EcouteEnCours()) {
		btnArret.EnableWindow(false);
		btnPause.EnableWindow(false);
		btnAvant.EnableWindow(false);
		btnArriere.EnableWindow(false);
	}
}

void CLecteurAudioDlg::OnBnClickedBtnAvant() {
}

void CLecteurAudioDlg::OnBnClickedBtnArriere() {
}

//===============================
//=== Clic sur bouton lecture ===
//===============================
void CLecteurAudioDlg::OnBnClickedBtnJouer()
{
	//si la liste des titres n'est pas vide
	if (clbListeDeLecture.GetCount() != 0) {
		//on r�cup�re le titre en cours de lecture
		NumTitreEnCours = clbListeDeLecture.GetCurSel();
		btnJouer.EnableWindow(false);
		//on tente de jouer le titre
		if (CLecteurAudioDlg::JouerPiste()) {
			//si il y a plus d'un titre dans la liste
			if (clbListeDeLecture.GetCount() > 1) {
				//si il y a dans la liste au moins un titre qui suit le titre en cours de lecture, on peut faire suivant
				if (NumTitreEnCours < clbListeDeLecture.GetCount() - 1)
					btnSuivant.EnableWindow(true);
				else
					btnSuivant.EnableWindow(false);
				//si il y a dans la liste au moins un titre avant le titre en cours de lecture, on peut faire pr�c�dent
				if (NumTitreEnCours > 0)
					btnPrecedent.EnableWindow(true);
				else
					btnPrecedent.EnableWindow(false);
			}
			//il y a qu'un titre dans la liste, on ne peut faire ni suivant ni pr�c�dent
			else {
				btnPrecedent.EnableWindow(false);
				btnSuivant.EnableWindow(false);
			}
			btnPause.EnableWindow(true);
			btnArret.EnableWindow(true);
			btnAvant.EnableWindow(true);
			btnArriere.EnableWindow(true);
			cslSliderAvancement.EnableWindow(true);
		}
		else
			btnJouer.EnableWindow(true);
	}
}

//=============================
//=== Clic sur bouton pause ===
//=============================
void CLecteurAudioDlg::OnBnClickedBtnPause()
{
	//on met pause si le titre �tait en lecture et on met en lecture si le titre �tait en pause
	FonctionsFmodEnCours.PauseOuReprise();
	//on remet le volume � jour si l'utilisateur le modifie pendant la pause
	FonctionsFmodEnCours.ReglerVolume(cslSliderVolume.GetPos());
}

//=============================
//=== Clic sur bouton Arr�t ===
//=============================
void CLecteurAudioDlg::OnBnClickedBtnArret()
{
	//arr�t du timer et du fichier musical
	KillTimer(ID_AVANCEMENT_PISTE_TIMER);
	FonctionsFmodEnCours.Arret();
	//on remet le temps et la position du curseur d'avancement � z�ro
	libAvancement.SetWindowText((CString)"00:00 / 00:00");
	cslSliderAvancement.SetPos(cslSliderAvancement.GetRangeMin());
	//on ne peut plus mettre pause, arr�t, etc
	btnPause.EnableWindow(false);
	btnArret.EnableWindow(false);
	btnAvant.EnableWindow(false);
	btnArriere.EnableWindow(false);
	cslSliderAvancement.EnableWindow(false);
	//on peut rejouer un titre que si il y en a au moins un dans la liste
	btnJouer.EnableWindow(!(clbListeDeLecture.GetCount() < 1));
}

//=================================
//=== Clic sur bouton Pr�c�dent ===
//=================================
void CLecteurAudioDlg::OnBnClickedBtnPrecedent()
{
	//on arr�te la lecture
	this->OnBnClickedBtnArret();
	//on d�cr�mente la position du titre � jouer (si ce n'est pas le premier de la liste)
	NumTitreEnCours = clbListeDeLecture.GetCurSel();
	if (NumTitreEnCours != 0)
		NumTitreEnCours--;
	else
		btnPrecedent.EnableWindow(false);
	//on met le curseur sur le nouveau titre dans la liste
	clbListeDeLecture.SetCurSel(NumTitreEnCours);
	//on lance la lecture
	this->OnBnClickedBtnJouer();
}

//===============================
//=== Clic sur bouton Suivant ===
//===============================
void CLecteurAudioDlg::OnBnClickedBtnSuivant()
{
	//on arr�te la lecture
	this->OnBnClickedBtnArret();
	//on incr�mente la position du titre � jouer (si ce n'est pas le dernier de la liste)
	NumTitreEnCours = clbListeDeLecture.GetCurSel();
	if (NumTitreEnCours != clbListeDeLecture.GetCount() - 1)
		NumTitreEnCours++;
	else
		btnSuivant.EnableWindow(false);
	//on met le curseur sur le nouveau titre dans la liste
	clbListeDeLecture.SetCurSel(NumTitreEnCours);
	//on lance la lecture
	this->OnBnClickedBtnJouer();
}

//============================================
//=== Clic sur le bouton Lecture en boucle ===
//============================================
void CLecteurAudioDlg::OnBnClickedLectureBoucle()
{
	btnLectureHasard.SetCheck(0);
	btnLectureAuto.SetCheck(0);
}

//============================================
//=== Clic sur le bouton Lecture au hasard ===
//============================================
void CLecteurAudioDlg::OnBnClickedLectureHasard()
{
	btnLectureBoucle.SetCheck(0);
	btnLectureAuto.SetCheck(0);
}

//==============================================
//=== Clic sur le bouton Passage automatique ===
//==============================================
void CLecteurAudioDlg::OnBnClickedPasserAutoSuiv()
{
	btnLectureHasard.SetCheck(0);
	btnLectureBoucle.SetCheck(0);
}

//=======================================================
//=== Clic sur le bouton Trier dans l'ordre croissant ===
//=======================================================
void CLecteurAudioDlg::OnBnClickedBtnTrierAz()
{
	//si la liste n'est pas vide, on peut trier
	if (clbListeDeLecture.GetCount() != 0) {
		CString cvaleur;
		int nbTitre = clbListeDeLecture.GetCount(), i = 0;
		//on copie les titres dans une ListBox cach�e qui � l'option SORT � true
		while (i < nbTitre) {
			clbListeDeLecture.GetText(i, cvaleur);
			clbListeTrieCache.AddString(cvaleur);
			i++;
		}
		//on efface notre liste
		clbListeDeLecture.ResetContent();
		i = 0;
		//on recopie dans notre liste les valeurs de la ListBox cach�e
		while (i < nbTitre) {
			clbListeTrieCache.GetText(i, cvaleur);
			clbListeDeLecture.AddString(cvaleur);
			i++;
		}
		//on vide la ListBox cach�e
		clbListeTrieCache.ResetContent();

		i = 0;
		//on copie les chemins dans une ListBox cach�e qui � l'option SORT � true
		while (i < nbTitre) {
			clbListeDeLectureDossier.GetText(i, cvaleur);
			clbListeTrieCache.AddString(cvaleur);
			i++;
		}
		//on efface notre liste
		clbListeDeLectureDossier.ResetContent();
		i = 0;
		//on recopie dans notre liste les valeurs de la ListBox cach�e
		while (i < nbTitre) {
			clbListeTrieCache.GetText(i, cvaleur);
			clbListeDeLectureDossier.AddString(cvaleur);
			i++;
		}
		//on vide la ListBox cach�e
		clbListeTrieCache.ResetContent();
	}
}

//=========================================================
//=== Clic sur le bouton Trier dans l'ordre d�croissant ===
//=========================================================
void CLecteurAudioDlg::OnBnClickedBtnTrierZa()
{
	//si la liste n'est pas vide, on peut trier
	if (clbListeDeLecture.GetCount() != 0) {
		CString cvaleur;
		int nbTitre = clbListeDeLecture.GetCount(), i = 0;
		//on copie les titres dans une ListBox cach�e qui � l'option SORT � true
		while (i < nbTitre) {
			clbListeDeLecture.GetText(i, cvaleur);
			clbListeTrieCache.AddString(cvaleur);
			i++;
		}
		//on efface notre liste
		clbListeDeLecture.ResetContent();
		i = nbTitre - 1;
		//on recopie dans notre liste les valeurs de la ListBox cach�e dans l'ordre inverse
		while (i >= 0) {
			clbListeTrieCache.GetText(i, cvaleur);
			clbListeDeLecture.AddString(cvaleur);
			i--;
		}
		//on vide la ListBox cach�e
		clbListeTrieCache.ResetContent();

		i = 0;
		//on copie les chemins dans une ListBox cach�e qui � l'option SORT � true
		while (i < nbTitre) {
			clbListeDeLectureDossier.GetText(i, cvaleur);
			clbListeTrieCache.AddString(cvaleur);
			i++;
		}
		//on efface notre liste
		clbListeDeLectureDossier.ResetContent();
		i = nbTitre - 1;
		//on recopie dans notre liste les valeurs de la ListBox cach�e dans l'ordre inverse
		while (i >= 0) {
			clbListeTrieCache.GetText(i, cvaleur);
			clbListeDeLectureDossier.AddString(cvaleur);
			i--;
		}
		//on vide la ListBox cach�e
		clbListeTrieCache.ResetContent();
	}
}

//=================================================================
//=== Clic sur le bouton Up pour d�placer un titre vers le haut ===
//=================================================================
void CLecteurAudioDlg::OnBnClickedBtnUp() {
	//si pas de s�lection, on s�lectionne le premier titre dans la liste
	if (clbListeDeLecture.GetCurSel() == LB_ERR) {
		clbListeDeLecture.SetCurSel(0);
	}
	else {
		//si le titre s�lectionn� n'est pas le premier de la liste
		if (clbListeDeLecture.GetCurSel() > 0) {
			CString cvaleur;
			CString cvaleurtemp;
			//on r�cup�re la position actuelle
			int pos = clbListeDeLecture.GetCurSel();
			//on �change les deux valeurs
			clbListeDeLecture.GetText(pos - 1, cvaleurtemp);
			clbListeDeLecture.GetText(pos, cvaleur);
			clbListeDeLecture.DeleteString(pos - 1);
			clbListeDeLecture.InsertString(pos - 1, cvaleur);
			clbListeDeLecture.DeleteString(pos);
			clbListeDeLecture.InsertString(pos, cvaleurtemp);
			clbListeDeLecture.SetCurSel(pos - 1);
			//idem pour les chemins
			clbListeDeLectureDossier.GetText(pos - 1, cvaleurtemp);
			clbListeDeLectureDossier.GetText(pos, cvaleur);
			clbListeDeLectureDossier.DeleteString(pos - 1);
			clbListeDeLectureDossier.InsertString(pos - 1, cvaleur);
			clbListeDeLectureDossier.DeleteString(pos);
			clbListeDeLectureDossier.InsertString(pos, cvaleurtemp);
			clbListeDeLectureDossier.SetCurSel(pos - 1);
		}
	}
}

//==================================================================
//=== Clic sur le bouton Down pour d�placer un titre vers le bas ===
//==================================================================
void CLecteurAudioDlg::OnBnClickedBtnDown() {
	//si pas de s�lection, on s�lectionne le premier titre dans la liste
	if (clbListeDeLecture.GetCurSel() == LB_ERR) {
		clbListeDeLecture.SetCurSel(0);
	}
	else {
		//si le titre s�lectionn� n'est pas le dernier de la liste
		if (clbListeDeLecture.GetCurSel() < clbListeDeLecture.GetCount() - 1) {
			CString cvaleur;
			CString cvaleurtemp;
			//on r�cup�re la position actuelle
			int pos = clbListeDeLecture.GetCurSel();
			//on �change les deux valeurs
			clbListeDeLecture.GetText(pos + 1, cvaleurtemp);
			clbListeDeLecture.GetText(pos, cvaleur);
			clbListeDeLecture.DeleteString(pos + 1);
			clbListeDeLecture.InsertString(pos + 1, cvaleur);
			clbListeDeLecture.DeleteString(pos);
			clbListeDeLecture.InsertString(pos, cvaleurtemp);
			clbListeDeLecture.SetCurSel(pos + 1);
			//idem pour les chemins
			clbListeDeLectureDossier.GetText(pos + 1, cvaleurtemp);
			clbListeDeLectureDossier.GetText(pos, cvaleur);
			clbListeDeLectureDossier.DeleteString(pos + 1);
			clbListeDeLectureDossier.InsertString(pos + 1, cvaleur);
			clbListeDeLectureDossier.DeleteString(pos);
			clbListeDeLectureDossier.InsertString(pos, cvaleurtemp);
			clbListeDeLectureDossier.SetCurSel(pos + 1);
		}
	}
}

//======================================
//=== Modification du curseur de son ===
//======================================
void CLecteurAudioDlg::OnNMReleasedcaptureVolume(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
	//on met � jour le volume du son si le titre est en cours de lecture
	if (FonctionsFmodEnCours.EcouteEnCours())
		FonctionsFmodEnCours.ReglerVolume(cslSliderVolume.GetPos());
}

//==========================================================
//=== Modification du curseur d'avancement de la lecture ===
//==========================================================
void CLecteurAudioDlg::OnNMReleasedcaptureAvancement(NMHDR *pNMHDR, LRESULT *pResult)
{
	//*pResult = 0;
	//int posTitre = (cslSliderAvancement.GetPos()*FonctionsFmodEnCours.GetDureeTitre())/100;
	//FonctionsFmodEnCours.uiSetPositionDansTitre(posTitre);
}

//============================
//=== Clic sur bouton Aide ===
//============================
void CLecteurAudioDlg::OnBnClickedBtnAide()
{
	//on lance l'aide
	//this->OnHelp();
	CAboutDlg myDlg;
	myDlg.DoModal();
}

//===============================
//=== Clic sur bouton Quitter ===
//===============================
void CLecteurAudioDlg::OnBnClickedBtnQuitter()
{
	//on arr�te la lecture du fichier
	FonctionsFmodEnCours.Arret();
	//on ferme la bo�te de dialogue comme si on cliquait sur OK
	OnOK();
}