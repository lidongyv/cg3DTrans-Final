// glFont.cpp: implementation of the CglFont class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "cg3DTrans.h"
#include "glFont.h"

#include "GL/gl.h"
#include "GL/glu.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CglFont::CglFont()
{
	
	m_uiListID = 0;
    m_dThick = 0.1;
	m_FontType = GL_FONT_SOLID;
}

CglFont::~CglFont()
{
	
	if (m_uiListID != 0)  glDeleteLists(m_uiListID, FONTLIST);
}

BOOL CglFont::CreateFont(CDC* pDrawDC, char* fontname)
{
	m_uiListID = glGenLists(FONTLIST);
	
	if (pDrawDC == NULL || m_uiListID == 0)  return FALSE;
	
	//Create the font to display
	CFont newfont;
	CFont* oldfont;
	BOOL  bresult;
	GLYPHMETRICSFLOAT gmf[FONTLIST];
	
	if (fontname != NULL)	{	
        bresult = newfont.CreateFont(-12, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, 
			OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			FF_DONTCARE|DEFAULT_PITCH, fontname);
		
		//if new font failed to be created
		if (!bresult)   return FALSE;
		
		oldfont = pDrawDC->SelectObject(&newfont);
	}	else	{
		oldfont = (CFont*)pDrawDC->SelectStockObject(SYSTEM_FONT);
	}
	
	if (m_FontType == GL_FONT_SOLID)	{
        bresult = wglUseFontOutlines(pDrawDC->m_hDC, 0, FONTLIST, m_uiListID, 
			0.0f, (float)m_dThick, WGL_FONT_POLYGONS, gmf);	
	} else if(m_FontType == GL_FONT_LINE)	{
        bresult = wglUseFontOutlines(pDrawDC->m_hDC, 0, FONTLIST, m_uiListID, 
			0.0f, (float)m_dThick, WGL_FONT_LINES, gmf);	
	}
	
	pDrawDC->SelectObject(oldfont);
	newfont.DeleteObject();
	
	if (!bresult)  return FALSE;
	
	return TRUE;
}


//////////////////////////////////////////////////////////////////////
// display the text string
//////////////////////////////////////////////////////////////////////
void CglFont::GLDrawText(float OffSet[3], float Scale[3], float Rotate[3], CString strText)
{
	if (m_uiListID == 0 || strText.IsEmpty())	return;
	
	GLsizei size = strText.GetLength();
	
	glPushMatrix();
    //Translate 
	glTranslated(OffSet[0], OffSet[1], OffSet[2]);
	glScaled(Scale[0], Scale[1], Scale[2]); 
	glRotated(Rotate[0], 1.0, 0.0, 0.0);
	glRotated(Rotate[1], 0.0, 1.0, 0.0);
	glRotated(Rotate[2], 0.0, 0.0, 1.0);
	
	//display the letter
	glListBase(m_uiListID);
	glCallLists(size, GL_UNSIGNED_BYTE, (const GLvoid*)strText.GetBuffer(size)); 
	
	//restore the original angle around Z-axis
	glRotated(-Rotate[2], 0.0, 0.0, 1.0);
	glRotated(-Rotate[1], 0.0, 1.0, 0.0);
	glRotated(-Rotate[0], 1.0, 0.0, 0.0);
	glScaled(1.0/Scale[0], 1.0/Scale[1], 1.0/Scale[2]); 
    glTranslated(-OffSet[0], -OffSet[1], -OffSet[2]);
	
	glPopMatrix();
	
}