
// �ڶ���ʵ����.h : �ڶ���ʵ���� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڶ���ʵ����App:
// �йش����ʵ�֣������ �ڶ���ʵ����.cpp
//

class C�ڶ���ʵ����App : public CWinApp
{
public:
	C�ڶ���ʵ����App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڶ���ʵ����App theApp;
