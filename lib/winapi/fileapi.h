#ifndef __FILEAPI_H__
#define __FILEAPI_H__

#include <windef.h>
#include <winbase.h>

#ifdef __cplusplus
extern "C"
{
#endif

HANDLE FindFirstFileA (LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
BOOL FindNextFileA (HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
BOOL FindClose (HANDLE hFindFile);

#ifndef UNICODE
#define FindFirstFile FindFirstFileA
#define FindNextFile FindNextFileA
#else
#error nxdk does not support the Unicode API
#endif

#ifdef __cplusplus
}
#endif

#endif
