
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
	ON_WM_MOUSEWHEEL()
	ON_WM_MOUSEMOVE()
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

	a = theApp._a;
	b = theApp._b;
	s = theApp._s;
	w = theApp._w;
	h = theApp._h;

	double t1, t2;
	t1 = a*(x - w / 2) * a*(x - w / 2);
	t2 = b*(y - h / 2) * b*(y - h / 2);

	return sin((t1 + t2)/s);
}

void CGraphicsHomeworkView::update_h_w() {
	RECT rect;
	LPRECT lprect = &rect;
	GetClientRect(lprect);
	theApp._h = rect.bottom;
	theApp._w = rect.right;
}

void CGraphicsHomeworkView::draw_axis(CDC* pDC) {
	int h = theApp._h;
	int w = theApp._w;
	int c_x = theApp.center_x;
	int c_y = theApp.center_y;
	
	// X axis
	MoveToEx(*pDC, 0, c_y, NULL);
	LineTo(*pDC, w, c_y);
	
	// Y axis
	MoveToEx(*pDC, c_x, 0, NULL);
	LineTo(*pDC, c_x, h);
}

void CGraphicsHomeworkView::draw_f(CDC* pDC) {
	int h = theApp._h;
	int w = theApp._w;

	CImage bmp;
	bmp.Create(w, h, 32);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			double x, y;
			x = (double)i - (double)theApp.center_x;
			y = (double)j - (double)theApp.center_y;
			y = -y;
			double t = (f(x, y) + 1) / 2;
			COLORREF clr;
			if (theApp._mode == CGraphicsHomeworkApp::VALUES) {
				BYTE red = GetRValue(theApp._c1) * (1 - t) + GetRValue(theApp._c2) * t;
				BYTE green = GetGValue(theApp._c1) * (1 - t) + GetGValue(theApp._c2) * t;
				BYTE blue = GetBValue(theApp._c1) * (1 - t) + GetBValue(theApp._c2) * t;
				clr = RGB(red, green, blue);
			}
			else {
				if (f(x, y) > 0)
					clr = theApp._c1;
				else
					clr = theApp._c2;
			}
			//SetPixel(memDC, i, j, clr);
			//dib[j + i*w] = clr;
			bmp.SetPixel(i, j, clr);
		}
	}
	bmp.Draw(*pDC, 0, 0);
}

void CGraphicsHomeworkView::OnDraw(CDC* pDC)
{
	CGraphicsHomeworkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	update_h_w();
	draw_f(pDC);
	draw_axis(pDC);
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

BOOL CGraphicsHomeworkView::OnMouseWheel(UINT flags, short zdelta, CPoint point) {
	theApp._s += zdelta;
	Invalidate();
	return true;
}

void CGraphicsHomeworkView::OnMouseMove(UINT nFlags, CPoint point) {
	if (!(nFlags & MK_LBUTTON))
		return;
	theApp.center_x = point.x;
	theApp.center_y = point.y;
	Invalidate();
}