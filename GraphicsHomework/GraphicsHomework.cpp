
// GraphicsHomework.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "GraphicsHomework.h"
#include "MainFrm.h"

#include "GraphicsHomeworkDoc.h"
#include "GraphicsHomeworkView.h"
#include "afxwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicsHomeworkApp

BEGIN_MESSAGE_MAP(CGraphicsHomeworkApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CGraphicsHomeworkApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	// Open custom parameters
	ON_COMMAND(ID_CUSTOM_CONTROLS, &CGraphicsHomeworkApp::OnEditParams)
END_MESSAGE_MAP()


// CGraphicsHomeworkApp construction

CGraphicsHomeworkApp::CGraphicsHomeworkApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("GraphicsHomework.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CGraphicsHomeworkApp object

CGraphicsHomeworkApp theApp;


// CGraphicsHomeworkApp initialization

BOOL CGraphicsHomeworkApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CGraphicsHomeworkDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CGraphicsHomeworkView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	_a = 1;
	_b = 1;
	_s = (float)GetSystemMetrics(0) / (float)10.0;
	_c1 = RGB(0, 0, 0);
	_c2 = RGB(255, 255, 255);
	_mode = VALUES;
	return TRUE;
}

int CGraphicsHomeworkApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CGraphicsHomeworkApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CGraphicsHomeworkApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CGraphicsHomeworkApp message handlers

class CCustomParams : public CDialogEx {
public:
	//CCustomParams();
	CCustomParams(float a, float b, float s, COLORREF c1, COLORREF c2);
	enum { IDD = IDD_CUSTOM_PARAMS };

	float GetA() const;
	float GetB() const;
	float GetS() const;
	COLORREF GetC1() const;
	COLORREF GetC2() const;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg BOOL OnInitDialog();
private:
	float _a, _b, _s;
	COLORREF _c1, _c2;
private:
	/*CEdit _EditBoxA;
	CEdit _EditBoxB;
	CEdit _EditBoxC;*/
public:
	afx_msg void OnBnClickedC1();
	afx_msg void OnBnClickedC2();
	afx_msg void OnBnClickedCancel();
};
/*
CCustomParams::CCustomParams() : CDialogEx(CCustomParams::IDD)
{
}
*/
CCustomParams::CCustomParams(float a, float b, float s, COLORREF c1, COLORREF c2) : CDialogEx(CCustomParams::IDD),
_a(a), _b(b), _s(s), _c1(c1), _c2(c2)
{
}

float CCustomParams::GetA() const { return _a; }
float CCustomParams::GetB() const { return _b; }
float CCustomParams::GetS() const { return _s; }
COLORREF CCustomParams::GetC1() const { return _c1; }
COLORREF CCustomParams::GetC2() const { return _c2; }

void CCustomParams::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	/*DDX_Control(pDX, IDC_EDIT1, _EditBoxA);
	DDX_Control(pDX, IDC_EDIT2, _EditBoxB);
	DDX_Control(pDX, IDC_EDIT3, _EditBoxC);*/
}

BEGIN_MESSAGE_MAP(CCustomParams, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCustomParams::OnBnClickedOk)
	ON_BN_CLICKED(IDC_C_1, &CCustomParams::OnBnClickedC1)
	ON_BN_CLICKED(IDC_C_2, &CCustomParams::OnBnClickedC2)
	ON_BN_CLICKED(IDCANCEL, &CCustomParams::OnBnClickedCancel)
END_MESSAGE_MAP()

// App command to run the custom params dialog

void CGraphicsHomeworkApp::OnEditParams()
{
	CCustomParams changeParamsDlg(_a, _b, _s, _c1, _c2);
	if (changeParamsDlg.DoModal() != IDCANCEL) {
		_a = changeParamsDlg.GetA();
		_b = changeParamsDlg.GetB();
		_s = changeParamsDlg.GetS();
		_c1 = changeParamsDlg.GetC1();
		_c2 = changeParamsDlg.GetC2();
	}
}

bool IsValidFloat(const CString& text)
{
	LPCTSTR ptr = (LPCTSTR)text;
	LPTSTR endptr;
	float value = _tcstof(ptr, &endptr);
	return (*ptr && endptr - ptr == text.GetLength());
}

void CCustomParams::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString aStr, bStr, sStr;
	GetDlgItemText(IDC_EDIT1, aStr);
	GetDlgItemText(IDC_EDIT2, bStr);
	GetDlgItemText(IDC_EDIT3, sStr);
	if (aStr != "" && IsValidFloat(aStr))
	{
		_a = (float)_ttof(aStr);
	}
	if (bStr != "" && IsValidFloat(bStr))
	{
		_b = (float)_ttof(bStr);
	}
	if (sStr != "" && IsValidFloat(sStr))
	{
		_s = (float)_ttof(sStr);
	}
	
	if (isnan(_a) || isnan(_b) || isnan(_s) || _a < 0 || _b < 0)
	{
		AfxMessageBox(_T("Invalid value. a and b must be positive."));
		return;
	}
	CDialogEx::OnOK();
}

BOOL CCustomParams::OnInitDialog()
{
	BOOL res = CDialogEx::OnInitDialog();
	if (!res)
	{
		return res;
	}
	CString str;
	str.Format(_T("%f"), _a);
	SetDlgItemText(IDC_EDIT1, str);
	str.Format(_T("%f"), _b);
	SetDlgItemText(IDC_EDIT2, str);
	str.Format(_T("%f"), _s);
	SetDlgItemText(IDC_EDIT3, str);
	return res;
}


void CCustomParams::OnBnClickedC1()
{
	// TODO: Add your control notification handler code here
	CColorDialog dialog(_c1);
	if (dialog.DoModal() != IDCANCEL)
		_c1 = dialog.GetColor();
}


void CCustomParams::OnBnClickedC2()
{
	// TODO: Add your control notification handler code here+
	CColorDialog dialog(_c2);
	if(dialog.DoModal() != IDCANCEL)
		_c2 = dialog.GetColor();
}


void CCustomParams::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
