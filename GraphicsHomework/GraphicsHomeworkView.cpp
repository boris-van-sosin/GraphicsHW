
// GraphicsHomeworkView.cpp : implementation of the CGraphicsHomeworkView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GraphicsHomework.h"
#endif

#include "GraphicsHomeworkDoc.h"
#include "GraphicsHomeworkView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicsHomeworkView

IMPLEMENT_DYNCREATE(CGraphicsHomeworkView, CView)

BEGIN_MESSAGE_MAP(CGraphicsHomeworkView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CGraphicsHomeworkView construction/destruction

CGraphicsHomeworkView::CGraphicsHomeworkView()
{
	// TODO: add construction code here

}

CGraphicsHomeworkView::~CGraphicsHomeworkView()
{
}

BOOL CGraphicsHomeworkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGraphicsHomeworkView drawing

double CGraphicsHomeworkView::f(double x, double y) {
	double a, b, s;
	double h, w;

	// TODO: get here the right values

	double t1, t2;
	t1 = a*(x - w / 2) * a*(x - w / 2);
	t2 = b*(y - h / 2) * b*(y - h / 2);

	return sin((t1 + t2)/s);
}

void CGraphicsHomeworkView::OnDraw(CDC* pDC)
{
	CGraphicsHomeworkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	SetPixel(*pDC, 5, 5, RGB(255, 0, 0));
}


// CGraphicsHomeworkView printing

BOOL CGraphicsHomeworkView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphicsHomeworkView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphicsHomeworkView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CGraphicsHomeworkView diagnostics

#ifdef _DEBUG
void CGraphicsHomeworkView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicsHomeworkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicsHomeworkDoc* CGraphicsHomeworkView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicsHomeworkDoc)));
	return (CGraphicsHomeworkDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicsHomeworkView message handlers
