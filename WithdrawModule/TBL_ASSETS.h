// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�TBL_ASSETS.h
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

#ifndef TBL_ASSETS_H
#define TBL_ASSETS_H
#include "common.h"
WITHDRAW_BEGIN
class TBL_ASSETS
{
public:
  TBL_ASSETS();
  ~TBL_ASSETS();

  friend otl_stream& operator>>(otl_stream& s, TBL_ASSETS& row);
  friend otl_stream& operator<<(otl_stream& s, const TBL_ASSETS& row);

public:
  long long CUST_CODE;
  long long CUACCT_CODE;
  long long STK_TRD_FRZ;
  long long STK_TRD_UFZ;
};
WITHDRAW_END
#endif