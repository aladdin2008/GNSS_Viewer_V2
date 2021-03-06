#include "stdafx.h"
#include "Utility.h"
#include <tlhelp32.h>

void Utility::Log(const char* str1, const char* str2, int n)
{
	CString strLog; 
	strLog.Format("%s, %s(%d)", str1, str2, n);
	::OutputDebugString(strLog);
}

void Utility::Log2(const char* function, int line, const char* str)
{
	CString strLog; 
	strLog.Format("%s(%d)-%s", function, line, str);
	::OutputDebugString(strLog);
}
//
//void Utility::LogDword(const char* str1, DWORD d, int n)
//{
//	CString strLog; 
//	strLog.Format("%s, %d(%d)", str1, d, n);
//	::OutputDebugString(strLog);
//}

void Utility::LogFatal(const char* str1, const char* str2, int n)
{
	CString strLog; 
	strLog.Format("%s, %s(%d)!!!", str1, str2, n);
	::OutputDebugString(strLog);
}

DWORD Utility::GetRegValue(HKEY hKeyHandle, LPCTSTR lpSubkey, LPCTSTR lpRegName, CString &csRegvalue)
{
	const int nBufferSize = 256;
	HKEY hKey;
	LONG lRet;
	DWORD dwDataSize;
	DWORD dwType;
	TCHAR pchBuf[nBufferSize];
	DWORD uRetCode = ERROR_SUCCESS;

	lRet = RegOpenKeyEx(hKeyHandle, 
						lpSubkey,
						0, 
						KEY_QUERY_VALUE, 
						&hKey);

	if( lRet != ERROR_SUCCESS )
	{
		return lRet;			
	}

	dwDataSize = nBufferSize;
	dwType     = REG_SZ;
	lRet = RegQueryValueEx(hKey, lpRegName, NULL, &dwType, (LPBYTE)pchBuf, &dwDataSize);

	if( lRet != ERROR_SUCCESS )
	{
		RegCloseKey(hKey);
		return lRet;
	}
	lRet = RegCloseKey(hKey);
	if( lRet != ERROR_SUCCESS )
	{
		return lRet;
	}

	if(dwDataSize > 0)
	{
		csRegvalue = pchBuf;
	}
	else
	{
		csRegvalue.Empty();
	}
	return ERROR_SUCCESS;
}

DWORD Utility::GetRegValue(HKEY hKeyHandle, LPCTSTR lpSubkey, LPCTSTR lpRegName, int &nRegvalue)
{
	CString strRegValue;
	DWORD dwRet;
	dwRet = GetRegValue(hKeyHandle, lpSubkey, lpRegName, strRegValue);
	if( dwRet != ERROR_SUCCESS )
	{
		return dwRet;
	}
	nRegvalue = _ttoi(strRegValue);
	return dwRet;
}

DWORD Utility::SetRegValue(HKEY hKeyHandle, LPCTSTR lpSubkey, LPCTSTR lpRegName, LPCTSTR szRegvalue)
{
	HKEY    hKey;
	LONG	lRet;
	DWORD	dwReturn;
	DWORD	dwKeySize;
	DWORD	uRetCode = ERROR_SUCCESS;
	CString csRegvalue(szRegvalue);

	lRet = RegCreateKeyEx(hKeyHandle,
			              lpSubkey,
						  0,
						  NULL,
						  REG_OPTION_NON_VOLATILE,
						  KEY_ALL_ACCESS,
						  NULL,
						  &hKey,
						  &dwReturn);

	if(lRet != ERROR_SUCCESS)
	{
		return lRet;
	}

	dwKeySize = csRegvalue.GetLength() * sizeof(TCHAR);

	lRet = RegSetValueEx(hKey, lpRegName, 0, REG_SZ, (LPBYTE)(LPCTSTR)csRegvalue, dwKeySize);
	if( lRet != ERROR_SUCCESS)
	{
		return lRet;
	}

	lRet = RegCloseKey(hKey);
	if( lRet != ERROR_SUCCESS)
	{
		return lRet;
	}
	return ERROR_SUCCESS;
}

DWORD Utility::SetRegValue(HKEY hKeyHandle, LPCTSTR lpSubkey, LPCTSTR lpRegName, int &nRegvalue)
{
	CString strRegValue;
	DWORD dwRet;
	strRegValue.Format(_T("%d"), nRegvalue);
	dwRet = SetRegValue(hKeyHandle, lpSubkey, lpRegName, strRegValue);
	return dwRet;
}

//Read UTF-8 format file to an unicode text buffer.
BOOL Utility::ReadU8FileToUText(LPCTSTR pszFile, CStringW& strOutText)
{
	CStringA strUTF8;
	CFile fNib;
	//Read an UTF-8 text file to pU8Buffer
	fNib.Open(pszFile, CFile::modeRead);
	int nSize = (int)fNib.GetLength();
	char *pU8Buffer = strUTF8.GetBuffer(nSize + 1);	//UTF-8 buffer
	fNib.Read(pU8Buffer, nSize);
	strUTF8.ReleaseBuffer();
	fNib.Close();

	//Convert pU8Buffer from UTF-8 to Unicode
	int count = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1 ,NULL,0);
	LPWSTR pszUnicode = strOutText.GetBuffer(count);
	MultiByteToWideChar(CP_UTF8, 0, pU8Buffer, -1, pszUnicode, count);
	strOutText.ReleaseBuffer();
	return TRUE;
}

