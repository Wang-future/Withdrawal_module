// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�WithdrawMain.cpp
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ���WithdrawMain��ʵ��
//             �汾: 1.1.01
// �������ߣ������� ������
// �������ڣ�2018-07-10
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    ������ ������        ԭ��
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
  OrderRecord order = list[0];    // ���������ѯ����ֵ�ض�Ψһ
  CWithdrawable w;
  if (w.isWithdrawable(order)) {
    order.IS_WITHDRAW = 1;         //�޸ĳ�����־   ������Ѿ����𳷵���
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
  order.ORDER_SN = order.ORDER_SN + 10086;        //������ˮ���
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