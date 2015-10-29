
// GraphicsHomeworkView.h : interface of the CGraphicsHomeworkView class
//

#pragma once


class CGraphicsHomeworkView : public CView
{
protected: // create from serialization only
	CGraphicsHomeworkView();
	DECLARE_DYNCREATE(CGraphicsHomeworkView)

// Attributes
public:
	CGraphicsHomeworkDoc* GetDocument() const;

// Operations
public:
	double f(double x, double y);

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CGraphicsHomeworkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GraphicsHomeworkView.cpp
inline CGraphicsHomeworkDoc* CGraphicsHomeworkView::GetDocument() const
   { return reinterpret_cast<CGraphicsHomeworkDoc*>(m_pDocument); }
#endif