//Write Unicode format text to an utf-8 file.
BOOL Utility::WriteUTextToU8File(LPCTSTR pszFile, LPCWSTR pszInputText)
{
	int count = WideCharToMultiByte(CP_UTF8, 0, pszInputText, -1 ,NULL, 0, NULL, NULL);
	CStringA strUTF8;
	char *pU8Buffer = strUTF8.GetBuffer(count);	//UTF-8 buffer
	WideCharToMultiByte(CP_UTF8, 0, pszInputText, -1 ,pU8Buffer, count, NULL, NULL);
	strUTF8.ReleaseBuffer();

	CFile fNibNew;
	//Write an UTF-8 text file from pU8Buffer
	fNibNew.Open(pszFile, CFile::modeWrite | CFile::modeCreate);
	fNibNew.Write(strUTF8, count - 1);	//Text file doesn't need null ending.
	fNibNew.Close();
	return TRUE;
}

const int unicodeMarkLen = 2;
union UnicodeMark
{
	BYTE mark_b[unicodeMarkLen];
	WORD mark_w;
};

//Read unicode big endian format file to an unicode text buffer.
void Utility::ConvertBE2LE(void* pBuffer, int nSize)
{
	int nSizeInWord = nSize / sizeof(WORD);
	WORD* pWordBuf = (WORD*)pBuffer;
	WORD tmp;
	while(nSizeInWord--)
	{
		tmp = (*pWordBuf)>>8;
		tmp |= (*pWordBuf)<<8;
		*pWordBuf = tmp;
		++pWordBuf;
	}
}

BOOL Utility::ReadUFileToUText(LPCTSTR pszFile, CStringW& strOutText, BOOL& bBigEndian)
{
	UnicodeMark umark;
	CFile fNib;
	//Read an UTF-8 text file to pU8Buffer
	BOOL bRet = fNib.Open(pszFile, CFile::modeRead);
	int nSize = (int)fNib.GetLength();
	fNib.Read(umark.mark_b, unicodeMarkLen);
	if(0xfffe == umark.mark_w)
	{
		bBigEndian = TRUE;
	}
	else if(0xfeff == umark.mark_w)
	{
		bBigEndian = FALSE;
	}
	else
	{
		return FALSE;
	}

	wchar_t *pUBuffer = strOutText.GetBuffer(nSize - unicodeMarkLen + 2);	//Unicode buffer
	ZeroMemory(pUBuffer, nSize - unicodeMarkLen + 2);
	fNib.Read(pUBuffer, nSize - unicodeMarkLen);
	if(bBigEndian)
	{
		ConvertBE2LE(pUBuffer, nSize - unicodeMarkLen);
	}
	fNib.Close();
	strOutText.ReleaseBuffer();
	return TRUE;
}

//Write Unicode format text to an unicode big endian file.
BOOL Utility::WriteUTextToUBFile(LPCTSTR pszFile, LPCWSTR pszInputText, BOOL bBigEndian)
{
	UnicodeMark umark;
	if(bBigEndian)
	{
		umark.mark_w = 0xfffe;
	}
	else
	{
		umark.mark_w = 0xfeff;
	}

	CFile fNibNew;
	fNibNew.Open(pszFile, CFile::modeWrite | CFile::modeCreate);
	fNibNew.Write(umark.mark_b, unicodeMarkLen);

	int nSize = (int)wcslen(pszInputText) * sizeof(wchar_t);
	if(bBigEndian)
	{
		int nSizeInWord = nSize / sizeof(WORD);
		const WORD* pWordBuf = (const WORD*)pszInputText;
		WORD tmp;
		while(nSizeInWord--)
		{
			tmp = (*pWordBuf)>>8;
			tmp |= (*pWordBuf)<<8;
			fNibNew.Write(&tmp, sizeof(WORD));	//Text file doesn't need null ending.
			++pWordBuf;
		}
	}
	else
	{
		fNibNew.Write(pszInputText, nSize);	//Text file doesn't need null ending.
	}

	fNibNew.Close();
	return TRUE;
}

