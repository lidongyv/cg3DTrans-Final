// DrawScene.h: interface for the CDrawScene class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWSCENE_H__467F4BFC_450C_4296_86F2_14AAE772C951__INCLUDED_)
#define AFX_DRAWSCENE_H__467F4BFC_450C_4296_86F2_14AAE772C951__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cg3DTransDoc.h"
#include "cg3DTransView.h"

class CDrawScene  
{
public:
	CDrawScene();
	virtual ~CDrawScene();
    CDrawScene(CCg3DTransView* pView);
	
	void DrawScene();
	
private:
	int m_objNumber;            // Object Number
	Object_p m_whoObj_p;        // Object pointer
	float xCenter,yCenter,zCenter;

	CCg3DTransView* m_pView;
	float glObjColor[SPACEOBJECTS][3];

	void DrawBackground();
	void drawSpaceObject();

	void CaculateMatrix();
	void transSpaceObject();
	void projectSpaceObject();
	
	void rotateX3Dmatrix(float S, float C);
	void rotateY3Dmatrix(float S, float C);
	void rotateZ3Dmatrix(float S, float C);
	void translate3dMatrix(float dx, float dy, float dz);

	void pRemoveBackFace();

	void pClipSpaceObject();
	int pVisible(float x, float y, float z, int pane);
	int outPut(float x, float y, float z, int *outCount, Gpoint_p polyClip);
	int pLineCrossPane(float sx, float sy, float sz,
		               float px, float py, float pz, int pane);
	int pLineInterSectPane(float sx, float sy, float sz, 
		                   float px, float py, float pz,
		                   int pane, int *outCount, Gpoint_p polyClip);
	void pObjectCenter();
	void pLightSpaceBall();
	void pLightSpaceObject();
};

#endif // !defined(AFX_DRAWSCENE_H__467F4BFC_450C_4296_86F2_14AAE772C951__INCLUDED_)
