
// MoneyManagerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MoneyManager.h"
#include "MoneyManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMoneyManagerDlg 대화 상자



CMoneyManagerDlg::CMoneyManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MONEYMANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoneyManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RENT, m_edRent);
	DDX_Control(pDX, IDC_EDIT_RENT_MANAGE, m_edRentManage);
	DDX_Control(pDX, IDC_EDIT_INSURANCE, m_edInsurance);
	DDX_Control(pDX, IDC_EDIT_ETC, m_edETC);
	DDX_Control(pDX, IDC_EDIT_Gas, m_edGAS);
	DDX_Control(pDX, IDC_EDIT_Electro, m_edElectro);
	DDX_Control(pDX, IDC_EDIT_Tele, m_edTele);
	DDX_Control(pDX, IDC_EDIT_CARD, m_edCard);
	DDX_Control(pDX, IDC_EDIT_INCOME, m_edIncome);
	DDX_Control(pDX, IDC_EDIT_REST, m_edRest);
	DDX_Control(pDX, IDC_EDIT_TRANSPORT, m_edTrasnport);
	DDX_Control(pDX, IDC_EDIT_TOTAL_FIX, m_edTotalFix);
	DDX_Control(pDX, IDC_EDIT_TOTAL_SPEND, m_edTotalSpend);
	DDX_Control(pDX, IDC_STATIC_CAN_SAVE, m_stCanSave);
}

BEGIN_MESSAGE_MAP(CMoneyManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_RENT, &CMoneyManagerDlg::OnEnChangeEditRent)
	ON_EN_CHANGE(IDC_EDIT_RENT_MANAGE, &CMoneyManagerDlg::OnEnChangeEditRentManage)
	ON_EN_CHANGE(IDC_EDIT_INSURANCE, &CMoneyManagerDlg::OnEnChangeEditInsurance)
	ON_EN_CHANGE(IDC_EDIT_Tele, &CMoneyManagerDlg::OnEnChangeEditTele)
	ON_EN_CHANGE(IDC_EDIT_Electro, &CMoneyManagerDlg::OnEnChangeEditElectro)
	ON_EN_CHANGE(IDC_EDIT_Gas, &CMoneyManagerDlg::OnEnChangeEditGas)
	ON_EN_CHANGE(IDC_EDIT_ETC, &CMoneyManagerDlg::OnEnChangeEditEtc)
	ON_EN_CHANGE(IDC_EDIT_CARD, &CMoneyManagerDlg::OnEnChangeEditCard)
	ON_EN_CHANGE(IDC_EDIT_INCOME, &CMoneyManagerDlg::OnEnChangeEditIncome)
	ON_EN_CHANGE(IDC_EDIT_TRANSPORT, &CMoneyManagerDlg::OnEnChangeEditTransport)
END_MESSAGE_MAP()


// CMoneyManagerDlg 메시지 처리기

BOOL CMoneyManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_edCard.SetWindowText(_T("0"));
	m_edElectro.SetWindowText(_T("0"));
	m_edETC.SetWindowText(_T("0"));
	m_edGAS.SetWindowText(_T("0"));
	m_edInsurance.SetWindowText(_T("0"));
	m_edRent.SetWindowText(_T("0"));
	m_edRentManage.SetWindowText(_T("0"));
	m_edRest.SetWindowText(_T("0"));
	m_edTele.SetWindowText(_T("0"));
	m_edIncome.SetWindowText(_T("0"));
	m_edTrasnport.SetWindowText(_T("0"));
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMoneyManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMoneyManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMoneyManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMoneyManagerDlg::OnEnChangeEditRent()
{
	GetRest();	
}


void CMoneyManagerDlg::OnEnChangeEditRentManage()
{
	GetRest();
}


void CMoneyManagerDlg::OnEnChangeEditInsurance()
{
	GetRest();
}


void CMoneyManagerDlg::OnEnChangeEditTele()
{
	GetRest();
}


void CMoneyManagerDlg::OnEnChangeEditElectro()
{
	GetRest();
}


void CMoneyManagerDlg::OnEnChangeEditGas()
{
	GetRest();
}


void CMoneyManagerDlg::OnEnChangeEditEtc()
{
	GetRest();
}


void CMoneyManagerDlg::OnEnChangeEditCard()
{
	GetRest();
}

int CMoneyManagerDlg::GetIncome()
{
	CString sIncome;
	m_edIncome.GetWindowText(sIncome);
	int iincome = _ttoi(sIncome);
	return iincome;
}

int CMoneyManagerDlg::GetSave()
{
	CString sSave;
	m_edRest.GetWindowText(sSave);
	int iSave = _ttoi(sSave);
	return iSave;
}

void CMoneyManagerDlg::SetRest(int iRest)
{
	CString sRest;
	sRest.Format(_T("%d"), iRest);
	m_edRest.SetWindowText(sRest);
}

void CMoneyManagerDlg::GetRest()
{
	CEdit* pEdit[9] = { &m_edRent, &m_edRentManage, &m_edInsurance, &m_edTele, &m_edElectro, &m_edGAS, &m_edETC, &m_edCard, &m_edTrasnport };
	CString sValue;
	CString sIncome;
	int iIncome = 0;
	int iRest = 0;
	int iTotalSpend = 0;
	int iTotalFix = 0;
	m_edIncome.GetWindowText(sIncome);
	iRest = _ttoi(sIncome);
	iIncome = iRest;
	for (int i = 0; i < 9; i++)
	{
		pEdit[i]->GetWindowText(sValue);
		int iValue = _ttoi(sValue);
		iRest -= iValue;
		iTotalSpend += iValue;
		iTotalFix += iValue;
		if (pEdit[i] == &m_edCard)
		{
			iTotalFix -= iValue;
		}
	}

	CString sRest,sTotalSpend,sTotalFix;
	sRest.Format(_T("%d"), iRest);
	sTotalSpend.Format(_T("%d"), iTotalSpend);
	sTotalFix.Format(_T("%d"), iTotalFix);
	
	m_edRest.SetWindowText(sRest);
	m_edTotalSpend.SetWindowText(sTotalSpend);
	m_edTotalFix.SetWindowText(sTotalFix);

	float fRatio = 0.0f;
	fRatio = ((float)iRest / ((float)iIncome / 100));
	CString sRatio;
	sRatio.Format(_T("수입의 %0.2f를 저축할 수 있습니다."), fRatio);
	m_stCanSave.SetWindowText(sRatio);
}


void CMoneyManagerDlg::OnEnChangeEditIncome()
{
	GetRest();
}


void CMoneyManagerDlg::OnEnChangeEditTransport()
{
	GetRest();
}
