/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		PlumLibrary.h
* @brief	This Program is PlumLibrary DLL Project.
* @author	alopex
* @version	v1.00a
* @date		2017-04-21	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __PLUMLIBRARY_H_
#define __PLUMLIBRARY_H_

//Include Windows Header File
#include <Windows.h>

//Include C/C++ Running Header File
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <mmreg.h>
#include <wchar.h>
#include <tchar.h>
#include <time.h>
#include <mmsystem.h>
#include <assert.h>

//Macro Definition
#ifdef PLUMLIBRARY_EXPORTS
#define PLUMLIBRARY_API __declspec(dllexport)
#else
#define PLUMLIBRARY_API __declspec(dllimport)
#endif

#define PLUMLIBRARY_CALLMODE __stdcall

//Class Definition
class PLUMLIBRARY_API CPlumLibrary
{
private:
	HMODULE m_hActive;						//Dynamic Link Library Handle
	char m_chLibraryArr[MAX_PATH];		//Dynamic Link Library Name Array

public:
	CPlumLibrary();		//Construction Function(����)
	~CPlumLibrary();		//Destruction Function(����)

	// ����
	CPlumLibrary(const char* pLibraryName);		//Construction Function(����)(����+1)

	// ����
	virtual HMODULE PLUMLIBRARY_CALLMODE PlumLibraryGetHandle(void) const;			//PlumLibrary Get Handle(PlumLibrary ���ʾ��)

	// ��ʼ��
	virtual BOOL PLUMLIBRARY_CALLMODE PlumLibraryInit(const char* pLibraryName);	//PlumLibrary Initialize(PlumLibrary ��ʼ��)
	virtual BOOL PLUMLIBRARY_CALLMODE PlumLibraryInitFunction() = 0;							//PlumLibrary Initialize Function(PlumLibrary ��ʼ������)

};

#endif