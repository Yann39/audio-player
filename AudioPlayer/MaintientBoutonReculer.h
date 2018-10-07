#pragma once

class MaintientBoutonReculer : public CBitmapButton
{
public:
	MaintientBoutonReculer(void);
public:
	~MaintientBoutonReculer(void);
public:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
