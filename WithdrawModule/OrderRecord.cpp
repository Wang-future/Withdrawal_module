// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�OrderRecord.cpp
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ�STOCK_ORDER���C++ʵ��
//             �汾: 1.1.01
// �������ߣ��ºƱ� �­Z�� ����һ
// �������ڣ�2018-07-11
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-11  1.0.000.000    �­Z�� ����һ        ԭ��
// 2018-07-11  1.0.000.000    �ºƱ�        �������������Ʋ�����
//------------------------------------------------------------

#include "common.h"
#include "OrderRecord.h"
WITHDRAW_BEGIN

OrderRecord & OrderRecord::operator=(const OrderRecord & arow)
{
  this->TRD_DATE = arow.TRD_DATE;
  this->ORDER_DATE = arow.ORDER_DATE;
  this->ORDER_TIME = arow.ORDER_TIME;
  this->ORDER_SN = arow.ORDER_SN;
  this->ORDER_TYPE = arow.ORDER_TYPE;
  this->CUST_CODE = arow.CUST_CODE;
  this->CUACCT_CODE = arow.CUACCT_CODE;
  this->ORDER_AMT = arow.ORDER_AMT;
  this->WITHDRAWN_QTY = arow.WITHDRAWN_QTY;
  this->MATCHED_QTY = arow.MATCHED_QTY;
  this->MATCHED_AMT = arow.MATCHED_AMT;
  this->IS_WITHDRAW = arow.IS_WITHDRAW;
  this->IS_WITHDRAWN = arow.IS_WITHDRAWN;
  return *this;
}

bool OrderRecord::operator<(const OrderRecord & p) const
{
  return ORDER_SN < p.ORDER_SN;
}

otl_stream & operator<<(otl_stream & s, const OrderRecord & OrderRecord)
{
  s << OrderRecord.TRD_DATE << OrderRecord.ORDER_DATE << OrderRecord.ORDER_TIME << OrderRecord.ORDER_SN << OrderRecord.ORDER_TYPE << OrderRecord.CUST_CODE << OrderRecord.CUACCT_CODE
    << OrderRecord.ORDER_AMT << OrderRecord.WITHDRAWN_QTY
    << OrderRecord.MATCHED_QTY << OrderRecord.MATCHED_AMT << OrderRecord.IS_WITHDRAW << OrderRecord.IS_WITHDRAWN;
  return s;
}

otl_stream& operator>>(otl_stream & s, OrderRecord & OrderRecord)
{
  s >> OrderRecord.TRD_DATE >> OrderRecord.ORDER_DATE >> OrderRecord.ORDER_TIME >> OrderRecord.ORDER_SN >> OrderRecord.ORDER_TYPE >> OrderRecord.CUST_CODE >> OrderRecord.CUACCT_CODE
    >> OrderRecord.ORDER_AMT >> OrderRecord.WITHDRAWN_QTY
    >> OrderRecord.MATCHED_QTY >> OrderRecord.MATCHED_AMT >> OrderRecord.IS_WITHDRAW >> OrderRecord.IS_WITHDRAWN;
  return s;
}

WITHDRAW_END