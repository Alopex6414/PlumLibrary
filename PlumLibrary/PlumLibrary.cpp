/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		PlumLibrary.cpp
* @brief	This Program is PlumLibrary DLL Project.
* @author	alopex
* @version	v1.00a
* @date		2017-04-21	v1.00a	alopex	Create Project.
*/
#include "PlumLibrary.h"

//This Project is Class With Dynamic Load DLL.(Simple)(BaseClass)

//------------------------------------------------------------------
// @Function:	 CPlumLibrary()
// @Purpose: CPlumLibrary构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CPlumLibrary::CPlumLibrary()
{
	m_hActive = NULL;
	memset(m_chLibraryArr, 0, MAX_PATH);
}

//------------------------------------------------------------------
// @Function:	 ~CPlumCipherA()
// @Purpose: CPlumCipherA析构函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CPlumLibrary::~CPlumLibrary()
{
	if (m_hActive) FreeLibrary(m_hActive);
}

//------------------------------------------------------------------
// @Function:	 CPlumLibrary(const char* pLibraryName)
// @Purpose: CPlumLibrary构造函数
// @Since: v1.00a
// @Para: const char* pLibraryName	(DLL路径名称)
// @Return: None
//------------------------------------------------------------------
CPlumLibrary::CPlumLibrary(const char* pLibraryName)
{
	assert(strlen(pLibraryName) < MAX_PATH);
	m_hActive = NULL;
	memset(m_chLibraryArr, 0, MAX_PATH);
	memcpy_s(m_chLibraryArr, MAX_PATH, pLibraryName, strlen(pLibraryName));
}

//------------------------------------------------------------------
// @Function:	 PlumLibraryGetHandle()
// @Purpose: CPlumLibrary获取动态链接库句柄
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
HMODULE PLUMLIBRARY_CALLMODE CPlumLibrary::PlumLibraryGetHandle(void) const
{
	return m_hActive;
}

//------------------------------------------------------------------
// @Function:	 PlumLibraryInit()
// @Purpose: CPlumLibrary初始化
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL PLUMLIBRARY_CALLMODE CPlumLibrary::PlumLibraryInit(const char* pLibraryName)
{
	if (!strcmp("", m_chLibraryArr))
	{
		assert(strlen(pLibraryName) < MAX_PATH);
		memset(m_chLibraryArr, 0, MAX_PATH);
		memcpy_s(m_chLibraryArr, MAX_PATH, pLibraryName, strlen(pLibraryName));
	}

	m_hActive = ::LoadLibraryA(m_chLibraryArr);
	if (!m_hActive)
	{
		return FALSE;	// FAIL
	}

	return TRUE;	// OK
}