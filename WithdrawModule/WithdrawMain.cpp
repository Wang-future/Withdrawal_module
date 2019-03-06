// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：WithdrawMain.cpp
// 模块名称：撤单模块
// 模块描述：本模块是对类WithdrawMain的实现
//             版本: 1.1.01
// 开发作者：刘凯婷 罗颂琦
// 创建日期：2018-07-10
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    刘凯婷 罗颂琦        原创
//------------------------------------------------------------

#include "common.h"
#include "WithdrawMain.h"
#include "Withdrawable.h"
#include "UnfreezeThread.h"
#include "Database.h"
#include <vector>
#include <thread>
#include <iostream>

using namespace std;

WITHDRAW_BEGIN


WithdrawMain::WithdrawMain()
{
  database = new Database("sa", "123456", "Withdraw_1");
  database->Initialize();
  beginUnfreezeThread();
}

WithdrawMain::~WithdrawMain()
{
  database->UnInitialize();
  delete database;
  endUnfreezeThread();
}

bool WithdrawMain::withdraw(int order_sn) {
  vector<OrderRecord> list = database->SelectIsWithdraw(order_sn);
  if (list.size() == 0)
  {
    return false;
  }
  OrderRecord order = list[0];    // 根据主码查询返回值必定唯一
  CWithdrawable w;
  if (w.isWithdrawable(order)) {
    order.IS_WITHDRAW = 1;         //修改撤单标志   如果是已经发起撤单了
    order.IS_WITHDRAWN = 1;
    UnfreezeThread::getInstance()->withdraw(order);
    database->Update_OrderRecord(order);
    MakeFlowRecord(order);
    return true;
  }
  return false;
}

std::vector<OrderRecord> WithdrawMain::getList() {
  SYSTEMTIME time;
  GetLocalTime(&time);
  int date = time.wYear * 10000 + time.wMonth * 100 + time.wDay;

  std::vector<OrderRecord> OrderList = database->SelectCurrent(date);
  vector<OrderRecord>::iterator iter;
  CWithdrawable w;
  for (iter = OrderList.begin(); iter != OrderList.end(); iter++)
  {
    if (!w.isWithdrawable(*iter))
    {
      OrderList.erase(iter);
    }
  }
  return OrderList;
};

void WithdrawMain::MakeFlowRecord(OrderRecord &order) {
  order.ORDER_TYPE = 3;
  order.ORDER_SN = order.ORDER_SN + 10086;        //撤单流水序号
  database->OrderRecord_Insert(order);
};


int WithdrawMain::beginUnfreezeThread() {
  UnfreezeThread * p = UnfreezeThread::getInstance();
  unfreezeThread = new thread(UnfreezeThread::threadMain, database);
  return 0;
}

void WithdrawMain::endUnfreezeThread()
{
  UnfreezeThread::getInstance()->release();

  while (!unfreezeThread->joinable());
  unfreezeThread->join();

  delete unfreezeThread;
  unfreezeThread = nullptr;
}

WITHDRAW_END