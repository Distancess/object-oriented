// Cpage2.cpp : 实现文件
//

#include "stdafx.h"
#include "计算器.h"
#include "Cpage2.h"
#include "afxdialogex.h"
#include "Calculator.h"
#include <fstream>
#include <atlconv.h>

using namespace std;


// Cpage2 对话框

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


// Cpage2 消息处理程序


void Cpage2::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    CFileDialog fileDlg(true, _T("txt"), _T("*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("txt Files (*.txt)|*.tx|All File (*.*)|*.*||"), NULL);
    if (fileDlg.DoModal() == IDOK)    //弹出对话框  
    {
        gReadFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
        GetDlgItem(IDC_EDIT1)->SetWindowText(gReadFilePathName);//将路径显示  
    }
}


void Cpage2::OnBnClickedButton4()
{
    // TODO: 在此添加控件通知处理程序代码
    CFileDialog fileDlg(true, _T("txt"), _T("*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("txt Files (*.txt)|*.tx|All File (*.*)|*.*||"), NULL);
    if (fileDlg.DoModal() == IDOK)    //弹出对话框  
    {
        goutputFilePathName = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名  
        GetDlgItem(IDC_EDIT2)->SetWindowText(goutputFilePathName);//将路径显示  
    }
}


void Cpage2::OnBnClickedButton3()
{
    // TODO: 在此添加控件通知处理程序代码
    Calculator c;
    Scanner ss;

    //---- 3-1 文件声明及打开; 
    ifstream in;
    ofstream out;

    //调用.c_str()接受字符串作为文件名;
    USES_CONVERSION;
    GetDlgItem(IDC_EDIT1)->GetWindowText(gReadFilePathName);
    GetDlgItem(IDC_EDIT2)->GetWindowText(goutputFilePathName);
    string read = W2CA((LPCWSTR)gReadFilePathName);
    string result  = W2CA((LPCWSTR)goutputFilePathName);
    in.open(read.c_str(), ios::in);
    out.open(result.c_str(), ios::out);

    //----3-2 文件的读写;
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

        //---- 3-2-1 判断是否超出十位; 
        if (ss.IsError() == false)
        {
            //---- 3-2-2 判断除数是否为0; 
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
    //-----3-3 关闭文件; 
    in.close();
    out.close();
}



void Cpage2::OnEnChangeEdit1()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialog::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}


void Cpage2::OnEnChangeEdit2()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialog::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码
}


