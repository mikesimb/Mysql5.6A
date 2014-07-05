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
	//首先MYSQL类需要初始化
	bool Initialize();
	//需要设置连接数据库
	bool Connect();

	//连接数据库以后可以先获取数据库列表
	void getdbs_name();

	//在连接数据库之前需要设置一下数据
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
	//事件挂接机制
	void SetMysqlConnectedEvent(const OnMysqlEvent& callback);
	void SetMysqlGetDBNameEvent(const OnMysqlEventA& callback);
	//*************


	//创建数据库
	bool CreateDataBase(char* dbname);

	//删除数据库
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

