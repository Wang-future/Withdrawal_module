// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：Database.cpp
// 模块名称：撤单模块
// 模块描述：本模块是对类Database的实现
//             版本: 1.1.01
// 开发作者：陈浩彬
// 创建日期：2018-07-10
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    陈浩彬          原创
//------------------------------------------------------------


#include "common.h"
#include "Database.h"
#include <iostream>

using namespace std;

WITHDRAW_BEGIN

std::vector<CUACCT_FUND> Database::getFundInfo(long long USER_CODE)
{
  otl_stream i(50, // buffer size may be > 1
    "select * from CUACCT_FUND "
    "where USER_CODE = :f1<bigint>",
    database // connect object
  );
  // create select stream

  vector<CUACCT_FUND> v; // vector of rows

  i << USER_CODE;

  copy(otl_input_iterator<CUACCT_FUND, ptrdiff_t>(i),
    otl_input_iterator<CUACCT_FUND, ptrdiff_t>(),
    back_inserter(v));

  return v;
}

std::vector<TBL_ASSETS> Database::getAsset(long long CUST_CODE, long long CUACCT_CODE)
{
  otl_stream i(50, // buffer size may be > 1
    "select * from ASSETS "
    "where CUST_CODE = :af1<bigint> and CUACCT_CODE = :af2<bigint>",
    database // connect object
  );
  // create select stream

  vector<TBL_ASSETS> v; // vector of rows

  i << CUST_CODE << CUACCT_CODE;

  copy(otl_input_iterator<TBL_ASSETS, ptrdiff_t>(i),
    otl_input_iterator<TBL_ASSETS, ptrdiff_t>(),
    back_inserter(v));

  return v;
}

void Database::updateFundInfo(const CUACCT_FUND & fundInfo)
{
  otl_stream o(1, // buffer size should be == 1 always on UPDATE
    "UPDATE CUACCT_FUND "
    " SET FUND_AVL = :f1<float>, FUND_TRD_FRZ = :f2<float>"
    "	WHERE USER_CODE = :f3<bigint>",
    // UPDATE statement
    database // connect object
  );
  try {
    o << fundInfo.FUND_AVL << fundInfo.FUND_TRD_FRZ << fundInfo.USER_CODE;
  }
  catch (otl_exception&e)
  {
    cerr << e.msg;
  }
}

void Database::updateAsset(const TBL_ASSETS & asset)
{
  otl_stream o(1, // buffer size should be == 1 always on UPDATE
    "UPDATE ASSETS "
    " SET STK_TRD_FRZ=:f1<bigint> ,STK_TRD_UFZ = :f2<bigint>"
    "	WHERE CUST_CODE=:f3<bigint> and CUACCT_CODE = :f4<bigint>",
    // UPDATE statement
    database // connect object
  );
  
  o << asset.STK_TRD_FRZ << asset.STK_TRD_UFZ << asset.CUST_CODE << asset.CUACCT_CODE;
  
}

std::vector<OrderRecord> Database::SelectIsWithdraw(long long order_sn)
{
  otl_stream i(1024, // buffer size may be > 1
    "select * from STOCK_ORDER "
    "where ORDER_SN = :af1<bigint>",
    database // connect object
  );
  // create select stream

  vector<OrderRecord> v; // vector of rows

  i << order_sn;  // enter :order_sn = af1

            // copy all rows to be fetched into the vector

  copy(otl_input_iterator<OrderRecord, ptrdiff_t>(i),
    otl_input_iterator<OrderRecord, ptrdiff_t>(),
    back_inserter(v));

  return v;
}

void Database::Update_OrderRecord(OrderRecord record)
{
  otl_stream o(1,
    "UPDATE STOCK_ORDER "
    " SET ORDER_TYPE = :f1<int>,IS_WITHDRAW = :tag1<int> , IS_WITHDRAWN = :tag2<int>"
    " WHERE ORDER_SN = :SN<bigint>",
    database  // connect object
  );
  o << record.ORDER_TYPE << record.IS_WITHDRAW << record.IS_WITHDRAWN << record.ORDER_SN;
}

std::vector<OrderRecord> Database::SelectCurrent(const int date)
{
  otl_stream i(100, // buffer size may be > 1
    "select * from STOCK_ORDER "
    "where ORDER_DATE = :af1<int>",
    database // connect object
  );
  // create select stream

  vector<OrderRecord> v; // vector of rows

  i << date;  // enter :datee = af1

              // copy all rows to be fetched into the vector

  copy(otl_input_iterator<OrderRecord, ptrdiff_t>(i),
    otl_input_iterator<OrderRecord, ptrdiff_t>(),
    back_inserter(v));

  return v;
}


void Database::OrderRecord_Insert(OrderRecord record)
{
  try
  {
    otl_stream o(500,
      "insert into STOCK_ORDER values("
      ":TRD_DATE<int>,:ORDER_DATE<int>,:ORDER_TIME<int>,:ORDER_SN<bigint>,:ORDER_TYPE<int>,:CUST_CODE<int>"
      ",:CUACCT_CODE<int>,:ORDER_AMT<float>,:WITHDRAWN_QTY<int>,:MATCHED_QTY<int>,:MATCHED_AMT<float>,:IS_WITHDRAW<int>,:IS_WITHDRAWN<int>)",
      database // connect object
    );

    vector<OrderRecord> vo; // vector of rows
                            // populate the vector
    vo.push_back(record);

    // insert vector into table
    copy(vo.begin(),
      vo.end(),
      otl_output_iterator<OrderRecord>(o)
    );
  }
  catch (otl_exception& p)    // intercept OTL exceptions
  {
    cerr << p.msg << endl; // print out error message
    cerr << p.stm_text << endl; // print out SQL that caused the error
    cerr << p.var_info << endl; // print out the variable that caused the error
  }
}


 void Database::Initialize()
 {
   otl_connect::otl_initialize(); // initialize ODBC environment
   try
   {
     database.rlogon(("UID=" + uid + ";PWD=" + pwd + ";DSN=" + dsn).c_str()); // connect to ODBC
   }
   catch (otl_exception& p)    // intercept OTL exceptions
   {
     cerr << p.msg << endl; // print out error message
     cerr << p.stm_text << endl; // print out SQL that caused the error
     cerr << p.var_info << endl; // print out the variable that caused the error
   }
 }

 void Database::UnInitialize()
 {
   try
   {
     database.logoff(); // disconnect from ODBC
   }
   catch (otl_exception& p)    // intercept OTL exceptions
   {
     cerr << p.msg << endl; // print out error message
     cerr << p.stm_text << endl; // print out SQL that caused the error
     cerr << p.var_info << endl; // print out the variable that caused the error
   }
 }

WITHDRAW_END