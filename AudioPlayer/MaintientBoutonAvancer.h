#pragma once

class MaintientBoutonAvancer : public CBitmapButton
{
public:
	MaintientBoutonAvancer(void);
public:
	~MaintientBoutonAvancer(void);
public:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