// strResult - command standard output
// return Exit code of command line 
DWORD Utility::ExecuteExternalFileW(LPCWSTR csCmdLine, CString& strResult)
{
	CStringW strCmdLine(csCmdLine);
	strResult.Empty();

	SECURITY_ATTRIBUTES secattr; 
	ZeroMemory(&secattr,sizeof(secattr));
	secattr.nLength = sizeof(secattr);
	secattr.bInheritHandle = TRUE;

	//Create pipes to write and read data
	HANDLE rPipe, wPipe;
	CreatePipe(&rPipe, &wPipe, &secattr, 0);

	STARTUPINFOW sInfo; 
	ZeroMemory(&sInfo, sizeof(sInfo));
	PROCESS_INFORMATION pInfo; 
	ZeroMemory(&pInfo, sizeof(pInfo));

	sInfo.cb = sizeof(sInfo);
	sInfo.dwFlags = STARTF_USESTDHANDLES;
	sInfo.hStdInput = NULL; 
	sInfo.hStdOutput = wPipe; 
	sInfo.hStdError = wPipe;

	//Create the process here.
	CreateProcessW(0, (LPWSTR)(LPCWSTR)strCmdLine, 
		0, 0, TRUE,
		NORMAL_PRIORITY_CLASS|CREATE_NO_WINDOW, 0, 0,
		&sInfo, &pInfo);
	CloseHandle(wPipe);

	//now read the output pipe here.
	const int nReadBlockSize = 1024;
	char buf[nReadBlockSize + 1];
	DWORD reDword; 
	CString csTemp;
	BOOL res;
	do
	{
		ZeroMemory(buf, nReadBlockSize + 1);
		res = ::ReadFile(rPipe, buf, nReadBlockSize, &reDword, 0);
		csTemp = buf;
		strResult += csTemp.Left(reDword);
	} while(res);

	//Get Exit Code
	DWORD dwResult;
	do
	{
		::GetExitCodeProcess(pInfo.hProcess, &dwResult);
		Sleep(100);
	}
	while(STILL_ACTIVE == dwResult);
	return dwResult;
}

BOOL Utility::ExecuteExeNoWait(LPCSTR csCmdLine)
{
	CStringW strCmdLine(csCmdLine);

	SECURITY_ATTRIBUTES secattr; 
	ZeroMemory(&secattr,sizeof(secattr));
	secattr.nLength = sizeof(secattr);
	secattr.bInheritHandle = TRUE;

	STARTUPINFOW sInfo; 
	ZeroMemory(&sInfo, sizeof(sInfo));
	PROCESS_INFORMATION pInfo; 
	ZeroMemory(&pInfo, sizeof(pInfo));

	sInfo.cb = sizeof(sInfo);
	sInfo.dwFlags = STARTF_USESTDHANDLES;
	sInfo.hStdInput = NULL; 
	sInfo.hStdOutput = NULL; 
	sInfo.hStdError = NULL;

	//Create the process here.
	return CreateProcessW(0, (LPWSTR)(LPCWSTR)strCmdLine, 
		0, 0, TRUE,
		NORMAL_PRIORITY_CLASS|CREATE_NO_WINDOW, 0, 0,
		&sInfo, &pInfo);
}

BOOL Utility::ExecuteExeWait(LPCSTR csCmdLine)
{
	CStringW strCmdLine(csCmdLine);

	SECURITY_ATTRIBUTES secattr; 
	ZeroMemory(&secattr,sizeof(secattr));
	secattr.nLength = sizeof(secattr);
	secattr.bInheritHandle = TRUE;

	STARTUPINFOW sInfo; 
	ZeroMemory(&sInfo, sizeof(sInfo));
	PROCESS_INFORMATION pInfo; 
	ZeroMemory(&pInfo, sizeof(pInfo));

	sInfo.cb = sizeof(sInfo);
	sInfo.dwFlags = STARTF_USESTDHANDLES;
	sInfo.hStdInput = NULL; 
	sInfo.hStdOutput = NULL; 
	sInfo.hStdError = NULL;

	//Create the process here.
	BOOL result =  CreateProcessW(0, (LPWSTR)(LPCWSTR)strCmdLine, 
		0, 0, TRUE,
		NORMAL_PRIORITY_CLASS|CREATE_NO_WINDOW, 0, 0,
		&sInfo, &pInfo);

  if(!result)
  {
      return FALSE;
  }
  else
  {
    DWORD exitCode;
    // Successfully created the process.  Wait for it to finish.
    WaitForSingleObject(pInfo.hProcess, INFINITE);

    // Get the exit code.
    result = GetExitCodeProcess(pInfo.hProcess, &exitCode);

    // Close the handles.
    CloseHandle(pInfo.hProcess);
    CloseHandle(pInfo.hThread);

    if(!result)
    {
       // Could not get exit code.
       return FALSE;
    }
    // We succeeded.
    return TRUE;
  }
}

bool Utility::IsProcessRunning(LPWSTR processName)
{
	CStringW name(processName);
  bool exists = false;
  PROCESSENTRY32W entry = { 0 };
  entry.dwSize = sizeof(entry);

  HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
  if(Process32FirstW(snapshot, &entry))
  {
    while(Process32NextW(snapshot, &entry))
	    if(0 == name.Compare(entry.szExeFile))
        exists = true;
  }
  CloseHandle(snapshot);
  return exists;
}

bool Utility::IsNamedPipeUsing(LPCTSTR name)
{
	CString pipeName;
	pipeName.Format("//./pipe/%s", name);
	HANDLE h = CreateFile(pipeName, GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE , NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);
	if(h != INVALID_HANDLE_VALUE)
	{
		::CloseHandle(h);
	}
  return (h != INVALID_HANDLE_VALUE);
}

