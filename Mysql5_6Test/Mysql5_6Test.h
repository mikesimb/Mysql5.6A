
// Mysql5_6Test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMysql5_6TestApp: 
// �йش����ʵ�֣������ Mysql5_6Test.cpp
//

class CMysql5_6TestApp : public CWinApp
{
public:
	CMysql5_6TestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMysql5_6TestApp theApp;