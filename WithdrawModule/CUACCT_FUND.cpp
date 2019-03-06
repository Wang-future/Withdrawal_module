// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：CUACCT_FUND.cpp
// 模块名称：撤单模块
// 模块描述：本模块是对CUACCT_FUND表的C++实现
//             版本: 1.1.01
// 开发作者：陈浩锐
// 创建日期：2018-07-11
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-11  1.0.000.000        陈浩锐          原创
//------------------------------------------------------------

#include "common.h"
#include "CUACCT_FUND.h"

WITHDRAW_BEGIN
CUACCT_FUND::CUACCT_FUND(): USER_CODE(0), FUND_AVL(0), FUND_TRD_FRZ(0)
{
}

otl_stream& operator>>(otl_stream& s, CUACCT_FUND& row)
{
  s >> row.USER_CODE >> row.FUND_AVL >> row.FUND_TRD_FRZ;
  return s;
}

otl_stream& operator<<(otl_stream& s, const CUACCT_FUND& row) {
  s << row.USER_CODE << row.FUND_AVL << row.FUND_TRD_FRZ;
  return s;
}
WITHDRAW_END