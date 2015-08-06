// cg3DTrans.h : main header file for the CG3DTRANS application
//

#if !defined(AFX_CG3DTRANS_H__30F8B56E_A3E9_4060_916A_F5BD34FE8018__INCLUDED_)
#define AFX_CG3DTRANS_H__30F8B56E_A3E9_4060_916A_F5BD34FE8018__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCg3DTransApp:
// See cg3DTrans.cpp for the implementation of this class
//

class CCg3DTransApp : public CWinApp
{
public:
	CCg3DTransApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCg3DTransApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCg3DTransApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG3DTRANS_H__30F8B56E_A3E9_4060_916A_F5BD34FE8018__INCLUDED_)
