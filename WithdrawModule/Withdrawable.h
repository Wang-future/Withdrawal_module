// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�Withdrawable.h
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ�CWithdrawable.h������
//             �汾: 1.1.01
// �������ߣ���ҵ��
// �������ڣ�2018-07-10
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    ��ҵ��          ԭ��
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
  SYSTEMTIME getTime();//�õ�ϵͳʱ��

  bool isTimeInCallAuction(SYSTEMTIME timeToJudeg);

  bool isCancelled(OrderRecord*);
  bool isOrderFinished(OrderRecord*);
  void setBeginTimeOfCallAuction(SYSTEMTIME BeginTimeOfCallAuction);
  void setEndTimeOfCallAuction(SYSTEMTIME EndTimeOfCallAuction);
};

WITHDRAW_END

#endif //_CWithdrawable_H#pragma once