
// gittestView.cpp : implementation of the CgittestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "gittest.h"
#endif

#include "gittestDoc.h"
#include "gittestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CgittestView

IMPLEMENT_DYNCREATE(CgittestView, CView)

BEGIN_MESSAGE_MAP(CgittestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CgittestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CgittestView construction/destruction

CgittestView::CgittestView()
{
	// TODO: add construction code here

}

CgittestView::~CgittestView()
{
}

BOOL CgittestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CgittestView drawing

void CgittestView::OnDraw(CDC* /*pDC*/)
{
	CgittestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CgittestView printing


void CgittestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CgittestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CgittestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CgittestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CgittestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CgittestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CgittestView diagnostics

#ifdef _DEBUG
void CgittestView::AssertValid() const
{
	CView::AssertValid();
}

void CgittestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CgittestDoc* CgittestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CgittestDoc)));
	return (CgittestDoc*)m_pDocument;
}
#endif //_DEBUG


// CgittestView message handlers
