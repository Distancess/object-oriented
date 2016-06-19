// Cpage1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������.h"
#include "Cpage1.h"
#include "afxdialogex.h"
#include "Calculator.h"
#include <atlconv.h>


// Cpage1 �Ի���

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


// Cpage1 ��Ϣ�������


void Cpage1::OnBnClickedButton1()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    m_result += _T("1");//unicode������Ҫ��_T()���ַ������в���
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


void Cpage1::OnBnClickedButton10()//ESC��ť
{
    m_result = "";
    UpdateData(FALSE);
    ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(m_result.GetLength(), m_result.GetLength(), FALSE);
}


void Cpage1::OnBnClickedButton11()//Backspace ��ť
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


void Cpage1::OnBnClickedButton18()// = ��ť
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
    //�ж��Ƿ�Ϊ������Ϣ
    if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
    {
        if (pMsg->message == WM_KEYDOWN)
        {
            switch (pMsg->wParam)
            {
                /*VK_NUMPAD0-VK_NUMPAD9�ֱ��ӦС����0-9*/
                /*VK_0-VK_9�ֱ��Ӧ���ּ���0-9*/
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
                    OnBnClickedButton15();//�ж��Ƿ�����ϼ� (shift + 8)-> ('*')
                }
                else
                {
                    OnBnClickedButton8();
                }
                break;
            case VK_9:
                if (GetKeyState(VK_SHIFT) < 0)//�ж��Ƿ�����ϼ� (shift + 9)-> ('(')
                {
                    OnBnClickedButton12();
                }
                else
                {
                    OnBnClickedButton9();
                }
                break;
            case VK_0:
                if (GetKeyState(VK_SHIFT) < 0)//�ж��Ƿ�����ϼ� (shift + 0)-> (')')
                {
                    OnBnClickedButton13();
                }
                else
                {
                    OnBnClickedButton20();
                }
                break;
            case VK_OEM_PLUS://  ���� +  �ż�
                if (GetKeyState(VK_SHIFT) < 0)
                {
                    OnBnClickedButton17();
                }
                else
                {
                    OnBnClickedButton18();
                }
                break;
                // ���� ' .��'��
            case VK_OEM_PERIOD:
            case VK_DECIMAL:
                OnBnClickedButton19(); break;
                //  �� �ż�
            case VK_SUBTRACT:
            case VK_OEM_MINUS:
                OnBnClickedButton16(); break;
                //   �����ϣ�/��
            case VK_DIVIDE:
            case VK_OEM_2:
                OnBnClickedButton14(); break;
                //  +  �ż�
            case VK_ADD:
                OnBnClickedButton17(); break;
                //   *  �ż�
            case VK_MULTIPLY:
                OnBnClickedButton15(); break;
                //  �˸��  <===>  Backspace
            case VK_BACK:
                OnBnClickedButton11(); break;
                //   �س���
            case VK_RETURN:
                OnBnClickedButton18(); return TRUE;
                //   ESC��
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
    // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
    // ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
    // ���������� CRichEditCtrl().SetEventMask()��
    // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}
