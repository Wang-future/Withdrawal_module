// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：TBL_ASSETS.h
// 模块名称：撤单模块
// 模块描述：本模块是对TBL_ASSETS表的C++实现
//             版本: 1.1.01
// 开发作者：陈浩锐
// 创建日期：2018-07-11
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-11  1.0.000.000    陈浩锐          原创
//------------------------------------------------------------

#ifndef TBL_ASSETS_H
#define TBL_ASSETS_H
#include "common.h"
WITHDRAW_BEGIN
class TBL_ASSETS
{
public:
  TBL_ASSETS();
  ~TBL_ASSETS();

  friend otl_stream& operator>>(otl_stream& s, TBL_ASSETS& row);
  friend otl_stream& operator<<(otl_stream& s, const TBL_ASSETS& row);

public:
  long long CUST_CODE;
  long long CUACCT_CODE;
  long long STK_TRD_FRZ;
  long long STK_TRD_UFZ;
};
WITHDRAW_END
#endif