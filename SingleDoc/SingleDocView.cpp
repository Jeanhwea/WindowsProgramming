
// SingleDocView.cpp : CSingleDocView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CSingleDocView 构造/析构

CSingleDocView::CSingleDocView()
{
    // TODO: 在此处添加构造代码

}

CSingleDocView::~CSingleDocView()
{
}

BOOL CSingleDocView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: 在此处通过修改
    //  CREATESTRUCT cs 来修改窗口类或样式

    return CView::PreCreateWindow(cs);
}

// CSingleDocView 绘制

void CSingleDocView::OnDraw(CDC* /*pDC*/)
{
    CSingleDocDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO: 在此处为本机数据添加绘制代码
}


// CSingleDocView 诊断

#ifdef _DEBUG
void CSingleDocView::AssertValid() const
{
    CView::AssertValid();
}

void CSingleDocView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CSingleDocDoc* CSingleDocView::GetDocument() const // 非调试版本是内联的
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDocDoc)));
    return (CSingleDocDoc*)m_pDocument;
}
#endif //_DEBUG


// CSingleDocView 消息处理程序
