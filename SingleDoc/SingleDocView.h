
// SingleDocView.h : CSingleDocView ��Ľӿ�
//

#pragma once


class CSingleDocView : public CView
{
protected: // �������л�����
    CSingleDocView();
    DECLARE_DYNCREATE(CSingleDocView)

// ����
public:
    CSingleDocDoc* GetDocument() const;

// ����
public:

// ��д
public:
    virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
    virtual ~CSingleDocView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SingleDocView.cpp �еĵ��԰汾
inline CSingleDocDoc* CSingleDocView::GetDocument() const
   { return reinterpret_cast<CSingleDocDoc*>(m_pDocument); }
#endif

