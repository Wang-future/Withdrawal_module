// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：CUACCT_FUND.h
// 模块名称：撤单模块
// 模块描述：本模块是对CUACCT_FUND表的C++实现
//             版本: 1.1.01
// 开发作者：陈浩锐
// 创建日期：2018-07-11
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-11  1.0.000.000    陈浩锐          原创
//------------------------------------------------------------

#ifndef CUACCT_FUND_H
#define CUACCT_FUND_H
#include "common.h"
WITHDRAW_BEGIN
class CUACCT_FUND
{
public:
	CUACCT_FUND();
	~CUACCT_FUND(){}

  friend otl_stream& operator >> (otl_stream& s, CUACCT_FUND& row);
  friend otl_stream& operator <<(otl_stream& s, const CUACCT_FUND& row);

public:
	long long USER_CODE;
  float FUND_AVL;
	float FUND_TRD_FRZ;
};
WITHDRAW_END
#endif