// delete directory
BOOL Utility::DeleteDirectory(LPCTSTR pszSrcDir, BOOL bSilent, BOOL bConfirm)
{
	ASSERT(pszSrcDir);
	CWaitCursor WaitCursor;

	SHFILEOPSTRUCT fos;
	FILEOP_FLAGS flags = 0;
	if(bSilent)
	{
		flags |= FOF_SILENT;
	}

	if(!bConfirm)
	{
		flags |= FOF_NOCONFIRMATION;
	}
 
	memset(&fos, 0, sizeof(SHFILEOPSTRUCT));
	CWnd *pWnd = AfxGetMainWnd();
	fos.hwnd = pWnd->GetSafeHwnd();
	fos.wFunc = FO_DELETE;
	fos.fFlags = flags;

	CString strSrc(pszSrcDir);
	int nSrcLen = strSrc.GetLength();
	LPTSTR pszFileList = strSrc.GetBuffer(nSrcLen + 2);
	for(int i=0; i<nSrcLen; ++i)
	{
		if(pszFileList[i]==_T('|'))
		{
			pszFileList[i] = 0;
		}
	}
	pszFileList[nSrcLen + 1] = 0;

	fos.pFrom = pszFileList;
	int nRet = SHFileOperation(&fos);
	strSrc.ReleaseBuffer();
	return nRet==0;
}

// Copy files
// pszSrcFiles - file list, sparate by '|' ex: "file1.ext|file2.ext|file3.exe"
// if more than one file, pszNewName will be ignored.
BOOL Utility::CopyFiles(LPCTSTR pszSrcFiles, LPCTSTR pszDestFolder, LPCTSTR pszNewName, BOOL bSilent, BOOL bConfirm)
{
	ASSERT(pszSrcFiles);
	ASSERT(pszDestFolder);
	CWaitCursor WaitCursor;

	SHFILEOPSTRUCT fos;
	FILEOP_FLAGS flags = 0;
	if(bSilent)
	{
		flags |= FOF_SILENT;
	}

	if(!bConfirm)
	{
		flags |= FOF_NOCONFIRMATION;
	}
 
	memset(&fos, 0, sizeof(SHFILEOPSTRUCT));
	CWnd *pWnd = AfxGetMainWnd();
	fos.hwnd = pWnd->GetSafeHwnd();
	fos.wFunc = FO_COPY;
	fos.fFlags = flags;

	CString strSrc(pszSrcFiles);
	int nSrcLen = strSrc.GetLength();
	LPTSTR pszFileList = strSrc.GetBuffer(nSrcLen + 2);
	BOOL bMultiSrc = FALSE;
	for(int i=0; i<nSrcLen; ++i)
	{
		if(pszFileList[i]==_T('|'))
		{
			pszFileList[i] = 0;
			bMultiSrc = TRUE;
		}
	}
	pszFileList[nSrcLen + 1] = 0;
	fos.pFrom = pszFileList;

	CString strDst(pszDestFolder);
	if(!bMultiSrc)
	{
		strDst += _T("\\");
		strDst += pszNewName;
	}
	int nDstLen = strDst.GetLength();
	LPTSTR pszDst = strDst.GetBuffer(nDstLen + 2);	//Double null-terminator
	pszDst[nDstLen + 1] = 0;
	fos.pTo = pszDst;

	int nRet = SHFileOperation(&fos);
	strSrc.ReleaseBuffer();
	strDst.ReleaseBuffer();
	return nRet==0;
}

CString Utility::GetFilePath(LPCTSTR pszPathname)
{
	CString strRet(pszPathname);
	int nSlash1 = strRet.ReverseFind(_T('\\'));
	int nSlash2 = strRet.ReverseFind(_T('/'));
	int nSlash = max(nSlash1, nSlash2);
	BOOL bColon = (strRet.GetLength()>=2)? strRet.GetAt(1)==_T(':') :FALSE;
	if(-1 == nSlash && !bColon)	//No slash and no colon, it's mean no path
	{
		return CString(_T(""));
	}
	else if(nSlash > 0)	//Has slash, before slash is the path.
	{
		strRet = strRet.Left(nSlash);
	}
	else	//No slash but has colon, the device letter is the path
	{	
		strRet = strRet.Left(2);
	}
	return strRet;
}

CString Utility::GetFileName(LPCTSTR pszPathname)
{
	CString strRet(pszPathname);
	int nSlash1 = strRet.ReverseFind(_T('\\'));
	int nSlash2 = strRet.ReverseFind(_T('/'));
	int nSlash = max(nSlash1, nSlash2);
	BOOL bColon = (strRet.GetLength()>=2)? strRet.GetAt(1)==_T(':') :FALSE;
	if(-1 == nSlash && !bColon)	//No slash and no colon, it's mean no path
	{
		return strRet;
	}
	else if(nSlash>0)	//Has slash, before slash is the path.
	{
		
		strRet = strRet.Right(strRet.GetLength() - nSlash - 1);
	}
	else	//No slash but has colon, the device letter is the path
	{	
		strRet = strRet.Left(strRet.GetLength() - 3);
	}
	return strRet;
}

