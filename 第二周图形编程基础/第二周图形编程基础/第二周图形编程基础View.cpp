
// 第二周图形编程基础View.cpp : C第二周图形编程基础View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二周图形编程基础.h"
#endif

#include "第二周图形编程基础Doc.h"
#include "第二周图形编程基础View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二周图形编程基础View

IMPLEMENT_DYNCREATE(C第二周图形编程基础View, CView)

BEGIN_MESSAGE_MAP(C第二周图形编程基础View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C第二周图形编程基础View 构造/析构

C第二周图形编程基础View::C第二周图形编程基础View()
{
	// TODO: 在此处添加构造代码
	
	
}

C第二周图形编程基础View::~C第二周图形编程基础View()
{
}

BOOL C第二周图形编程基础View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第二周图形编程基础View 绘制

//(2) 改进上面的程序，使窗口重绘后，所画的圆仍然显示出来;	

void C第二周图形编程基础View::OnDraw(CDC* pDC)
{
	C第二周图形编程基础Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int n = x.GetCount();
	for (int i = 0; i < n;i++)
		pDC->Ellipse(x[i] - R[i], y[i] - R[i], x[i] + R[i], y[i]+ R[i]);
}


// C第二周图形编程基础View 打印

BOOL C第二周图形编程基础View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第二周图形编程基础View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第二周图形编程基础View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第二周图形编程基础View 诊断

#ifdef _DEBUG
void C第二周图形编程基础View::AssertValid() const
{
	CView::AssertValid();
}

void C第二周图形编程基础View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二周图形编程基础Doc* C第二周图形编程基础View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二周图形编程基础Doc)));
	return (C第二周图形编程基础Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二周图形编程基础View 消息处理程序

//(1) 鼠标在客户区点击，画出以该点为中心，以随机数为半径的圆； [提示: Ellipse(),  rand()%(b-a)+a ]

void C第二周图形编程基础View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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

//(3) 作以客户区中心为圆心的椭圆，并使椭圆与边界相切 ;
//(4) 以彩色填充椭圆内部。[提示: 构造画刷后选入DC中，再画椭圆]

void C第二周图形编程基础View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);					//定义一个CClientDC的对象dc
	
	CRect rc;						//定义一个描述矩形的对象rc
	GetClientRect(&rc);
	CBrush newBrush(RGB(125, 125, 125));			//创建新画刷
	CBrush* oldBrush = dc.SelectObject(&newBrush);		//载入新画刷并把就话说载入指针

	dc.Ellipse(rc.right, rc.left, rc.top, rc.bottom);     //以客户区的右上角和左下角两个坐标绘制矩形
	dc.SelectObject(oldBrush);			//在使用新画刷绘制线条之后，恢复原画刷
	CView::OnRButtonDown(nFlags, point);
}
