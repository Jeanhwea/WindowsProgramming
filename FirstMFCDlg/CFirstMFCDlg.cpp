
// CFirstMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FirstMFCDlg.h"
#include "CFirstMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFirstMFCDlg �Ի���



CFirstMFCDlg::CFirstMFCDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CFirstMFCDlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFirstMFCDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFirstMFCDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDOK, &CFirstMFCDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CFirstMFCDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CFirstMFCDlg ��Ϣ�������

BOOL CFirstMFCDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);         // ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);        // ����Сͼ��

    // TODO: �ڴ���Ӷ���ĳ�ʼ������

    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFirstMFCDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFirstMFCDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



void CFirstMFCDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CDialogEx::OnOK();
    CString msg;
    GetDlgItemText(IDC_EDIT1, msg);
    MessageBox(msg, TEXT("tilte"), NULL);
}


void CFirstMFCDlg::OnBnClickedCancel()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CDialogEx::OnCancel();
}
