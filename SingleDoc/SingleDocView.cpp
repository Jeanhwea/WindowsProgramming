
// SingleDocView.cpp : CSingleDocView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SingleDoc.h"
#endif

#include "SingleDocDoc.h"
#include "SingleDocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDocView

IMPLEMENT_DYNCREATE(CSingleDocView, CView)

BEGIN_MESSAGE_MAP(CSingleDocView, CView)
END_MESSAGE_MAP()

// CSingleDocView ����/����

CSingleDocView::CSingleDocView()
{
    // TODO: �ڴ˴���ӹ������

}

CSingleDocView::~CSingleDocView()
{
}

BOOL CSingleDocView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: �ڴ˴�ͨ���޸�
    //  CREATESTRUCT cs ���޸Ĵ��������ʽ

    return CView::PreCreateWindow(cs);
}

// CSingleDocView ����

void CSingleDocView::OnDraw(CDC* /*pDC*/)
{
    CSingleDocDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSingleDocView ���

#ifdef _DEBUG
void CSingleDocView::AssertValid() const
{
    CView::AssertValid();
}

void CSingleDocView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CSingleDocDoc* CSingleDocView::GetDocument() const // �ǵ��԰汾��������
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDocDoc)));
    return (CSingleDocDoc*)m_pDocument;
}
#endif //_DEBUG


// CSingleDocView ��Ϣ�������
