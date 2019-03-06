// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：CWithdrawable.cpp
// 模块名称：撤单模块
// 模块描述：本模块是对CWithdrawable.h的实现
//             版本: 1.1.01
// 开发作者：王业超
// 创建日期：2018-07-10
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    王业超          原创
//------------------------------------------------------------

#include "common.h"
#include "Withdrawable.h"

WITHDRAW_BEGIN

// set and get function
void CWithdrawable::setBeginTimeOfCallAuction(SYSTEMTIME BeginTimeOfCallAuction5)
{
  BeginTimeOfCallAuction = BeginTimeOfCallAuction5;
}
void CWithdrawable::setEndTimeOfCallAuction(SYSTEMTIME EndTimeOfCallAuction5)
{
  EndTimeOfCallAuction = EndTimeOfCallAuction5;
}

SYSTEMTIME CWithdrawable::getBeginTimeOfCallAuction()
{
  return BeginTimeOfCallAuction;
}
SYSTEMTIME CWithdrawable::getEndTimeOfCallAuction()
{
  return EndTimeOfCallAuction;
}

// set and get function

//--------------------------------------------------------------------------------------
// 函数名称： getTime()
// 函数描述：通过调用c++自带的SYSTEMTIME类得到当前系统时间
//
// 其他说明：
// 参数说明：不需要参数
// 返回结果： SYSTEMTIME  调用结果
//            sys         调用成功
//
//--------------------------------------------------------------------------------------
SYSTEMTIME CWithdrawable::getTime()
{
  SYSTEMTIME sys;
  GetLocalTime(&sys);
  return sys;
}

//--------------------------------------------------------------------------------------
// 函数名称： isTimeInCallAuction
// 函数描述：判断当前时间是否在竞价时间
//
// 其他说明：
// 参数说明：SYSTEMTIME timeToJudge    ：timeToJudge为当前的系统时间
// 返回结果： bool   调用结果
//            true   在集合竞价时间内
//            false  不在集合竞价时间内
//--------------------------------------------------------------------------------------
bool CWithdrawable::isTimeInCallAuction(SYSTEMTIME timeToJudge)
{
  if (timeToJudge.wHour == 9 &&
    (timeToJudge.wMinute >= 20 && timeToJudge.wMinute <= 25))
    return true;

  return false;
}

//--------------------------------------------------------------------------------------
// 函数名称： isCancelled
// 函数描述：判断当前单子是否重复撤单，因为用户可能一直提交撤单申请
//
// 其他说明：
// 参数说明：OrderRecord* pclorder    ：pclorder为指向当前撤单的单子OrderRecord的指针
// 返回结果： bool   调用结果
//            true   已经在撤单了
//            false  还没撤单
//--------------------------------------------------------------------------------------
bool CWithdrawable::isCancelled(OrderRecord* pclorder)
{
  if ('1' == pclorder->IS_WITHDRAW)
    return true;
  else return false;
}

//--------------------------------------------------------------------------------------
// 函数名称： isOrderFinished
// 函数描述：判断当前单子是否已经完成撤单
//
// 其他说明：
// 参数说明：OrderRecord* pclorder    ：pclorder为指向当前撤单的单子OrderRecord的指针
// 返回结果： bool   调用结果
//            true   已经完成撤单了
//            false  还没完成撤单
//--------------------------------------------------------------------------------------
bool CWithdrawable::isOrderFinished(OrderRecord* pclorder)
{
  if ('1' == pclorder->IS_WITHDRAWN)
    return true;
  else return false;
}
//--------------------------------------------------------------------------------------
// 函数名称： isWithdrawable
// 函数描述：判断当前单子是否有效，如果有效提交撤单，如果无效根据无效的原因进行提醒
//
// 其他说明：
// 参数说明：OOrderRecord order    ：order为当前撤单的单子
// 返回结果： bool   调用结果
//            true   单子有效，可以撤单
//            false  单子无效，不能撤单
//--------------------------------------------------------------------------------------
bool CWithdrawable::isWithdrawable(OrderRecord order)
{
  SYSTEMTIME clcurrenttime;
  GetLocalTime(&clcurrenttime);  //当前系统时间
  if ((!isTimeInCallAuction(clcurrenttime)) && (!isCancelled(&order) && (!isOrderFinished(&order))))//这里要根据order的状态判断
    return true;
  else
    return false;
}
WITHDRAW_END