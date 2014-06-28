
// Mysql5_6TestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "MySql.h"


// CMysql5_6TestDlg �Ի���
class CMysql5_6TestDlg : public CDialogEx
{
// ����
public:
	CMysql5_6TestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYSQL5_6TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	CMySql * mysql;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
