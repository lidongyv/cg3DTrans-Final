// glFont.h: interface for the CglFont class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLFONT_H__46BB73DA_1273_4731_A439_452433D67247__INCLUDED_)
#define AFX_GLFONT_H__46BB73DA_1273_4731_A439_452433D67247__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define FONTLIST    256

//the type of 3D Font, solid or wireframe
enum GLFontType  {
	GL_FONT_SOLID,
	GL_FONT_LINE,
};

class CglFont  
{
public:
	CglFont();
	virtual ~CglFont();
	
	//	void   SetFontType(GLFontType FontType) {m_FontType = FontType;};
	//	void   SetFontSize(double dThick) {m_dThick = dThick;};
	
	
	//Create the 3D font from the truetype library, fontname is the Font name of truetype
	BOOL CreateFont(CDC* pDrawDC, char* fontname);
	
	//Draw the 3D Font string in screen
	void GLDrawText(float OffSet[3], float Scale[3], float Rotate[3], CString strText);
	
	//Parameters
private:
	GLFontType   m_FontType;     //font type
	UINT         m_uiListID;     //the ID of the displaylist
    double       m_dThick;       //the letters thick 
	
};

#endif // !defined(AFX_GLFONT_H__46BB73DA_1273_4731_A439_452433D67247__INCLUDED_)
