// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�UnfreezeThread.h
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ���UnfreezeThread��ʵ��
//             �汾: 1.1.01
// �������ߣ��º���
// �������ڣ�2018-07-10
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    �º���          ԭ��
//------------------------------------------------------------

#include "common.h"
#include "UnfreezeThread.h"
#include "Database.h"
#include "TBL_ASSETS.h"
#include "CUACCT_FUND.h"

#include <Windows.h>
#include <stdio.h>

WITHDRAW_BEGIN

UnfreezeThread *UnfreezeThread::instance = nullptr;

UnfreezeThread * UnfreezeThread::getInstance()
{
	if (instance == nullptr)
	{
		instance = new UnfreezeThread;
		instance->ending = false;
		instance->ended = false;
	}
	return instance;
}

void UnfreezeThread::threadMain(Database * database)
{
	UnfreezeThread* inst = getInstance();
	inst->database = database;

	while (true)
	{
    auto i = inst->toUnfreeze.begin();
    while (true)
    {
      if (i == inst->toUnfreeze.end())
        break;
      OrderRecord p = inst->database->SelectIsWithdraw(i->ORDER_SN)[0];
      if (p.IS_WITHDRAWN)
      {
        switch (p.ORDER_TYPE)
        {
        case BUY_ORDER:
          inst->unfreezeMoney(p);
          break;
        case SALE_ORDER:
          inst->unfreezeStock(p);
          break;
        }
        inst->toUnfreeze.erase(i);
        i = inst->toUnfreeze.begin();
      }
      else
      {
        i++;
      }
    }

		Sleep(5 * 1000);
		if (inst->ending)
		{
			inst->ended = true;
			break;
		}
	}
}

void UnfreezeThread::withdraw(OrderRecord & order)
{
  if(order.IS_WITHDRAW)
    toUnfreeze.insert(order);
}

void UnfreezeThread::endThread()
{
	ending = true;
	while (!ended)
	{
		Sleep(0);
	}
}

void UnfreezeThread::release()
{
	endThread();
	instance = nullptr;
	delete this;
}

void UnfreezeThread::unfreezeMoney(const OrderRecord& order)
{
	std::vector<CUACCT_FUND> list = database->getFundInfo(order.CUST_CODE);
	for (CUACCT_FUND &p : list)
	{
    p.FUND_AVL += p.FUND_TRD_FRZ;
    p.FUND_TRD_FRZ = 0;
    database->updateFundInfo(p);
	}
}

void UnfreezeThread::unfreezeStock(const OrderRecord& order)
{
	std::vector<TBL_ASSETS> list = database->getAsset(order.CUST_CODE, order.CUACCT_CODE);
	for (TBL_ASSETS &p : list)
	{
    p.STK_TRD_UFZ += p.STK_TRD_FRZ;
    p.STK_TRD_FRZ = 0;
    database->updateAsset(p);
	}
}

WITHDRAW_END