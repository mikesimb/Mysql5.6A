
// Mysql5_6TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Mysql5_6Test.h"
#include "Mysql5_6TestDlg.h"
#include "afxdialogex.h"

// #include <mysql.h>
// 
// #pragma comment(lib,"libmysql")
#include "MySql.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMysql5_6TestDlg 对话框



CMysql5_6TestDlg::CMysql5_6TestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMysql5_6TestDlg::IDD, pParent)
	, m_db_Name(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMysql5_6TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_db_list);
	DDX_Text(pDX, IDC_EDIT1, m_db_Name);
}

BEGIN_MESSAGE_MAP(CMysql5_6TestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMysql5_6TestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMysql5_6TestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMysql5_6TestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMysql5_6TestDlg::OnBnClickedButton3)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMysql5_6TestDlg 消息处理程序

BOOL CMysql5_6TestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMysql5_6TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMysql5_6TestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMysql5_6TestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMysql5_6TestDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMysql5_6TestDlg::OnMySqlConnected(CMySql* mysql, bool Connected)
{
	if (Connected)
		MessageBox("MySql connect is successed!");
	else
		MessageBox("Mysql Connect is Failed");
}


void CMysql5_6TestDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//连接数据库服务器的代码
// 	MYSQL * g_mysql = NULL;
// 	g_mysql = mysql_init(g_mysql);
// 	if (g_mysql != NULL)
// 	{
// 		MessageBox(L"MySql init is successed!");
// 	    mysql_real_connect(g_mysql, "127.0.0.1", "root", "zzw780517..","",3306,NULL,0);
// 		if (g_mysql != NULL)
// 		{
// 			MessageBox(L"MySql connect is successed!");
// 			char * dbname = NULL;
// 			MYSQL_RES * res = mysql_list_dbs(g_mysql, dbname);
// 			MYSQL_ROW  row;
// 			ULONG colLen = mysql_num_fields(res);
// 			
// 			while (row = mysql_fetch_row(res)) // 遍历每行记录
// 			{
// 				for (ULONG i = 0; i < colLen; i++)
// 				{
// 					CString datas("");
// 					datas += row[i] ? row[i] : "NULL";
// 					datas += "\t";
// 					m_db_list.AddString(datas.GetString());
// 				}
// 				//datas += "\n\n";
// 			}
// 		}
// 	}
// 	else
// 		MessageBox(L"MYSQL INIT IS Failed");

     mysql = new CMySql;
	mysql->Initialize();
	mysql->setHostIp("127.0.0.1");
	mysql->setUsername("root");
	mysql->setPassword("zzw780517..");
//	mysql->SetMysqlCallback(this);
	mysql->SetMysqlConnectedEvent(std::bind(&CMysql5_6TestDlg::OnMySqlConnected, this, std::placeholders::_1, std::placeholders::_2));
	mysql->SetMysqlGetDBNameEvent(std::bind(&CMysql5_6TestDlg::OnMysqlGetDBListFinished, this, std::placeholders::_1));

    mysql->Connect();
	mysql->getdbs_name();
	//std::bind(&CMysql5_6TestDlg::onMysqlConnected, this, std::placeholders::_1);
	mysql->getTableName();

}

void CMysql5_6TestDlg::OnMysqlGetDBListFinished(CMySql * Mysql)
{
	m_db_list.ResetContent();
	for (int i = 0; i < Mysql->getDBCount(); i++)
	{
		const char * p = Mysql->getDBName(i);
	
		char name[255];
		strcpy_s(name, p);
		if (i == 4)

		if (mysql->selectDB(name))
			OutputDebugString("select DB success");
		m_db_list.AddString((LPCTSTR)name);
	}
}


void CMysql5_6TestDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData();
	mysql->CreateDataBase((char *)m_db_Name.GetString());
}



void CMysql5_6TestDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_db_list.GetCurSel();
	CString dbname = "";
	m_db_list.GetText(index, dbname);
	mysql->DropDataBase((char*)dbname.GetString());
}


void CMysql5_6TestDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	delete(mysql);
	CDialogEx::OnClose();
}
