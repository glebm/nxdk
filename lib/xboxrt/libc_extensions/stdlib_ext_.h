// SPDX-License-Identifier: MIT

// SPDX-FileCopyrightText: 2019-2021 Stefan Schmidt
// SPDX-FileCopyrightText: 2020 Jannik Vogel

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _CRT_RAND_S
int rand_s (unsigned int *randomValue);
#endif

// Win32 extension for reversing byte order
unsigned short _byteswap_ushort (unsigned short val);
unsigned long _byteswap_ulong (unsigned long val);
unsigned __int64 _byteswap_uint64 (unsigned __int64 val);

typedef void (__cdecl *_purecall_handler)(void);

_purecall_handler __cdecl _get_purecall_handler (void);
_purecall_handler __cdecl _set_purecall_handler (_purecall_handler function);

// Win32 extension providing the highest valid errno number
// https://docs.microsoft.com/en-us/cpp/c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr?view=vs-2019
#define _sys_nerr _PDCLIB_ERRNO_MAX

// Necessary stub for libc++
#include <wchar.h>
int mbtowc (wchar_t *pwc, const char *string, size_t n);

// Defined as on ReactOS - may need further adjustment if we decide to do locales properly
#define MB_CUR_MAX 2

// Microsoft extension (evaluation of arguments twice is intended)
#define __min(a,b) (((a) < (b)) ? (a) : (b))
#define __max(a,b) (((a) > (b)) ? (a) : (b))

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
#if (__cplusplus < 201103L)
#define _NXDK_NOEXCEPT throw()
#else
#define _NXDK_NOEXCEPT noexcept
#endif

// libc++ expects MSVCRT to provide these overloads

inline static long abs (long __x) _NXDK_NOEXCEPT
{
    return labs(__x);
}

inline static long long abs (long long __x) _NXDK_NOEXCEPT
{
    return llabs(__x);
}

inline static ldiv_t div (long __x, long __y) _NXDK_NOEXCEPT
{
    return ldiv(__x, __y);
}

inline static lldiv_t div (long long __x, long long __y) _NXDK_NOEXCEPT
{
    return lldiv(__x, __y);
}

#undef _NXDK_NOEXCEPT

#endif

static void *_aligned_malloc (size_t size, size_t alignment)
{
    return aligned_alloc(alignment, size);
}

static void _aligned_free (void *memblock)
{
    free(memblock);
}
