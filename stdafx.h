// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#ifndef WINVER                          // ���w�̧C���x�ݨD�� Windows Vista�C
#define WINVER 0x0600           // �N���ܧ󬰰w�� Windows ��L�������A��ȡC
#endif

#ifndef _WIN32_WINNT            // ���w�̧C���x�ݨD�� Windows Vista�C
#define _WIN32_WINNT 0x0600     // �N���ܧ󬰰w�� Windows ��L�������A��ȡC
#endif						

#ifndef _WIN32_WINDOWS          // ���w�̧C���x�ݨD�� Windows 98�C
#define _WIN32_WINDOWS 0x0410 // �N���ܧ󬰰w�� Windows Me (�t) �H�᪩�����A��ȡC
#endif

#ifndef _WIN32_IE                       // ���w�̧C���x�ݨD�� Internet Explorer 7.0�C
#define _WIN32_IE 0x0700        // �N���ܧ󬰰w�� IE ��L�������A��ȡC
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions





#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �䴩�� Internet Explorer 4 �q�α��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �䴩�� Windows �q�α��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �\��ϩM����C�� MFC �䴩

#include <conio.h>
#include <afxinet.h>

#include "StBaseType.h"
#include "Vender_newGNSS.h"
#include "Global.h"

