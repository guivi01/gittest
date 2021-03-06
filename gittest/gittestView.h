
// gittestView.h : interface of the CgittestView class
//

#pragma once


class CgittestView : public CView
{
protected: // create from serialization only
	CgittestView();
	DECLARE_DYNCREATE(CgittestView)

// Attributes
public:
	CgittestDoc* GetDocument() const;
	int tony;
	int vero;
// Operations
public:

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
	virtual ~CgittestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in gittestView.cpp
inline CgittestDoc* CgittestView::GetDocument() const
   { return reinterpret_cast<CgittestDoc*>(m_pDocument); }
#endif

