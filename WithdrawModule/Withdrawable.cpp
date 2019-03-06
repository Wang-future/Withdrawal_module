// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�CWithdrawable.cpp
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ�CWithdrawable.h��ʵ��
//             �汾: 1.1.01
// �������ߣ���ҵ��
// �������ڣ�2018-07-10
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-10  1.0.000.000    ��ҵ��          ԭ��
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
// �������ƣ� getTime()
// ����������ͨ������c++�Դ���SYSTEMTIME��õ���ǰϵͳʱ��
//
// ����˵����
// ����˵��������Ҫ����
// ���ؽ���� SYSTEMTIME  ���ý��
//            sys         ���óɹ�
//
//--------------------------------------------------------------------------------------
SYSTEMTIME CWithdrawable::getTime()
{
  SYSTEMTIME sys;
  GetLocalTime(&sys);
  return sys;
}

//--------------------------------------------------------------------------------------
// �������ƣ� isTimeInCallAuction
// �����������жϵ�ǰʱ���Ƿ��ھ���ʱ��
//
// ����˵����
// ����˵����SYSTEMTIME timeToJudge    ��timeToJudgeΪ��ǰ��ϵͳʱ��
// ���ؽ���� bool   ���ý��
//            true   �ڼ��Ͼ���ʱ����
//            false  ���ڼ��Ͼ���ʱ����
//--------------------------------------------------------------------------------------
bool CWithdrawable::isTimeInCallAuction(SYSTEMTIME timeToJudge)
{
  if (timeToJudge.wHour == 9 &&
    (timeToJudge.wMinute >= 20 && timeToJudge.wMinute <= 25))
    return true;

  return false;
}

//--------------------------------------------------------------------------------------
// �������ƣ� isCancelled
// �����������жϵ�ǰ�����Ƿ��ظ���������Ϊ�û�����һֱ�ύ��������
//
// ����˵����
// ����˵����OrderRecord* pclorder    ��pclorderΪָ��ǰ�����ĵ���OrderRecord��ָ��
// ���ؽ���� bool   ���ý��
//            true   �Ѿ��ڳ�����
//            false  ��û����
//--------------------------------------------------------------------------------------
bool CWithdrawable::isCancelled(OrderRecord* pclorder)
{
  if ('1' == pclorder->IS_WITHDRAW)
    return true;
  else return false;
}

//--------------------------------------------------------------------------------------
// �������ƣ� isOrderFinished
// �����������жϵ�ǰ�����Ƿ��Ѿ���ɳ���
//
// ����˵����
// ����˵����OrderRecord* pclorder    ��pclorderΪָ��ǰ�����ĵ���OrderRecord��ָ��
// ���ؽ���� bool   ���ý��
//            true   �Ѿ���ɳ�����
//            false  ��û��ɳ���
//--------------------------------------------------------------------------------------
bool CWithdrawable::isOrderFinished(OrderRecord* pclorder)
{
  if ('1' == pclorder->IS_WITHDRAWN)
    return true;
  else return false;
}
//--------------------------------------------------------------------------------------
// �������ƣ� isWithdrawable
// �����������жϵ�ǰ�����Ƿ���Ч�������Ч�ύ�����������Ч������Ч��ԭ���������
//
// ����˵����
// ����˵����OOrderRecord order    ��orderΪ��ǰ�����ĵ���
// ���ؽ���� bool   ���ý��
//            true   ������Ч�����Գ���
//            false  ������Ч�����ܳ���
//--------------------------------------------------------------------------------------
bool CWithdrawable::isWithdrawable(OrderRecord order)
{
  SYSTEMTIME clcurrenttime;
  GetLocalTime(&clcurrenttime);  //��ǰϵͳʱ��
  if ((!isTimeInCallAuction(clcurrenttime)) && (!isCancelled(&order) && (!isOrderFinished(&order))))//����Ҫ����order��״̬�ж�
    return true;
  else
    return false;
}
WITHDRAW_END