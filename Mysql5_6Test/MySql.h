#pragma once
#include <string>
#include <mysql.h>
#include <vector>
#include <functional>


#pragma comment(lib,"libmysql")
using namespace std;
class CMySql;

typedef std::function<void(CMySql *,bool)> OnMysqlEvent;
typedef std::function<void(CMySql *)> OnMysqlEventA;
//#define CC_CALLBACK_1(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, ##__VA_ARGS__) 

class CMySql
{
public:
	CMySql();
	virtual ~CMySql();
public:
	//����MYSQL����Ҫ��ʼ��
	bool Initialize();
	//��Ҫ�����������ݿ�
	bool Connect();

	//�������ݿ��Ժ�����Ȼ�ȡ���ݿ��б�
	void getdbs_name();

	//���������ݿ�֮ǰ��Ҫ����һ������
	//setup begin
	void setUsername(char * name);
	void setPassword(char* Pass);
	void setHostIp(char* Ipaddress);
	void setPort(int port);
	//setup end

	int getDBCount(){ return m_db_namelist.size(); };
	const char * getDBName(int index);

	bool selectDB(char * dbname);
	bool getTableName();

	//*************
	//�¼��ҽӻ���
	void SetMysqlConnectedEvent(const OnMysqlEvent& callback);
	void SetMysqlGetDBNameEvent(const OnMysqlEventA& callback);
	//*************


	//�������ݿ�
	bool CreateDataBase(char* dbname);

	//ɾ�����ݿ�
	bool DropDataBase(char* dbname);


private:
	MYSQL * m_mysql;
	string m_username;
	string m_ip;
	string m_pass;
	int    m_port;

	vector<string> m_db_namelist;



	OnMysqlEvent mysqlConnected;

	OnMysqlEventA mysql_get_DBNames;

	bool bConnected;

	

	
};

