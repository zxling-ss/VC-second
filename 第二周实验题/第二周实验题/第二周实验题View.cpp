
// �ڶ���ʵ����View.cpp : C�ڶ���ʵ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ʵ����.h"
#endif

#include "�ڶ���ʵ����Doc.h"
#include "�ڶ���ʵ����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���ʵ����View

IMPLEMENT_DYNCREATE(C�ڶ���ʵ����View, CView)

BEGIN_MESSAGE_MAP(C�ڶ���ʵ����View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C�ڶ���ʵ����View ����/����

C�ڶ���ʵ����View::C�ڶ���ʵ����View()
{
	// TODO: �ڴ˴���ӹ������
	count = 0;


}

C�ڶ���ʵ����View::~C�ڶ���ʵ����View()
{
}

BOOL C�ڶ���ʵ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}


// C�ڶ���ʵ����View ����


//����ʵ���⡡
//
//(1) �����ɻ���MFC�ĵ���ͼ�ṹ�ĳ����ܣ���OnDraw�����ж���һ���ַ�������S������ֵΪ_T("����***")���������ͱ���A������ֵ��Ȼ���ڿͻ������S��A
//
//(2)���������б�������͸���ֵ�ŵ��ĵ����У�Ȼ���ڿͻ������S��A
//
//(3)�����ɳ����ܣ���Doc���м�int�����ݳ�Աcount����ʼ��Ϊ0������������������ۼƵ��������count��, �Ҽ������ʾcount��ֵ��
void C�ڶ���ʵ����View::OnDraw(CDC* pDC)
{
	C�ڶ���ʵ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	int A = 520;
	s.Format(_T("����ZXL,%d"),A);
	CClientDC dc(this);
	pDC->TextOutW(200, 300, s);
	
	s.Format(pDoc->ss+_T("  %d"), pDoc->a);
	pDC->TextOutW(200, 100, s);
}


// C�ڶ���ʵ����View ���

#ifdef _DEBUG
void C�ڶ���ʵ����View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���ʵ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���ʵ����Doc* C�ڶ���ʵ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���ʵ����Doc)));
	return (C�ڶ���ʵ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���ʵ����View ��Ϣ�������
//
//һ������(��2.1��ʵ�鲿����Ƶ��ȡ�����λ��)
//
//(1)����Ӧ�����
//
//(2)    ��ֵ�ͱ�����ֵת�����ַ�����������s.Format("%d", count)
void C�ڶ���ʵ����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//count++;
	//CString s;
	//s.Format(_T("���λ����(%d,%d)���������:%d"), point.x, point.y,count);
	//CClientDC dc(this);
	//dc.TextOutW(100, 200, s);
	C�ڶ���ʵ����Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void C�ڶ���ʵ����View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�ڶ���ʵ����Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(100, 400, s);
	CView::OnRButtonDown(nFlags, point);
}