// Copy files
// pszSrcFiles - file pathname. ex: "c:\\file1.ext"
// pszNewName - new file name, does not include path. ex: "filenewname.ext"
BOOL Utility::RenameFile(LPCTSTR pszSrcFile, LPCTSTR pszNewName, BOOL bSilent, BOOL bConfirm)
{
	ASSERT(pszSrcFile);
	ASSERT(pszNewName);
	CWaitCursor WaitCursor;

	SHFILEOPSTRUCT fos;
	FILEOP_FLAGS flags = 0;
	if(bSilent)
	{
		flags |= FOF_SILENT;
	}

	if(!bConfirm)
	{
		flags |= FOF_NOCONFIRMATION;
	}
 
	memset(&fos, 0, sizeof(SHFILEOPSTRUCT));
	CWnd *pWnd = AfxGetMainWnd();
	fos.hwnd = pWnd->GetSafeHwnd();
	fos.wFunc = FO_RENAME;
	fos.fFlags = flags;

	CString strSrc(pszSrcFile);
	int nSrcLen = strSrc.GetLength();
	LPTSTR pszFileList = strSrc.GetBuffer(nSrcLen + 2);
	pszFileList[nSrcLen + 1] = 0;	//Double null-terminator
	fos.pFrom = pszFileList;

	CString strDst = GetFilePath(pszSrcFile);
	strDst += _T("\\");
	strDst += pszNewName;
	int nDstLen = strDst.GetLength();
	LPTSTR pszDst = strDst.GetBuffer(nDstLen + 2);	//Double null-terminator
	pszDst[nDstLen + 1] = 0;
	fos.pTo = pszDst;

	int nRet = SHFileOperation(&fos);
	strSrc.ReleaseBuffer();
	strDst.ReleaseBuffer();
	return nRet==0;
}

CString Utility::GetFileExt(LPCTSTR pszPathname)
{
	CString strRet(pszPathname);
	int nDot = strRet.ReverseFind(_T('.'));
	if(-1 == nDot)
	{
		return _T("");
	}
	int nSlash1 = strRet.ReverseFind(_T('\\'));
	int nSlash2 = strRet.ReverseFind(_T('/'));
	int nSlash = max(nSlash1, nSlash2);
	if(nSlash > nDot)
	{
		return CString(_T(""));
	}
	else
	{
		strRet = strRet.Right(strRet.GetLength() - nDot - 1);
	}
	return strRet;
}

bool Utility::WriteBufferToFileAddNew(LPCTSTR filePath, void* pBuf, DWORD size)
{
  CFile file;
  if(!file.Open(filePath, CFile::modeReadWrite | CFile::shareDenyWrite))
  {
    return false;
  }
	file.SeekToEnd();
  file.Write(pBuf, size);
  file.Close();
  return true;
}

CString Utility::GetFilePathName(LPCTSTR pszPathname)
{
	CString strRet(pszPathname);
	int nDot = strRet.ReverseFind(_T('.'));
	if(-1 == nDot)
	{
		return strRet;
	}

	strRet = strRet.Left(nDot);
	return strRet;
}

BOOL Utility::CopyResToFile(LPCTSTR szDesFileName, DWORD dRes, LPCTSTR szType)
{
	HANDLE			hFile;	
	HRSRC			hRsrc;	
	DWORD			cntBytes, cbWrite;	
	HGLOBAL			hGlob;	
	LPVOID			lp;	
	CString			csTmp(szDesFileName);	 
	int				i;	
 
	//Copy App to distination directory, and we finish clone....
	HINSTANCE  hResource = AfxGetResourceHandle();

	hRsrc = FindResource(hResource, MAKEINTRESOURCE(dRes), szType);	
	if(hRsrc == NULL)	
		return 0;	

	cntBytes = SizeofResource(AfxGetResourceHandle(), hRsrc);	
	if(cntBytes <= 0)		
		return 0;	
	 
	hGlob = LoadResource(AfxGetResourceHandle(), hRsrc);	
	if(hGlob == NULL)		
		return 0;	
	lp = LockResource(hGlob);	
	if(lp == NULL)	
	{	
		FreeResource(hGlob);
		return 0;
	}	
	//Create folder
	if ((i = csTmp.ReverseFind('\\')) > 2)
	{
		csTmp.SetAt(i+1, '\0');
		LPVOID lpMsgBuf;


		if (!CreateDirectory(csTmp, NULL))
		{
			
			int nResult = GetLastError();
			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM
						| FORMAT_MESSAGE_IGNORE_INSERTS, NULL, nResult, 
						MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
						(LPTSTR) &lpMsgBuf, 0, NULL);
			
			if (nResult != ERROR_ALREADY_EXISTS)
			{
			//	MessageBox(NULL, (LPTSTR)lpMsgBuf, "Install driver", MB_OK);
				LocalFree(lpMsgBuf);
				return 0;
			}
			LocalFree(lpMsgBuf);
		}
	}

	if((hFile = CreateFile(szDesFileName, GENERIC_READ|GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
							FILE_ATTRIBUTE_NORMAL, NULL))==INVALID_HANDLE_VALUE)
	{		
		DWORD derr = GetLastError();
		UnlockResource(hGlob);		
		FreeResource(hGlob);		
		//MessageBox(NULL, "Can't create file! Install fail!", "Install driver", MB_OK);
		return 0;	
	}	
	if(!WriteFile(hFile, lp, cntBytes, &cbWrite, NULL))	
	{		
		CloseHandle(hFile);	
		DeleteFile(szDesFileName);
		UnlockResource(hGlob);
		FreeResource(hRsrc);	
		//MessageBox(NULL, "Can't write directory! Install fail!", "Install driver", MB_OK);
		return 0;	
	}
	CloseHandle(hFile);
	UnlockResource(hGlob);
	FreeResource(hRsrc);
	return TRUE;
}

