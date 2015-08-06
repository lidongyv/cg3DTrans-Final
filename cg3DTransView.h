// cg3DTransView.h : interface of the CCg3DTransView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CG3DTRANSVIEW_H__FDF6DABE_3BFE_45D6_95A7_52B94E574E32__INCLUDED_)
#define AFX_CG3DTRANSVIEW_H__FDF6DABE_3BFE_45D6_95A7_52B94E574E32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "glFont.h"

class CDrawScene;
class CCameraView;

class CCg3DTransView : public CView
{
protected: // create from serialization only
	CCg3DTransView();
	DECLARE_DYNCREATE(CCg3DTransView)

// Attributes
public:
	CCg3DTransDoc* GetDocument();

	BOOL       m_autoPlay;
	CClientDC  *m_pDC; 
	CRect      m_viewRect;
    CDrawScene  *m_drawScene;
	CCameraView *m_cameraView;

	CglFont  m_axisFont;
//	CGLFont  m_axisFont, m_vecFont;

// Operations
public:

	void DrawScene();
    BOOL bSetupPixelFormat();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCg3DTransView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCg3DTransView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCg3DTransView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnAutoplay();
	afx_msg void OnUpdateAutoplay(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnOnlight();
	afx_msg void OnOnshade();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in cg3DTransView.cpp
inline CCg3DTransDoc* CCg3DTransView::GetDocument()
   { return (CCg3DTransDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG3DTRANSVIEW_H__FDF6DABE_3BFE_45D6_95A7_52B94E574E32__INCLUDED_)
