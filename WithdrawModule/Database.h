// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�Database.h
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ���Database�����������ڶԳ���ģ���ṩ���ݿ�֧��
//             �汾: 1.1.01
// �������ߣ��ºƱ�
// �������ڣ�2018-07-10
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    �ºƱ�          ԭ��
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