double Utility::GetPrivateProfileDouble(LPCSTR appName, LPCSTR keyName, LPCSTR defaultString, LPCSTR fileName)
{
	CString strBuffer;
	const int bufferSize = 1024;
	GetPrivateProfileString(appName, keyName, defaultString, strBuffer.GetBuffer(bufferSize), bufferSize, fileName);
	strBuffer.ReleaseBuffer();
	return atof(strBuffer);
}

U32 Utility::GetPrivateProfileHex(LPCSTR appName, LPCSTR keyName, U32 defaultValue, LPCSTR fileName)
{
	CString strBuffer, defaultString;
  defaultString.Format("%08X", defaultValue);
	const int bufferSize = 1024;
	GetPrivateProfileString(appName, keyName, defaultString, strBuffer.GetBuffer(bufferSize), bufferSize, fileName);
	strBuffer.ReleaseBuffer();

  return strtoul(strBuffer, NULL, 16);
}

bool Utility::IsFileExist(const char* filePath)
{
	return (INVALID_FILE_ATTRIBUTES != ::GetFileAttributes(filePath));
}

int Utility::LSB(char lsb)
{
	if(lsb>='0' && lsb<='9')
	{
		return (lsb - '0');
	}
	else if(lsb>='A' && lsb<='F')
	{
		return (lsb - 'A' + 0xA);
	}
	else
	{
//		ASSERT(FALSE);
	}
	return 0;
}

int Utility::MSB(char msb)
{
	return LSB(msb) * 0x10;
}	

int Utility::GetHexValue(char highByte, char lowByte)
{
	return LSB(highByte) * 16 + LSB(lowByte);
}

int Utility::GetOctValue(char highByte, char lowByte)
{
	return LSB(highByte) * 10 + LSB(lowByte);
}

CString Utility::ErrorString(DWORD err)
{
	CString strError;
	LPTSTR s;
	if(::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		err,
		0,
		(LPTSTR)&s,
		0,
		NULL) == 0)
	{ /* failed */
		// Unknown error code %08x (%d)
	//	CString fmt;
	//	CString t;
	//	fmt.LoadString(IDS_UNKNOWN_ERROR);
	//	t.Format(fmt, err, LOWORD(err));
	//	Error = t;
	} /* failed */
	else
	{ /* success */
		LPTSTR p = _tcschr(s, _T('\r'));
		if(p != NULL)
		{ /* lose CRLF */
			*p = _T('\0');
		} /* lose CRLF */
		strError = s;
		::LocalFree(s);
	} /* success */
	return strError;
} // ErrorString

int Utility::FindNextNoneSpaceChar(LPCSTR pszInput, bool forward)
{
	int index = (forward) ? 0 : strlen(pszInput) - 1;

	if(index < 0)
	{
		return index;
	}

	while(pszInput[index]==' ')
	{
		index += (forward) ? 1 : -1;
	}
	index += (forward) ? 0 : 1;

	return index;
}	

bool CheckHex(LPCSTR pszInput)
{
	for(const char* c = pszInput; *c != 0; ++c)
	{
		if(*c >= '0' && *c <= '9')
			continue;
		if(*c >= 'a' && *c <= 'f')
			continue;
		if(*c >= 'A' && *c <= 'F')
			continue;
		return false;
	}
	return true;
}

bool Utility::ConvertHexToBinary(LPCSTR pszInput, BinaryData& binData)
{
	CString strInput(pszInput);
	if(strInput.GetLength()<2)
	{
		return false;
	}
	strInput.MakeLower();

	int index = FindNextNoneSpaceChar(strInput);
	//Trim the space character in head.
	if(index > 0)
	{
		strInput = strInput.Right(strInput.GetLength() - index);
	}

	if(strInput.GetLength() == 0)
	{
		return false;
	}

	//Trim the space character in tail.
	index = FindNextNoneSpaceChar(strInput, false);
	if(index < strInput.GetLength())
	{
		strInput = strInput.Left(index);
	}

	int i = 0;	// size of output binary.
	int n = 0;	// index of input string
	BinaryData b(strlen(pszInput) / 2 + 1);

	CString token = strInput.Tokenize(" \r\n\t", n);
	while(n != -1)
	{
		if(!CheckHex(token))
		{
			return false;
		}
		long data = strtol(token, NULL, 16);
		if(data > 255)
		{
			return false;
		}
		*b.GetBuffer(i++) = (char)data;
		token = strInput.Tokenize(" \r\n\t", n);
	}

	if(i)
	{
 		binData.Alloc(i);
		memcpy(binData.GetBuffer(), b.Ptr(), i);
	}
	return true;
}

