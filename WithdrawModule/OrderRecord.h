// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：OrderRecord.h
// 模块名称：撤单模块
// 模块描述：本模块是对STOCK_ORDER表的C++实现
//             版本: 1.1.01
// 开发作者：陈浩彬 陈璟池 张守一
// 创建日期：2018-07-11
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-11  1.0.000.000    陈璟池 张守一        原创
// 2018-07-11  1.0.000.000    陈浩彬        重载了左移右移操作符
//------------------------------------------------------------
#ifndef _ORDERRECORD_H
#define _ORDERRECORD_H

#include <string>

WITHDRAW_BEGIN

#define BUY_ORDER 1
#define SALE_ORDER 2
#define WITHDRAW_ORDER 3


class DLL_MODULE OrderRecord {
public:
  int TRD_DATE; //交易日期
  int ORDER_DATE; //委托日期
  int  ORDER_TIME; //委托时间
  long long ORDER_SN; //委托序号
  int ORDER_TYPE; //委托类型
  int CUST_CODE;//客户代码
  int CUACCT_CODE;//资产账户
  float ORDER_AMT;//委托金额
  int WITHDRAWN_QTY;//已撤单数量
  int MATCHED_QTY;//已成交数量
  float MATCHED_AMT;//已成交金额
  int IS_WITHDRAW;//撤单标志
  int IS_WITHDRAWN;//已撤单标志

					  // default constructor
	OrderRecord() :
		TRD_DATE(0),
		ORDER_DATE(0),
		ORDER_TIME(0),
		ORDER_SN(0),
		ORDER_TYPE(),
		CUST_CODE(0),
		CUACCT_CODE(0),
		ORDER_AMT(0.0),
		WITHDRAWN_QTY(0),
		MATCHED_QTY(0),
		MATCHED_AMT(0.0),
		IS_WITHDRAW(),
		IS_WITHDRAWN()
	{
	}

	// destructor
	~OrderRecord() {}

	// copy constructor
	OrderRecord(const OrderRecord& arow) :
		TRD_DATE(arow.TRD_DATE),
		ORDER_DATE(arow.ORDER_DATE),
		ORDER_TIME(arow.ORDER_TIME),
		ORDER_SN(arow.ORDER_SN),
		ORDER_TYPE(arow.ORDER_TYPE),
		CUST_CODE(arow.CUST_CODE),
		CUACCT_CODE(arow.CUACCT_CODE),
		ORDER_AMT(arow.ORDER_AMT),
		WITHDRAWN_QTY(arow.WITHDRAWN_QTY),
		MATCHED_QTY(arow.MATCHED_QTY),
		MATCHED_AMT(arow.MATCHED_AMT),
		IS_WITHDRAW(arow.IS_WITHDRAW),
		IS_WITHDRAWN(arow.IS_WITHDRAWN)
	{
	}

	// assignment operator
  OrderRecord& operator=(const OrderRecord& arow);

  bool operator<(const OrderRecord& p) const;

  friend otl_stream& operator>>(otl_stream& s, OrderRecord& OrderRecord);
  
  friend otl_stream& operator<<(otl_stream& s, const OrderRecord& OrderRecord);


};
WITHDRAW_END

#endif //_ORDERRECORD_H