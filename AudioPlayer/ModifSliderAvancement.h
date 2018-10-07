#pragma once

class ModifSliderAvancement : public CSliderCtrl
{
public:
	ModifSliderAvancement(void);
public:
	~ModifSliderAvancement(void);
public:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
