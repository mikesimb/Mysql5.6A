
// Mysql5_6TestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "MySql.h"


// CMysql5_6TestDlg 对话框
class CMysql5_6TestDlg : public CDialogEx
{
// 构造
public:
	CMysql5_6TestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYSQL5_6TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	CMySql * mysql;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CListBox m_db_list;

	void OnMySqlConnected(CMySql* mysql,bool Connected);
	void OnMysqlGetDBListFinished(CMySql * Mysql);
	

	afx_msg void OnBnClickedButton3();
	CString m_db_Name;
};
