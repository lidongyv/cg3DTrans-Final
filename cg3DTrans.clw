; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCg3DTransView
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "cg3DTrans.h"
LastPage=0

ClassCount=6
Class1=CCg3DTransApp
Class2=CCg3DTransDoc
Class3=CCg3DTransView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CCgTransControl
Resource3=IDD_TRANSCONTROL

[CLS:CCg3DTransApp]
Type=0
HeaderFile=cg3DTrans.h
ImplementationFile=cg3DTrans.cpp
Filter=N

[CLS:CCg3DTransDoc]
Type=0
HeaderFile=cg3DTransDoc.h
ImplementationFile=cg3DTransDoc.cpp
Filter=N

[CLS:CCg3DTransView]
Type=0
HeaderFile=cg3DTransView.h
ImplementationFile=cg3DTransView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_ONSHADE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=cg3DTrans.cpp
ImplementationFile=cg3DTrans.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_AUTOPLAY
Command10=ID_ONLIGHT
Command11=ID_ONSHADE
CommandCount=11

[DLG:IDD_TRANSCONTROL]
Type=1
Class=CCgTransControl
ControlCount=10
Control1=IDC_TRANSSELECT_TITLE,static,1342308353
Control2=IDC_TRANSSELECT,combobox,1344339970
Control3=IDC_TRANSMODE,button,1342242816
Control4=IDC_X_CLKWISE,button,1342242816
Control5=IDC_X_ANTICLKWISE,button,1342242816
Control6=IDC_Y_CLKWISE,button,1342242816
Control7=IDC_Y_ANTICLKWISE,button,1342242816
Control8=IDC_Z_CLKWISE,button,1342242816
Control9=IDC_Z_ANTICLKWISE,button,1342242816
Control10=IDC_VIEWPORT,static,1342177287

[CLS:CCgTransControl]
Type=0
HeaderFile=CgTransControl.h
ImplementationFile=CgTransControl.cpp
BaseClass=CFormView
Filter=D
LastObject=CCgTransControl
VirtualFilter=VWC

