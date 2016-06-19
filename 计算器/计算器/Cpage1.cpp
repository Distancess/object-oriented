// Cpage1.cpp : 实现文件
//

#include "stdafx.h"
#include "计算器.h"
#include "Cpage1.h"
#include "afxdialogex.h"
#include "Calculator.h"
#include <atlconv.h>


// Cpage1 对话框

IMPLEMENT_DYNAMIC(Cpage1, CDialog)

Cpage1::Cpage1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_Page1, pParent)
    , m_result(_T(""))
{

}

Cpage1::~Cpage1()
{
}

void Cpage1::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_result);
}


BEGIN_MESSAGE_MAP(Cpage1, CDialog)
    ON_BN_CLICKED(IDC_BUTTON1, &Cpage1::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &Cpage1::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &Cpage1::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON4, &Cpage1::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON5, &Cpage1::OnBnClickedButton5)
    ON_BN_CLICKED(IDC_BUTTON6, &Cpage1::OnBnClickedButton6)
    ON_BN_CLICKED(IDC_BUTTON7, &Cpage1::OnBnClickedButton7)
    ON_BN_CLICKED(IDC_BUTTON8, &Cpage1::OnBnClickedButton8)
    ON_BN_CLICKED(IDC_BUTTON9, &Cpage1::OnBnClickedButton9)
    ON_BN_CLICKED(IDC_BUTTON20, &Cpage1::OnBnClickedButton20)
    ON_BN_CLICKED(IDC_BUTTON19, &Cpage1::OnBnClickedButton19)
    ON_BN_CLICKED(IDC_BUTTON10, &Cpage1::OnBnClickedButton10)
    ON_BN_CLICKED(IDC_BUTTON11, &Cpage1::OnBnClickedButton11)
    ON_BN_CLICKED(IDC_BUTTON12, &Cpage1::OnBnClickedButton12)
    ON_BN_CLICKED(IDC_BUTTON13, &Cpage1::OnBnClickedButton13)
    ON_BN_CLICKED(IDC_BUTTON14, &Cpage1::OnBnClickedButton14)
    ON_BN_CLICKED(IDC_BUTTON15, &Cpage1::OnBnClickedButton15)
    ON_BN_CLICKED(IDC_BUTTON16, &Cpage1::OnBnClickedButton16)
    ON_BN_CLICKED(IDC_BUTTON17, &Cpage1::OnBnClickedButton17)
    ON_BN_CLICKED(IDC_BUTTON18, &Cpage1::OnBnClickedButton18)
    ON_EN_CHANGE(IDC_EDIT1, &Cpage1::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Cpage1 消息处理程序


void Cpage1::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    m_result += _T("1");//unicode编码需要对_T()对字符串进行操作
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton2()
{
    m_result += _T("2");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton3()
{
    m_result += _T("3");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton4()
{
    m_result += _T("4");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton5()
{
    m_result += _T("5");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton6()
{
    m_result += _T("6");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton7()
{
    m_result += _T("7");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton8()
{
    m_result += _T("8");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton9()
{
    m_result += _T("9");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton20()
{
    m_result += _T("0");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton19()
{
    m_result += _T(".");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton10()//ESC按钮
{
    m_result = "";
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton11()//Backspace 按钮
{
    CString tmp;
    tmp = "";
    int l = m_result.GetLength();
    for (int i = 0; i < l - 1; i++)
    {
        tmp += m_result[i];
    }
    m_result = tmp;
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton12()
{
    m_result += _T("(");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton13()
{
    m_result += _T(")");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton14()
{
    m_result += _T("/");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton15()
{
    m_result += _T("*");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton16()
{
    m_result += _T("-");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton17()
{
    m_result += _T("+");
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton18()// = 按钮
{
    CString str;
    //---- 0 CString->String
    if (m_result == "")
    {
        m_result += "0=";
    }
    else
    {
        m_result += "=";
    }
    str = m_result;
    USES_CONVERSION;
    string input = W2CA((LPCWSTR)m_result);
    //---- 1 Calculate
    Calculator c;
    Scanner s;

    answer = c.Calculater(input);
    if (s.IsError() == true)
    {
        m_result = _T("ERROR");
        UpdateData(FALSE);
    }
    else
    {
        if (c.IsError() == false)
        {
            m_result.Format(_T("%.2lf"), answer);
            str += m_result;
            m_result = str;
            UpdateData(FALSE);
            ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
        }
        else
        {
            m_result = _T("ERROR");
            UpdateData(FALSE);
            ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
        }
    }
    m_result = _T("");
}


BOOL Cpage1::PreTranslateMessage(MSG* pMsg)
{
    //判断是否为键盘消息
    if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
    {
        if (pMsg->message == WM_KEYDOWN)
        {
            switch (pMsg->wParam)
            {
                /*VK_NUMPAD0-VK_NUMPAD9分别对应小键盘0-9*/
                /*VK_0-VK_9分别对应数字键盘0-9*/
            case VK_NUMPAD0:
                OnBnClickedButton20(); break;
            case VK_NUMPAD1:
            case VK_1:
                OnBnClickedButton1(); break;
            case VK_2:
            case VK_NUMPAD2:
                OnBnClickedButton2(); break;
            case VK_3:
            case VK_NUMPAD3:
                OnBnClickedButton3(); break;
            case VK_4:
            case VK_NUMPAD4:
                OnBnClickedButton4(); break;
            case VK_5:
            case VK_NUMPAD5:
                OnBnClickedButton5(); break;
            case VK_6:
            case VK_NUMPAD6:
                OnBnClickedButton6(); break;
            case VK_7:
            case VK_NUMPAD7:
                OnBnClickedButton7(); break;
            case VK_NUMPAD8:
                OnBnClickedButton8(); break;
            case VK_NUMPAD9:
                OnBnClickedButton9(); break;
            case VK_8:
                if (GetKeyState(VK_SHIFT) < 0)
                {
                    OnBnClickedButton15();//判断是否是组合键 (shift + 8)-> ('*')
                }
                else
                {
                    OnBnClickedButton8();
                }
                break;
            case VK_9:
                if (GetKeyState(VK_SHIFT) < 0)//判断是否是组合键 (shift + 9)-> ('(')
                {
                    OnBnClickedButton12();
                }
                else
                {
                    OnBnClickedButton9();
                }
                break;
            case VK_0:
                if (GetKeyState(VK_SHIFT) < 0)//判断是否是组合键 (shift + 0)-> (')')
                {
                    OnBnClickedButton13();
                }
                else
                {
                    OnBnClickedButton20();
                }
                break;
            case VK_OEM_PLUS://  键盘 +  号键
                if (GetKeyState(VK_SHIFT) < 0)
                {
                    OnBnClickedButton17();
                }
                else
                {
                    OnBnClickedButton18();
                }
                break;
                // 键盘 ' .。'键
            case VK_OEM_PERIOD:
            case VK_DECIMAL:
                OnBnClickedButton19(); break;
                //  － 号键
            case VK_SUBTRACT:
            case VK_OEM_MINUS:
                OnBnClickedButton16(); break;
                //   键盘上？/键
            case VK_DIVIDE:
            case VK_OEM_2:
                OnBnClickedButton14(); break;
                //  +  号键
            case VK_ADD:
                OnBnClickedButton17(); break;
                //   *  号键
            case VK_MULTIPLY:
                OnBnClickedButton15(); break;
                //  退格键  <===>  Backspace
            case VK_BACK:
                OnBnClickedButton11(); break;
                //   回车键
            case VK_RETURN:
                OnBnClickedButton18(); return TRUE;
                //   ESC键
            case VK_ESCAPE:
                OnBnClickedButton10(); return TRUE;
            default:
                break;
            }
        }
    }
    return CDialog::PreTranslateMessage(pMsg);
}

void Cpage1::OnEnChangeEdit1()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialog::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}
