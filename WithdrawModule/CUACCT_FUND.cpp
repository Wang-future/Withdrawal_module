// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�CUACCT_FUND.cpp
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ�CUACCT_FUND���C++ʵ��
//             �汾: 1.1.01
// �������ߣ��º���
// �������ڣ�2018-07-11
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-11  1.0.000.000        �º���          ԭ��
//------------------------------------------------------------

#include "common.h"
#include "CUACCT_FUND.h"

WITHDRAW_BEGIN
CUACCT_FUND::CUACCT_FUND(): USER_CODE(0), FUND_AVL(0), FUND_TRD_FRZ(0)
{
}

otl_stream& operator>>(otl_stream& s, CUACCT_FUND& row)
{
  s >> row.USER_CODE >> row.FUND_AVL >> row.FUND_TRD_FRZ;
  return s;
}

otl_stream& operator<<(otl_stream& s, const CUACCT_FUND& row) {
  s << row.USER_CODE << row.FUND_AVL << row.FUND_TRD_FRZ;
  return s;
}
WITHDRAW_END