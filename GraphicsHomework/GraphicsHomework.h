
// GraphicsHomework.h : main header file for the GraphicsHomework application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGraphicsHomeworkApp:
// See GraphicsHomework.cpp for the implementation of this class
//

class CGraphicsHomeworkApp : public CWinApp
{
public:
	CGraphicsHomeworkApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	afx_msg void OnEditParams();
	DECLARE_MESSAGE_MAP()
public: // because I need them fron the view
	double _a, _b, _s;
	int _h, _w; // size of the view
	int center_x, center_y; // not in use yet
	COLORREF _c1, _c2;
	enum {VALUES = 0, ZEROES = 1} _mode;
public:
	afx_msg void OnSetModeValues();
	afx_msg void OnModeZeros();
};

extern CGraphicsHomeworkApp theApp;
