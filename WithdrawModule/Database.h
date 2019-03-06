// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：Database.h
// 模块名称：撤单模块
// 模块描述：本模块是对类Database的声明，用于对撤单模块提供数据库支持
//             版本: 1.1.01
// 开发作者：陈浩彬
// 创建日期：2018-07-10
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    陈浩彬          原创
//------------------------------------------------------------

#ifndef _DATABASE_H
#define _DATABASE_H
#include "OrderRecord.h"
#include "TBL_ASSETS.h"
#include "CUACCT_FUND.h"
#include <vector>
#include <string>

WITHDRAW_BEGIN
class Database {
public:
  std::vector<CUACCT_FUND> getFundInfo(long long USER_CODE);
	std::vector<TBL_ASSETS> getAsset(long long CUST_CODE, long long CUACCT_CODE);
	void updateFundInfo(const CUACCT_FUND& fundInfo);
  void updateAsset(const TBL_ASSETS& asset);

  std::vector<OrderRecord> SelectIsWithdraw(long long order_sn);
  void Update_OrderRecord(OrderRecord record);
  std::vector<OrderRecord> SelectCurrent(const int date);
  void OrderRecord_Insert(OrderRecord record); // insert rows into table

public:
  Database(const std::string& suid, const std::string& spwd, const std::string& sdsn) :
    uid(suid), pwd(spwd), dsn(sdsn)
  {}
  ~Database() {}

  void Initialize();
  void UnInitialize();


private:
  otl_connect database; // connect object
  std::string uid;
  std::string pwd;
  std::string dsn;
};
WITHDRAW_END
#endif //_DATABASE_H