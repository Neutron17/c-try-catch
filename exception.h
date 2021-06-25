/* exception.h
 * 
 * 
 */

#ifndef _NTR_EXCEPTION_H_
#define _NTR_EXCEPTION_H_ 1

#if NTR_EXC_NO_DEFAULT != 1

#include <setjmp.h>
#define try do { jmp_buf ex_buff__; int __NtrY = setjmp(ex_buff__); if(__NtrY == 0) 
#define catch(x) else if((__NtrY % x) == 0) 
#define throw(exception) longjmp(ex_buff__, exception);
#define entry }while(0)
#define	Exception 1
#define IOException 2
#define FileNotFoundException 4
#define NoSuchFileOrDirectory 4
#define DirectoryNotFound 8
#define NullPointerException 3
#define Nothing 17
#endif

#if NTR_EXC_NO_GOTO != 1

#define gotoExc E1
#define gotoThrow(exc) goto exc
#define gotoCatch(exc) exc
#define gotoEntry end:

#endif
#endif