// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�TBL_ASSETS.cpp
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ�TBL_ASSETS���C++ʵ��
//             �汾: 1.1.01
// �������ߣ��º���
// �������ڣ�2018-07-11
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-11  1.0.000.000    �º���          ԭ��
//------------------------------------------------------------

#include "common.h"
#include "TBL_ASSETS.h"

WITHDRAW_BEGIN
TBL_ASSETS::TBL_ASSETS()
{
}


TBL_ASSETS::~TBL_ASSETS()
{
}


otl_stream& operator >> (otl_stream& s, TBL_ASSETS& row)
{
  s >> row.CUST_CODE >> row.CUACCT_CODE  >> row.STK_TRD_FRZ >> row.STK_TRD_UFZ;
  return s;
}

otl_stream& operator<<(otl_stream& s, const TBL_ASSETS& row)
{
  s <<  row.CUST_CODE << row.CUACCT_CODE << row.STK_TRD_FRZ << row.STK_TRD_UFZ;
  return s;
}

WITHDRAW_END