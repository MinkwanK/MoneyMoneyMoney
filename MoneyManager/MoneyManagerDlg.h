
// MoneyManagerDlg.h: 헤더 파일
//

#pragma once


// CMoneyManagerDlg 대화 상자
class CMoneyManagerDlg : public CDialogEx
{
// 생성입니다.
public:
	CMoneyManagerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MONEYMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edRent;
	CEdit m_edRentManage;
	CEdit m_edInsurance;
	CEdit m_edETC;
	CEdit m_edGAS;
	CEdit m_edElectro;
	CEdit m_edTele;
	CEdit m_edCard;
	CEdit m_edRest;
	CEdit m_edIncome;
	afx_msg void OnEnChangeEditRent();
	afx_msg void OnEnChangeEditRentManage();
	afx_msg void OnEnChangeEditInsurance();
	afx_msg void OnEnChangeEditTele();
	afx_msg void OnEnChangeEditElectro();
	afx_msg void OnEnChangeEditGas();
	afx_msg void OnEnChangeEditEtc();
	afx_msg void OnEnChangeEditCard();
	int GetIncome();
	int GetSave();
	void SetRest(int iRest);
	void GetRest();
	afx_msg void OnEnChangeEditIncome();
	afx_msg void OnEnChangeEditTransport();
	CEdit m_edTrasnport;
	CEdit m_edTotalFix;
	CEdit m_edTotalSpend;
	CStatic m_stCanSave;
};
