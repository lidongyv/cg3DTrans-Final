#if !defined(AFX_CGTRANSCONTROL_H__7F5C348A_CD47_42EC_841B_4B95198E9DF7__INCLUDED_)
#define AFX_CGTRANSCONTROL_H__7F5C348A_CD47_42EC_841B_4B95198E9DF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CgTransControl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCgTransControl form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#define  N 32
#define PRJPLANERETWIDTH  400
#define PRJPLANERETHEIGHT 400

#include "cg3DTransDoc.h"

class CCgTransControl : public CFormView
{
protected:
	CCgTransControl();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCgTransControl)

// Form Data
public:
	//{{AFX_DATA(CCgTransControl)
	enum { IDD = IDD_TRANSCONTROL };
	CComboBox	m_transSelect;
	//}}AFX_DATA

// Attributes
public:
	int m_objNumber;            // Object Number
	Object_p m_whoObj_p;        // Object pointer

	COLORREF vcObjColor[SPACEOBJECTS];

	int polyCount;
	float ymax[N],ymin[N];
    int ibegin,iend,scan,pdges;
    float Dx[N],Xa[N],Sc[N],Dc[N];
	
	float prjPlaneRetZ[PRJPLANERETWIDTH][PRJPLANERETHEIGHT];  // Z-Buffer 2D Array

// Operations
public:
	void pTransToZbuffer(CRect dcRect);
	void pDrawLineObject(CDC *pDC, CRect dcRect);

   void pDrawLightObject(CDC *pDC, CRect dcRect, float maxShade, float minShade);
   void pDrawShadeLightObject(CDC *pDC, CRect dcRect, float maxShade, float minShade);

   void FillPolygon(CDC *pDC, int n,int *x,int *y,int *color,CRect dcRect);
   void Loadpolygon(int n,int *x,int *y, int *color);
   void PolyInsert(float x1,float y1,float x2,float y2, int c1, int c2);
   void UpdateXvalue();
   void XSort(int begin,int i);
   void Fillscan(CDC *pDC,CRect dcRect);
   void Include();
   
   // Interface for remove hidden part by Z-buffer Method. 
	float CalculateZValue(int x,int y,CRect dcRect,int i);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCgTransControl)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCgTransControl();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCgTransControl)
	afx_msg void OnTransmode();
	afx_msg void OnSelchangeTransselect();
	afx_msg void OnXClkwise();
	afx_msg void OnXAnticlkwise();
	afx_msg void OnYClkwise();
	afx_msg void OnYAnticlkwise();
	afx_msg void OnZClkwise();
	afx_msg void OnZAnticlkwise();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGTRANSCONTROL_H__7F5C348A_CD47_42EC_841B_4B95198E9DF7__INCLUDED_)
