
// �ڶ���ͼ�α�̻���View.h : C�ڶ���ͼ�α�̻���View ��Ľӿ�
//

#pragma once


class C�ڶ���ͼ�α�̻���View : public CView
{
protected: // �������л�����
	C�ڶ���ͼ�α�̻���View();
	DECLARE_DYNCREATE(C�ڶ���ͼ�α�̻���View)

// ����
public:
	C�ڶ���ͼ�α�̻���Doc* GetDocument() const;
	
// ����
public:

	CArray<int, int> x;
	CArray<int, int> y;
	CArray<int, int> R;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�ڶ���ͼ�α�̻���View();
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

#ifndef _DEBUG  // �ڶ���ͼ�α�̻���View.cpp �еĵ��԰汾
inline C�ڶ���ͼ�α�̻���Doc* C�ڶ���ͼ�α�̻���View::GetDocument() const
   { return reinterpret_cast<C�ڶ���ͼ�α�̻���Doc*>(m_pDocument); }
#endif

