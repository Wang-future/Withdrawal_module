// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�WithdrawMain.h
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ���WithdrawMain�Ķ��壬�������ṩ�����ӿڣ��Լ���ѯ��ǰ�ɳ�����ί���б�
//             �汾: 1.1.01
// �������ߣ������� ������
// �������ڣ�2018-07-10
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    ������ ������        ԭ��
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