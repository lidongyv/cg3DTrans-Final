// cg3DTransDoc.h : interface of the CCg3DTransDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CG3DTRANSDOC_H__8FF707C6_E339_493C_A67E_9344FAD7B0E2__INCLUDED_)
#define AFX_CG3DTRANSDOC_H__8FF707C6_E339_493C_A67E_9344FAD7B0E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TypeDefine.h"

// Trans Object Select No.
#define BALL     0
#define CUBE     1
#define TRIANGLE 2
#define EYE      3
#define LIGHT0   4
#define LIGHT1   5
#define SCENE    6

#define SPACEOBJECTS 3

class CCg3DTransDoc : public CDocument
{
protected: // create from serialization only
	CCg3DTransDoc();
	DECLARE_DYNCREATE(CCg3DTransDoc)

// Attributes
public: 
	
	// Scene Trans parameters
   	float m_translateVector[3];       
	float m_xAngle,m_yAngle,m_zAngle;

	BOOL  m_selfRotate,m_onLight,m_onShade;        // Scene Light Mode
	char  m_transMode,m_transDir,m_transSelect;    // Transform mode, direction and select 

	Object_t m_spaceObjects[8];       // Space Object Buffer
	
	// Camera view model parameters.
	float m_viewDistance;                   // View distance
	float m_refX,m_refY,m_refZ;             // View reference point
	float m_viewX,m_viewY,m_viewZ;          // View direction
	float m_viewUpX,m_viewUpY,m_viewUpZ;    // View Up direction
	
	float eyeX,eyeY,eyeZ;             // Eye Position
	float winLx,winLy,winRx,winRy;    // window on XOY project plane
	
	float ballRadius;
	float zBack, zFront;              // Clip Box Front and Back Plane.
	float winLpaneM,winRpaneM,winBpaneM,winTpaneM;

	float clipCubeBackLB[3], clipCubeBackRB[3];
	float clipCubeBackLT[3], clipCubeBackRT[3];
	float clipCubeFrontLB[3], clipCubeFrontRB[3];
	float clipCubeFrontLT[3], clipCubeFrontRT[3];

	int   nrLights,shinePara;
	float lightX[5], lightY[5], lightZ[5];
	float ambientLight, pointLight, reflectPara,refractPara;


// Operations
public:
    void pCreateBall();
	void pCreateCube();
	void pCreateClipBox();
	void pCreateTriangle();
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCg3DTransDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCg3DTransDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCg3DTransDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG3DTRANSDOC_H__8FF707C6_E339_493C_A67E_9344FAD7B0E2__INCLUDED_)
