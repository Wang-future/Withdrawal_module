// ��Ȩ������������ģ�����ڻ�������ѧ���ѧԺ2016��UML���ʵѵ����ģ��
//
// �ļ����ƣ�common.h
// ģ�����ƣ�����ģ��
// ģ����������ģ���Ƕ�һЩ��Ķ��壬���������ռ䣬DLL����
//             �汾: 1.1.01
// �������ߣ��º���
// �������ڣ�2018-07-11
// ģ��汾��1.0.000.000
//------------------------------------------------------------
// �޸�����      �汾              ����            ��ע
//------------------------------------------------------------
// 2018-07-11  1.0.000.000    �º���          ԭ��
//------------------------------------------------------------
#define WITHDRAW_BEGIN namespace withdraw {
#define WITHDRAW_END   }


#ifdef WITHDRAWMODULE_EXPORTS
#define DLL_MODULE __declspec(dllexport)
#else
#define DLL_MODULE __declspec(dllimport)
#endif // DEBUG


#define OTL_ODBC_ALTERNATE_RPC
#if !defined(_WIN32) && !defined(_WIN64)
#define OTL_ODBC
#else 
#define OTL_ODBC_POSTGRESQL // required with PG ODBC on Windows
#endif

#define OTL_BIGINT  __int64
#define OTL_STR_TO_BIGINT(str,n) \
{ \
  n=_atoi64(str); \
}
#define OTL_BIGINT_TO_STR(n,str) \
{ \
  _i64toa(n,str,10); \
}

// #define OTL_ODBC_UNIX
// uncomment this line if UnixODBC is used
#define OTL_STL // Turn on STL features
#ifndef OTL_ANSI_CPP
#define OTL_ANSI_CPP // Turn on ANSI C++ typecasts
#endif
#include "otlv4.h" // include the OTL 4.0 header file