// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�CUACCT_FUND.h
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ�CUACCT_FUND���C++ʵ��
//             �汾: 1.1.01
// �������ߣ��º���
// �������ڣ�2018-07-11
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-11  1.0.000.000    �º���          ԭ��
//------------------------------------------------------------

#ifndef CUACCT_FUND_H
#define CUACCT_FUND_H
#include "common.h"
WITHDRAW_BEGIN
class CUACCT_FUND
{
public:
	CUACCT_FUND();
	~CUACCT_FUND(){}

  friend otl_stream& operator >> (otl_stream& s, CUACCT_FUND& row);
  friend otl_stream& operator <<(otl_stream& s, const CUACCT_FUND& row);

public:
	long long USER_CODE;
  float FUND_AVL;
	float FUND_TRD_FRZ;
};
WITHDRAW_END
#endif
