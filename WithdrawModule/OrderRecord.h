// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�OrderRecord.h
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
#ifndef _ORDERRECORD_H
#define _ORDERRECORD_H

#include <string>

WITHDRAW_BEGIN

#define BUY_ORDER 1
#define SALE_ORDER 2
#define WITHDRAW_ORDER 3


class DLL_MODULE OrderRecord {
public:
  int TRD_DATE; //��������
  int ORDER_DATE; //ί������
  int  ORDER_TIME; //ί��ʱ��
  long long ORDER_SN; //ί�����
  int ORDER_TYPE; //ί������
  int CUST_CODE;//�ͻ�����
  int CUACCT_CODE;//�ʲ��˻�
  float ORDER_AMT;//ί�н��
  int WITHDRAWN_QTY;//�ѳ�������
  int MATCHED_QTY;//�ѳɽ�����
  float MATCHED_AMT;//�ѳɽ����
  int IS_WITHDRAW;//������־
  int IS_WITHDRAWN;//�ѳ�����־

					  // default constructor
	OrderRecord() :
		TRD_DATE(0),
		ORDER_DATE(0),
		ORDER_TIME(0),
		ORDER_SN(0),
		ORDER_TYPE(),
		CUST_CODE(0),
		CUACCT_CODE(0),
		ORDER_AMT(0.0),
		WITHDRAWN_QTY(0),
		MATCHED_QTY(0),
		MATCHED_AMT(0.0),
		IS_WITHDRAW(),
		IS_WITHDRAWN()
	{
	}

	// destructor
	~OrderRecord() {}

	// copy constructor
	OrderRecord(const OrderRecord& arow) :
		TRD_DATE(arow.TRD_DATE),
		ORDER_DATE(arow.ORDER_DATE),
		ORDER_TIME(arow.ORDER_TIME),
		ORDER_SN(arow.ORDER_SN),
		ORDER_TYPE(arow.ORDER_TYPE),
		CUST_CODE(arow.CUST_CODE),
		CUACCT_CODE(arow.CUACCT_CODE),
		ORDER_AMT(arow.ORDER_AMT),
		WITHDRAWN_QTY(arow.WITHDRAWN_QTY),
		MATCHED_QTY(arow.MATCHED_QTY),
		MATCHED_AMT(arow.MATCHED_AMT),
		IS_WITHDRAW(arow.IS_WITHDRAW),
		IS_WITHDRAWN(arow.IS_WITHDRAWN)
	{
	}

	// assignment operator
  OrderRecord& operator=(const OrderRecord& arow);

  bool operator<(const OrderRecord& p) const;

  friend otl_stream& operator>>(otl_stream& s, OrderRecord& OrderRecord);
  
  friend otl_stream& operator<<(otl_stream& s, const OrderRecord& OrderRecord);


};
WITHDRAW_END

#endif //_ORDERRECORD_H