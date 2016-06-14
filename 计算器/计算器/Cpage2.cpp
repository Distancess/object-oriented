// Cpage2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������.h"
#include "Cpage2.h"
#include "afxdialogex.h"
#include "Calculator.h"
#include <fstream>
#include <atlconv.h>

using namespace std;


// Cpage2 �Ի���

IMPLEMENT_DYNAMIC(Cpage2, CDialog)

Cpage2::Cpage2(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_Page2, pParent)
    , gReadFilePathName(_T(""))
    , goutputFilePathName(_T(""))
{

}

Cpage2::~Cpage2()
{
}

void Cpage2::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, gReadFilePathName);
    DDX_Text(pDX, IDC_EDIT2, goutputFilePathName);
}


BEGIN_MESSAGE_MAP(Cpage2, CDialog)
    ON_BN_CLICKED(IDC_BUTTON1, &Cpage2::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON3, &Cpage2::OnBnClickedButton3)
    ON_EN_CHANGE(IDC_EDIT1, &Cpage2::OnEnChangeEdit1)
    ON_EN_CHANGE(IDC_EDIT1, &Cpage2::OnEnChangeEdit1)
    ON_EN_CHANGE(IDC_EDIT2, &Cpage2::OnEnChangeEdit2)
    ON_BN_CLICKED(IDC_BUTTON4, &Cpage2::OnBnClickedButton4)
END_MESSAGE_MAP()


// Cpage2 ��Ϣ�������


void Cpage2::OnBnClickedButton1()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CFileDialog fileDlg(true, _T("txt"), _T("*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("txt Files (*.txt)|*.tx|All File (*.*)|*.*||"), NULL);
    if (fileDlg.DoModal() == IDOK)    //�����Ի���  
    {
        gReadFilePathName = fileDlg.GetPathName();//�õ��������ļ�����Ŀ¼����չ��  
        GetDlgItem(IDC_EDIT1)->SetWindowText(gReadFilePathName);//��·����ʾ  
    }
}


void Cpage2::OnBnClickedButton4()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CFileDialog fileDlg(true, _T("txt"), _T("*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("txt Files (*.txt)|*.tx|All File (*.*)|*.*||"), NULL);
    if (fileDlg.DoModal() == IDOK)    //�����Ի���  
    {
        goutputFilePathName = fileDlg.GetPathName();//�õ��������ļ�����Ŀ¼����չ��  
        GetDlgItem(IDC_EDIT2)->SetWindowText(goutputFilePathName);//��·����ʾ  
    }
}


void Cpage2::OnBnClickedButton3()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    Calculator c;
    Scanner ss;

    //---- 3-1 �ļ���������; 
    ifstream in;
    ofstream out;

    //����.c_str()�����ַ�����Ϊ�ļ���;
    USES_CONVERSION;
    GetDlgItem(IDC_EDIT1)->GetWindowText(gReadFilePathName);
    GetDlgItem(IDC_EDIT2)->GetWindowText(goutputFilePathName);
    string read = W2CA((LPCWSTR)gReadFilePathName);
    string result  = W2CA((LPCWSTR)goutputFilePathName);
    in.open(read.c_str(), ios::in);
    out.open(result.c_str(), ios::out);

    //----3-2 �ļ��Ķ�д;
    while (!in.eof())
    {
        string input;
        input.clear();
        getline(in, input);
        if (input == "")
        {
            continue;
        }
        double ans = 0;
        ans = c.Calculater(input);

        //---- 3-2-1 �ж��Ƿ񳬳�ʮλ; 
        if (ss.IsError() == false)
        {
            //---- 3-2-2 �жϳ����Ƿ�Ϊ0; 
            if (c.IsError() == true)
            {
                out << "ERROR" << endl;
            }
            else
            {
                out << ans << endl;
            }
        }
        else
        {
            out << "ERROR" << endl;
        }
    }
    //-----3-3 �ر��ļ�; 
    in.close();
    out.close();
}



void Cpage2::OnEnChangeEdit1()
{
    // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
    // ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
    // ���������� CRichEditCtrl().SetEventMask()��
    // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cpage2::OnEnChangeEdit2()
{
    // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
    // ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
    // ���������� CRichEditCtrl().SetEventMask()��
    // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}


