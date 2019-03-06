// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：UnfreezeThread.h
// 模块名称：撤单模块
// 模块描述：本模块是对类UnfreezeThread的定义，为模块提供撤单完成后的解冻资金/证券功能
//             版本: 1.1.01
// 开发作者：陈浩锐
// 创建日期：2018-07-10
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    陈浩锐          原创
//------------------------------------------------------------

#ifndef _UNFREEZETHREAD_H
#define _UNFREEZETHREAD_H

#include "Database.h"
#include "OrderRecord.h"
#include <set>

WITHDRAW_BEGIN
class UnfreezeThread
{
public: 
	static UnfreezeThread* getInstance();
    
	/* 操作契约
	参数
	@database：创建的用于读写数据库的Database实例
	前置条件：启动该子线程的父线程应当先通过getInstance初始化实例
	后置条件：父子线程的实例相同，线程正确启动
	*/
    static void threadMain(Database* database);

	void withdraw(OrderRecord& order);

	void endThread();

	void release();

private:
	static UnfreezeThread* instance;

	Database* database;

	std::set<OrderRecord> toUnfreeze;

	bool ending;

	bool ended;

private:
	void unfreezeMoney(const OrderRecord& order);

	void unfreezeStock(const OrderRecord& order);
};
WITHDRAW_END

#endif //_UNFREEZETHREAD_H