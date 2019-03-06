// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：UnfreezeThread.h
// 模块名称：撤单模块
// 模块描述：本模块是对类UnfreezeThread的实现
//             版本: 1.1.01
// 开发作者：陈浩锐
// 创建日期：2018-07-10
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    陈浩锐          原创
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