// CameraView.h: interface for the CCameraView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAMERAVIEW_H__F071BB29_56EE_403E_976B_DFD1B8DA3787__INCLUDED_)
#define AFX_CAMERAVIEW_H__F071BB29_56EE_403E_976B_DFD1B8DA3787__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TypeDefine.h"
#include "cg3dTransDoc.h"
#include "cg3DTransView.h"

class CCameraView  
{
public:
	CCameraView();
	virtual ~CCameraView();
    CCameraView(CCg3DTransView* pView);

	void DrawScene();

private:
	CCg3DTransView* m_pView;
	float glObjColor[SPACEOBJECTS][3];

	Object_p m_whoObj_p;     // Object pointer
	int      m_objNumber;    // Object Number
	
	float viewOx,viewOy,viewOz;                      // View Original Point
	float viewEyex,viewEyey,viewEyez;
    float xAxisX,xAxisY,xAxisZ;                      // View X Axis 
    float yAxisX,yAxisY,yAxisZ;                      // View Y Axis
	float zAxisX,zAxisY,zAxisZ;                      // View Z Axis

	float m_viewTransMatrix[4][3];            // Object view transforms matrix
    float m_reverseTransMatrix[4][3];         // Object view-reverse transforms matrix

	void DrawBackground();

	void ViewTransObject();
	void InitViewTransMatrix();

	void CalculateViewTransMatrix();
	void rotateX3Dmatrix(float S, float C, float transMatrix[4][3]);
	void rotateY3Dmatrix(float S, float C, float transMatrix[4][3]);
	void rotateZ3Dmatrix(float S, float C, float transMatrix[4][3]);
	void translate3dMatrix(float dx, float dy, float dz, float transMatrix[4][3]);

};

#endif // !defined(AFX_CAMERAVIEW_H__F071BB29_56EE_403E_976B_DFD1B8DA3787__INCLUDED_)
