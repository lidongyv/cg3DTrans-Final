// cg3DTransView.cpp : implementation of the CCg3DTransView class
//

#include "stdafx.h"
#include "cg3DTrans.h"

#include "gl\gl.h"
#include "gl\glu.h"
#include "gl\glut.h"

#include "DrawScene.h"
#include "CameraView.h"
#include "cg3DTransDoc.h"
#include "cg3DTransView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCg3DTransView

IMPLEMENT_DYNCREATE(CCg3DTransView, CView)

BEGIN_MESSAGE_MAP(CCg3DTransView, CView)
	//{{AFX_MSG_MAP(CCg3DTransView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_AUTOPLAY, OnAutoplay)
	ON_UPDATE_COMMAND_UI(ID_AUTOPLAY, OnUpdateAutoplay)
	ON_WM_TIMER()
	ON_COMMAND(ID_ONLIGHT, OnOnlight)
	ON_COMMAND(ID_ONSHADE, OnOnshade)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCg3DTransView construction/destruction

CCg3DTransView::CCg3DTransView()
{
	// TODO: add construction code here
    m_drawScene = new CDrawScene(this);
    m_cameraView = new CCameraView(this);

}

CCg3DTransView::~CCg3DTransView()
{
}

BOOL CCg3DTransView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCg3DTransView drawing

void CCg3DTransView::OnDraw(CDC* pDC)
{
	CCg3DTransDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	DrawScene();
}

/////////////////////////////////////////////////////////////////////////////
// CCg3DTransView printing

BOOL CCg3DTransView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCg3DTransView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCg3DTransView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCg3DTransView diagnostics

#ifdef _DEBUG
void CCg3DTransView::AssertValid() const
{
	CView::AssertValid();
}

void CCg3DTransView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCg3DTransDoc* CCg3DTransView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCg3DTransDoc)));
	return (CCg3DTransDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCg3DTransView message handlers
BOOL CCg3DTransView::bSetupPixelFormat()
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
			1,                              // version number
			PFD_DRAW_TO_WINDOW |            // support window
			PFD_SUPPORT_OPENGL |            // support OpenGL
			PFD_DOUBLEBUFFER,               // double buffered
			PFD_TYPE_RGBA,                  // RGBA type
			24,                             // 24-bit color depth
			0, 0, 0, 0, 0, 0,               // color bits ignored
			0,                              // no alpha buffer
			0,                              // shift bit ignored
			0,                              // no accumulation buffer
			0, 0, 0, 0,                     // accum bits ignored
			32,                             // 32-bit z-buffer
			0,                              // no stencil buffer
			0,                              // no auxiliary buffer
			PFD_MAIN_PLANE,                 // main layer
			0,                              // reserved
			0, 0, 0                         // layer masks ignored
	};
	int pixelformat;
	
	if ( (pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0 )
	{
		MessageBox("ChoosePixelFormat failed");
		return FALSE;
	}
	
	if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
	{
		MessageBox("SetPixelFormat failed");
		return FALSE;
	}
	
	return TRUE;
}

int CCg3DTransView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	PIXELFORMATDESCRIPTOR pfd;
	int         n;
	HGLRC       hrc;
	GLfloat      fAspect;
	CCg3DTransDoc* pDoc = GetDocument();
	
	m_pDC = new CClientDC(this);
	ASSERT(m_pDC != NULL);
	
	if (!bSetupPixelFormat()) return 0;
	
	n = ::GetPixelFormat(m_pDC->GetSafeHdc());
	::DescribePixelFormat(m_pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);
	
	hrc = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(), hrc);
	
	glClearDepth(100.0f);
    glShadeModel(GL_FLAT);
    glEnable(GL_NORMALIZE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_AUTO_NORMAL);
	GetClientRect(&m_viewRect);
	
	if (!m_viewRect.bottom)	fAspect = 1.0f;
	else                    fAspect = (GLfloat)m_viewRect.right/
		m_viewRect.bottom;
	
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.15 };
	GLfloat mat_shininess[] = { 100.0 };
	GLfloat position[] = { 0.5, 1.0, 2.0, 0.0 };
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, fAspect, 3.0f, 15.0f);
	glMatrixMode(GL_MODELVIEW);
	
	
// 	m_vecFont.CreateFont(m_pDC, "Arial Black");
 	m_axisFont.CreateFont(m_pDC, "Times New Roman"); //Arial Black
	
	return 0;
}

void CCg3DTransView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (cy > 0)
	{
		glViewport(0, 0, cx, cy);
		
		if((m_viewRect.right > cx) || (m_viewRect.bottom > cy))
			RedrawWindow();
		
		m_viewRect.right = cx;
		m_viewRect.bottom = cy;
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLdouble)cx/cy, 3.0f, 7.0f);
		glMatrixMode(GL_MODELVIEW);
	}						
}

void CCg3DTransView::DrawScene()
{
	static BOOL bBusy = FALSE;
	CCg3DTransDoc* pDoc = (CCg3DTransDoc*)GetDocument();
	
	if (bBusy)	return;
	
	bBusy = TRUE;

	// 清祯缓存
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// 构建空间场景变换矩阵
	glPushMatrix();
	glTranslatef(pDoc->m_translateVector[0], 
		         pDoc->m_translateVector[1],
		         pDoc->m_translateVector[2]);
	glRotatef(pDoc->m_xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(pDoc->m_yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(pDoc->m_zAngle, 0.0f, 0.0f, 1.0f);
	glScalef(0.3f, 0.3f, 0.3f);   /* Make Scene Smaller Enough to Look */

	
    // Call CDrawScene 输出绘制空间场景坐标XYZ轴
	if (m_drawScene != NULL) m_drawScene->DrawScene();

	// Call CCameraView 绘制视空间场景坐标XYZ轴
	if (m_cameraView != NULL) m_cameraView->DrawScene();

	glPopMatrix();
	
	glFinish();
	SwapBuffers(wglGetCurrentDC());
	
	bBusy = FALSE;
	
	pDoc->UpdateAllViews(this);
}


BOOL m_autoPlay = FALSE;

void CCg3DTransView::OnAutoplay() 
{
	// TODO: Add your command handler code here
	m_autoPlay = !m_autoPlay;
	
	if (m_autoPlay)  SetTimer(1, 50, NULL);
	else             KillTimer(1);
	
}

void CCg3DTransView::OnUpdateAutoplay(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
//	pCmdUI->SetCheck(m_autoPlay);
}

void CCg3DTransView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	DrawScene();

	CView::OnTimer(nIDEvent);
}

void CCg3DTransView::OnOnlight() 
{
	// TODO: Add your command handler code here
	CCg3DTransDoc* pDoc = (CCg3DTransDoc*)GetDocument();

	pDoc->m_onLight = !pDoc->m_onLight;
}

void CCg3DTransView::OnOnshade() 
{
	// TODO: Add your command handler code here
	CCg3DTransDoc* pDoc = (CCg3DTransDoc*)GetDocument();
	
	pDoc->m_onShade = !pDoc->m_onShade;	
}
