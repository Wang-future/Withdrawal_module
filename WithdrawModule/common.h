// 版权声明：本程序模块属于华南理工大学软件学院2016级UML软件实训撤单模块
//
// 文件名称：common.h
// 模块名称：撤单模块
// 模块描述：本模块是对一些宏的定义，包括命名空间，DLL导出
//             版本: 1.1.01
// 开发作者：陈浩锐
// 创建日期：2018-07-11
// 模块版本：1.0.000.000
//------------------------------------------------------------
// 修改日期      版本              作者            备注
//------------------------------------------------------------
// 2018-07-11  1.0.000.000    陈浩锐          原创
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