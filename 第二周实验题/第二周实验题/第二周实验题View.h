
// �ڶ���ʵ����View.h : C�ڶ���ʵ����View ��Ľӿ�
//

#pragma once


class C�ڶ���ʵ����View : public CView
{
protected: // �������л�����
	C�ڶ���ʵ����View();
	DECLARE_DYNCREATE(C�ڶ���ʵ����View)

// ����
public:
	C�ڶ���ʵ����Doc* GetDocument() const;
	int count;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C�ڶ���ʵ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // �ڶ���ʵ����View.cpp �еĵ��԰汾
inline C�ڶ���ʵ����Doc* C�ڶ���ʵ����View::GetDocument() const
   { return reinterpret_cast<C�ڶ���ʵ����Doc*>(m_pDocument); }
#endif

