// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：Withdrawable.h
// 模块名称：撤单模块
// 模块描述：本模块是对CWithdrawable.h的声明
//             版本: 1.1.01
// 开发作者：王业超
// 创建日期：2018-07-10
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    王业超          原创
//------------------------------------------------------------
#ifndef _WITHDRAWABLE_H
#define _WITHDRAWABLE_H
#include "OrderRecord.h"

WITHDRAW_BEGIN
class CWithdrawable {

public:
  CWithdrawable() {}
  CWithdrawable(SYSTEMTIME BeginTimeOfCallAuction, SYSTEMTIME EndTimeOfCallAuction) :BeginTimeOfCallAuction(BeginTimeOfCallAuction), EndTimeOfCallAuction(EndTimeOfCallAuction) {}
  SYSTEMTIME BeginTimeOfCallAuction;
  SYSTEMTIME EndTimeOfCallAuction;
  SYSTEMTIME getBeginTimeOfCallAuction();
  SYSTEMTIME getEndTimeOfCallAuction();

  bool isWithdrawable(OrderRecord);

private:
  SYSTEMTIME getTime();//得到系统时间

  bool isTimeInCallAuction(SYSTEMTIME timeToJudeg);

  bool isCancelled(OrderRecord*);
  bool isOrderFinished(OrderRecord*);
  void setBeginTimeOfCallAuction(SYSTEMTIME BeginTimeOfCallAuction);
  void setEndTimeOfCallAuction(SYSTEMTIME EndTimeOfCallAuction);
};

WITHDRAW_END

#endif //_CWithdrawable_H#pragma once