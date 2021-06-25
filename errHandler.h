#ifndef __ERR_HANDL_H_
#define __ERR_HANDL_H_ 1
#include "exception.h"
#include <stddef.h>

#define error() __errorA(__LINE__, __FILE__, __FUNCTION__)
#define errorA error

#ifdef WIN32 /* Windows errno has a type called errno_t */
void __errorB(size_t l, const char* f, const char* fn, errno_t er);
#else /* WIN32 */
#ifndef NTR_NO_ERRNO
#include <errno.h>
#define errorB() __errorB(__LINE__, __FILE__, __FUNCTION__, errno)
void __errorB(size_t l, const char* f, const char* fn, int er);
#endif /* NTR_NO_ERRNO */
#endif /* WIN32 else */

#endif