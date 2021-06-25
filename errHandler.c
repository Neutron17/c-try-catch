#define _CRT_SECURE_NO_WARNINGS 1
#include "errHandler.h"
#include <stdio.h>

void __errorA(size_t l, const char* f, const char* fn) {
	fprintf(stderr, "ntr: Error in file: %s\n\tin function: %s\n\tat line: %ld\n", f, fn, l);
	fflush(stderr);
}

#ifndef NTR_NO_ERRNO
#include <string.h>
#ifdef WIN32
void __errorB(size_t l, const char* f, const char* fn, errno_t er) {
	__errorA(l, f, fn);
	fprintf_s(stderr, "\terrno: %s\n", strerror(er));
}
#else
void __errorB(size_t l, const char* f, const char* fn, int er) {
	__errorA(l, f, fn);
	fprintf(stderr, "\terrno: %s\n", strerror(er));
}
#endif
#endif
