// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�UnfreezeThread.h
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ���UnfreezeThread�Ķ��壬Ϊģ���ṩ������ɺ�Ľⶳ�ʽ�/֤ȯ����
//             �汾: 1.1.01
// �������ߣ��º���
// �������ڣ�2018-07-10
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    �º���          ԭ��
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
    
	/* ������Լ
	����
	@database�����������ڶ�д���ݿ��Databaseʵ��
	ǰ�����������������̵߳ĸ��߳�Ӧ����ͨ��getInstance��ʼ��ʵ��
	���������������̵߳�ʵ����ͬ���߳���ȷ����
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