#include "stdafx.h"
#include "MySql.h"
#include <stdio.h>


CMySql::CMySql()
{
	m_mysql = NULL;
	m_username = "";
	m_ip = "";
	m_pass = "";
	m_port = 3306;
	
}


CMySql::~CMySql()
{
}

bool CMySql::Initialize()
{
	m_mysql = mysql_init(m_mysql);
	return m_mysql != NULL;
}

bool CMySql::Connect()
{
	bool res =   (mysql_real_connect(m_mysql, m_ip.c_str(), m_username.c_str(), m_pass.c_str(), "", m_port, NULL, 0) != NULL);
//	if (mysqlConnected != NULL)
	bConnected = res;
	mysqlConnected(this,res);
	return res;

}

void CMySql::getdbs_name()
{
	if (m_mysql)
	{
		m_db_namelist.clear();
		char * dbname = NULL;
		MYSQL_RES * res = mysql_list_dbs(m_mysql, dbname);
		MYSQL_ROW  row;
		ULONG colLen = mysql_num_fields(res);

		while (row = mysql_fetch_row(res)) // 遍历每行记录
		{
			for (ULONG i = 0; i < colLen; i++)
			{
				string name = row[i] ? row[i] : "NULL";
				m_db_namelist.push_back(name);
			}
		}
		mysql_get_DBNames(this);
	}
}

void CMySql::setHostIp(char* Ipaddress)
{
	m_ip = Ipaddress;

}

void CMySql::setPassword(char* Pass)
{
	m_pass = Pass;
}

void CMySql::setUsername(char * name)
{
	m_username = name;

}

void CMySql::setPort(int port)
{
	m_port = port;
}


void CMySql::SetMysqlConnectedEvent(const OnMysqlEvent& callback)
{
	mysqlConnected = callback;
}

bool CMySql::DropDataBase(char* dbname)
{
	if (bConnected)
	{
		char sql[255] = { "\0" };
		sprintf_s(sql, 255, "Drop Database %s", dbname);
		if (mysql_query(m_mysql, sql) == 0)
		{
			getdbs_name();
			return true;
		}
		else
		{
			return false;
		}

	}
	else
		return false;

}



bool CMySql::CreateDataBase(char* dbname)
{
	//判断当前是否处于连接状态
	if (bConnected)
	{
		//执行创建数据库的代码
#ifdef USE_OLD_FUNCTIONS
		if (mysql_create_db(m_mysql, dbname)!= 0)
		{
			return false;
		}
		else
		{
			getdbs_name();
			return true;
		}
#else
		char sql[255] = { "\0" };
		sprintf_s(sql, 255, "Create Database %s", dbname);
		if (mysql_query(m_mysql, sql) == 0)
		{
			getdbs_name();
			return true;
		}
		else
		{
			return false;
		}
#endif
	}
	else
		return  false;

}

void CMySql::SetMysqlGetDBNameEvent(const OnMysqlEventA& callback)
{
	mysql_get_DBNames = callback;
}

const char * CMySql::getDBName(int index)
{
	vector<string>::iterator it;
	it = m_db_namelist.begin() + index;
	return it->c_str();

}

