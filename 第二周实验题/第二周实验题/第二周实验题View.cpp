
// 第二周实验题View.cpp : C第二周实验题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二周实验题.h"
#endif

#include "第二周实验题Doc.h"
#include "第二周实验题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二周实验题View

IMPLEMENT_DYNCREATE(C第二周实验题View, CView)

BEGIN_MESSAGE_MAP(C第二周实验题View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C第二周实验题View 构造/析构

C第二周实验题View::C第二周实验题View()
{
	// TODO: 在此处添加构造代码
	count = 0;


}

C第二周实验题View::~C第二周实验题View()
{
}

BOOL C第二周实验题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}


// C第二周实验题View 绘制


//二、实验题　
//
//(1) 　生成基于MFC文档视图结构的程序框架，在OnDraw函数中定义一个字符串变量S并赋初值为_T("我是***")，定义整型变量A并赋初值，然后在客户区输出S和A
//
//(2)　把上题中变量定义和赋初值放到文档类中，然后在客户区输出S和A
//
//(3)　生成程序框架，在Doc类中加int型数据成员count并初始化为0，鼠标左键连续点击，累计点击次数到count中, 右键点击显示count的值。
void C第二周实验题View::OnDraw(CDC* pDC)
{
	C第二周实验题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	int A = 520;
	s.Format(_T("我是ZXL,%d"),A);
	CClientDC dc(this);
	pDC->TextOutW(200, 300, s);
	
	s.Format(pDoc->ss+_T("  %d"), pDoc->a);
	pDC->TextOutW(200, 100, s);
}


// C第二周实验题View 诊断

#ifdef _DEBUG
void C第二周实验题View::AssertValid() const
{
	CView::AssertValid();
}

void C第二周实验题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二周实验题Doc* C第二周实验题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二周实验题Doc)));
	return (C第二周实验题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二周实验题View 消息处理程序
//
//一、讲解(见2.1　实验部分视频获取鼠标点击位置)
//
//(1)　响应鼠标点击
//
//(2)    数值型变量的值转化到字符串：方法：s.Format("%d", count)
void C第二周实验题View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//count++;
	//CString s;
	//s.Format(_T("点的位置是(%d,%d)，点击次数:%d"), point.x, point.y,count);
	//CClientDC dc(this);
	//dc.TextOutW(100, 200, s);
	C第二周实验题Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void C第二周实验题View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第二周实验题Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(100, 400, s);
	CView::OnRButtonDown(nFlags, point);
}
