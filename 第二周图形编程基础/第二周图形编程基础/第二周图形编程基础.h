
// �ڶ���ͼ�α�̻���.h : �ڶ���ͼ�α�̻��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڶ���ͼ�α�̻���App:
// �йش����ʵ�֣������ �ڶ���ͼ�α�̻���.cpp
//

class C�ڶ���ͼ�α�̻���App : public CWinApp
{
public:
	C�ڶ���ͼ�α�̻���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڶ���ͼ�α�̻���App theApp;