bool Utility::ConvertBinaryToHex(const BinaryData& binData, CString& strOutput, int startIndex, int maxCount, int lineCount)
{
	strOutput.Empty();
	CString txt;
	for(int i=0; i<maxCount; ++i)
	{
		txt.Format("%02X ", *binData.Ptr(i + startIndex));
		strOutput += txt;
		if( (i + 1) % lineCount == 0)
		{
			strOutput += "\r\n";
		}
	}
	return true;
}

CString Utility::GetSpecialFolder(INT iFolder)	//CSIDL_APPDATA
{
	LPITEMIDLIST pidl;
	SHGetSpecialFolderLocation(NULL, iFolder, &pidl);
	CString strPath;
	SHGetPathFromIDList(pidl, strPath.GetBufferSetLength(MAX_PATH));
	strPath.ReleaseBuffer();

	// Clean up
	LPMALLOC pMalloc;
	SHGetMalloc(&pMalloc);
	pMalloc->Free(pidl);
	pMalloc->Release();
	return strPath;
}

CString Utility::GetNameAttachPid(LPCSTR name)
{
	DWORD pid = GetCurrentProcessId();
	CString r;
	r.Format("%s%08X", name, pid);
	//r.Format("%s", name);
	return r;
}

void Utility::DoEvents()
{
    MSG msg;
    BOOL result;

    while(::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
    {
        result = ::GetMessage(&msg, NULL, 0, 0);
        if(result == 0) // WM_QUIT
        {                
            ::PostQuitMessage(msg.wParam);
            break;
        }
        else if (result == -1)
        {
             // Handle errors/exit application, etc.
        }
        else 
        {
            ::TranslateMessage(&msg);
            :: DispatchMessage(&msg);
        }
    }
}

void Utility::GetErrorString(CString& msg, DWORD errorCode)
{
	LPVOID lpMsgBuf = NULL;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL);

	msg.Format("%s", lpMsgBuf);
	LocalFree(lpMsgBuf);
}

//flashSize 0 is auto detect
bool Utility::CalcFirmwareCrc(const CString& fwPath, int flashSize, 
                              U16& crcM, U16& crcS, 
                              U32& crc32_16m, 
                              U32& crc32_8m, 
                              U08& checkSum)
{
  if(!Utility::IsFileExist(fwPath))
  {
    return false;
  }

  BinaryData fw(fwPath);
  crcM = 0;
  crcS = 0;
  crc32_16m = 0;
  crc32_8m = 0;
  checkSum = 0;

  //if(fw.Size() <= oneMFlashSize)
  //{

  //}
  //else
  //{
  //}


  for (int i = 0; i < fw.Size(); ++i)
  {
    crcM += fw[i];
    crc32_16m += fw[i];
    crc32_8m += fw[i];
    checkSum += fw[i];
  }
  crcS = crcM;
  int realFlashSize = flashSize;
  int oneMFlashSize = 1024 * 1024;
  if(flashSize == 0)
  {
    realFlashSize = 2 * 1024 * 1024;
  }

  for (int i = fw.Size(); i < oneMFlashSize; ++i)
  {
    crcM += 0xFF;
    crc32_16m += 0xFF;
  }
  crc32_8m = crc32_16m;
  for (int i = (fw.Size() < oneMFlashSize) ? oneMFlashSize : fw.Size(); i < realFlashSize; ++i)
  {
    crcM += 0xFF;
    crc32_16m += 0xFF;
  }
  return true;
}


bool Utility::CheckPromUniqueTag(const CString& imgPath, U32& tagPos, bool& emptyTag)
{
  if(!Utility::IsFileExist(imgPath))
  {
    return false;
  }

  BinaryData img(imgPath);
  tagPos = 0;
  if(img.Size() <= 0)
  {
    return false;
  }

  //U08* buff = new U08[imgSize];
  //UINT s = f.Read(buff, imgSize);
  //f.Close();

  //if(s != imgSize)
  //{
  //  delete [] buff;
  //  return false;
  //}
  UINT s = (UINT)img.Size();
  U08 checkPattern[] = { 0x21, 0x22, 0x23, 0x24, 0x26, 0x2A, 0x28, 0x29, 
                         0x2F, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40 };
  int checkSize = sizeof(checkPattern);
  U08 *p = img.GetBuffer(0);
  while (true) 
  {
    U08* ptr = (U08*)memchr(p, checkPattern[0], s); 
    if(ptr == NULL)
    { //Not found
      p = NULL;
      break;
    }
    if(0 == memcmp(ptr, checkPattern, checkSize))
    { //Pattern found
      p = ptr;
      break;
    }
    s -= (ptr - p) + 1;
    if(s <= 0)
    {
      p = NULL;
      break;
    }
    p = ptr + 1;
  }

  if(p)
  {
    tagPos = (int)(p - img.GetBuffer(0)) - 16;
    p = img.GetBuffer(0) + tagPos;
    emptyTag = true;
    for(int i = 0; i < 16; ++i)
    {
      if(*p != 0xFF)
      {
        emptyTag = false;
        return true;
      }
    }
    return true;
  }
  return false;
}

