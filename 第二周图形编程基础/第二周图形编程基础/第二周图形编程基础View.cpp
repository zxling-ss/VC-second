
// �ڶ���ͼ�α�̻���View.cpp : C�ڶ���ͼ�α�̻���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ͼ�α�̻���.h"
#endif

#include "�ڶ���ͼ�α�̻���Doc.h"
#include "�ڶ���ͼ�α�̻���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���ͼ�α�̻���View

IMPLEMENT_DYNCREATE(C�ڶ���ͼ�α�̻���View, CView)

BEGIN_MESSAGE_MAP(C�ڶ���ͼ�α�̻���View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C�ڶ���ͼ�α�̻���View ����/����

C�ڶ���ͼ�α�̻���View::C�ڶ���ͼ�α�̻���View()
{
	// TODO: �ڴ˴���ӹ������
	
	
}

C�ڶ���ͼ�α�̻���View::~C�ڶ���ͼ�α�̻���View()
{
}

BOOL C�ڶ���ͼ�α�̻���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڶ���ͼ�α�̻���View ����

//(2) �Ľ�����ĳ���ʹ�����ػ��������Բ��Ȼ��ʾ����;	

void C�ڶ���ͼ�α�̻���View::OnDraw(CDC* pDC)
{
	C�ڶ���ͼ�α�̻���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	int n = x.GetCount();
	for (int i = 0; i < n;i++)
		pDC->Ellipse(x[i] - R[i], y[i] - R[i], x[i] + R[i], y[i]+ R[i]);
}


// C�ڶ���ͼ�α�̻���View ��ӡ

BOOL C�ڶ���ͼ�α�̻���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ڶ���ͼ�α�̻���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ڶ���ͼ�α�̻���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ڶ���ͼ�α�̻���View ���

#ifdef _DEBUG
void C�ڶ���ͼ�α�̻���View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���ͼ�α�̻���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���ͼ�α�̻���Doc* C�ڶ���ͼ�α�̻���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���ͼ�α�̻���Doc)));
	return (C�ڶ���ͼ�α�̻���Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���ͼ�α�̻���View ��Ϣ�������

//(1) ����ڿͻ�������������Ըõ�Ϊ���ģ��������Ϊ�뾶��Բ�� [��ʾ: Ellipse(),  rand()%(b-a)+a ]

void C�ڶ���ͼ�α�̻���View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC *pDC = this->GetDC();
	int a = point.x;
	int b = point.y;
	int r = rand() % (b - a) + a;
	if(r>0&&r<=1000)
		pDC->Ellipse(point.x-r,point.y-r,point.x+r,point.y+r);
	
	x.Add(point.x);
	y.Add(point.y);
	R.Add(r);


	ReleaseDC(pDC);

	CView::OnLButtonDown(nFlags, point);
}

//(3) ���Կͻ�������ΪԲ�ĵ���Բ����ʹ��Բ��߽����� ;
//(4) �Բ�ɫ�����Բ�ڲ���[��ʾ: ���컭ˢ��ѡ��DC�У��ٻ���Բ]

void C�ڶ���ͼ�α�̻���View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);					//����һ��CClientDC�Ķ���dc
	
	CRect rc;						//����һ���������εĶ���rc
	GetClientRect(&rc);
	CBrush newBrush(RGB(125, 125, 125));			//�����»�ˢ
	CBrush* oldBrush = dc.SelectObject(&newBrush);		//�����»�ˢ���Ѿͻ�˵����ָ��

	dc.Ellipse(rc.right, rc.left, rc.top, rc.bottom);     //�Կͻ��������ϽǺ����½�����������ƾ���
	dc.SelectObject(oldBrush);			//��ʹ���»�ˢ��������֮�󣬻ָ�ԭ��ˢ
	CView::OnRButtonDown(nFlags, point);
}
