#pragma once
const int VK_0 = 0x30;
const int VK_1 = 0x31;
const int VK_2 = 0x32;
const int VK_3 = 0x33;
const int VK_4 = 0x34;
const int VK_5 = 0x35;
const int VK_6 = 0x36;
const int VK_7 = 0x37;
const int VK_8 = 0x38;
const int VK_9 = 0x39;

// Cpage1 对话框

class Cpage1 : public CDialog
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Page1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    double answer;
    CString m_result;
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton3();
    afx_msg void OnBnClickedButton4();
    afx_msg void OnBnClickedButton5();
    afx_msg void OnBnClickedButton6();
    afx_msg void OnBnClickedButton7();
    afx_msg void OnBnClickedButton8();
    afx_msg void OnBnClickedButton9();
    afx_msg void OnBnClickedButton20();
    afx_msg void OnBnClickedButton19();
    afx_msg void OnBnClickedButton10();
    afx_msg void OnBnClickedButton11();
    afx_msg void OnBnClickedButton12();
    afx_msg void OnBnClickedButton13();
    afx_msg void OnBnClickedButton14();
    afx_msg void OnBnClickedButton15();
    afx_msg void OnBnClickedButton16();
    afx_msg void OnBnClickedButton17();
    afx_msg void OnBnClickedButton18();
    BOOL PreTranslateMessage(MSG * pMsg);
    afx_msg void OnEnChangeEdit1();
};