DWORD Utility::GetStqBinary(void *buffer, DWORD bufferSize, CFile& f)
{	
	U08* bufferIter = (U08*)buffer;
	DWORD totalSize = 0;
	DWORD failCount = 10;
  bool hasHeader = false;
  bool hasSize = false;
  U16 headerSize = 0;
	while(totalSize < bufferSize - 1)
	{ 
		DWORD dwBytesDoRead = 0;
		DWORD dwErrorFlags = 0;

		DWORD bytesinbuff = (DWORD)(f.GetLength() - f.GetPosition());
		while(bytesinbuff)
		{
			BOOL bb = ReadFile(f.m_hFile, bufferIter, 1, &dwBytesDoRead, 0);
			if(dwBytesDoRead <= 0)
			{	//Read fail.
				DWORD dwErr = ::GetLastError();
				break;
			}

			if(totalSize > 0)
			{	//not first char.
				if(!hasHeader && *bufferIter == 0xa1 && *(bufferIter - 1) == 0xa0)
				{
					bufferIter -= totalSize;
					*bufferIter = 0xa0; 
					++bufferIter;
					*bufferIter = 0xa1; 
					++bufferIter;
					totalSize = 2;
          hasHeader = true;
					continue;
				}
				else if(hasHeader && hasSize & (totalSize > headerSize + 3U) && 
          *bufferIter == 0x0a && *(bufferIter - 1) == 0x0d)
				{
					unsigned char *chk_ptr = bufferIter - totalSize;
					
					if (*chk_ptr == 0xa0)
					{
						int tmp_len = *(chk_ptr + 2);
						tmp_len = tmp_len << 8 | *(chk_ptr+3);
						if (totalSize == tmp_len + 6) 
						{
							*(bufferIter+1) = 0;
							return totalSize + 1;
						}
					}
					else
					{
						return totalSize;
					}
				}
        else if(totalSize == 2)
        {
          headerSize = *bufferIter << 8;
        }
        else if(totalSize == 3)
        {
          headerSize |= *bufferIter;
          hasSize = true;
        }
			} //if(totalSize > 0)
			++totalSize;
			if (totalSize >=  bufferSize - 1)
			{	//Check 
				*(bufferIter+1) = 0;
				break;
			}
				
			++bufferIter;
			--bytesinbuff;
		} //while(bytesinbuff)
		if(bytesinbuff==0)
		{
			return totalSize;
		}
	} //while(total < size - 1)
	return totalSize;
}

CString Utility::Base64Encode(const CString& src)  
{  
  static U08* base64 = (U08*)"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";  
  CString dstSrc = NULL;
  int n, buflen, i, j;
  CString buf = src;
  buflen = n = src.GetLength();

  //dst = (U08*)malloc(buflen / 3 * 4 + 3);
  U08* dst = (U08*)dstSrc.GetBuffer(buflen / 3 * 4 + 5);

  for(i = 0, j = 0; i <= buflen - 3; i += 3, j += 4) 
  {  
     dst[j] = (buf[i] & 0xFC) >> 2;  
     dst[j+1] = ((buf[i] & 0x03) << 4) + ((buf[i + 1] & 0xF0) >> 4);  
     dst[j+2] = ((buf[i+1] & 0x0F) << 2) + ((buf[i + 2] & 0xC0) >> 6);  
     dst[j+3] = buf[i+2] & 0x3F;  
  }  
  if(n % 3 == 1) 
  {  
     dst[j] = (buf[i] & 0xFC) >> 2;  
     dst[j + 1] = ((buf[i] & 0x03) << 4);  
     dst[j + 2] = 64;  
     dst[j + 3] = 64;  
     j += 4;  
  }  
  else if(n % 3 == 2)
  {  
     dst[j] = (buf[i] & 0xFC) >> 2;  
     dst[j + 1] = ((buf[i] & 0x03) << 4) + ((buf[i + 1] & 0xF0) >> 4);  
     dst[j + 2] = ((buf[i+1] & 0x0F) << 2);  
     dst[j + 3] = 64;  
     j += 4;  
  }  

  for(i = 0; i < j; ++i) /* map 6 bit value to base64 ASCII character */  
  {
     dst[i] = base64[(int)dst[i]];  
  }
  dst[j] = 0;  

  dstSrc.ReleaseBuffer();
  return dstSrc;  
}  