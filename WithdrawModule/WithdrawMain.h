// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：WithdrawMain.h
// 模块名称：撤单模块
// 模块描述：本模块是对类WithdrawMain的定义，对外面提供撤单接口，以及查询当前可撤单的委托列表
//             版本: 1.1.01
// 开发作者：刘凯婷 罗颂琦
// 创建日期：2018-07-10
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    刘凯婷 罗颂琦        原创
//------------------------------------------------------------

#ifndef _WITHDRAWMAIN_H
#define _WITHDRAWMAIN_H

#include "OrderRecord.h"
#include "Database.h"
#include "Withdrawable.h"
#include <vector>
#include <thread>


WITHDRAW_BEGIN

class DLL_MODULE WithdrawMain
{
public:
  WithdrawMain();

  ~WithdrawMain();

  bool withdraw(int order_sn);

  std::vector<OrderRecord> getList();


private:
  void MakeFlowRecord(OrderRecord &order);

  int beginUnfreezeThread();

  void endUnfreezeThread();

  Database* database;

  std::thread *unfreezeThread;
};

WITHDRAW_END

#endif //_WITHDRAWMAIN_H