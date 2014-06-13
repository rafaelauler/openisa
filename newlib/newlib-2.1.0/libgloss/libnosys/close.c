/*
 * Stub version of close.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#undef errno
extern int errno;
#include "warning.h"

static int sysCall(unsigned long func, unsigned long p1)
{
  int ret = 0;
  asm volatile ( "		\n\
          or $5, $0, %2		\n\
          or $4, $0, %1		\n\
          syscall 		\n\
          or %0, $0, $2" : "=r"(ret) : "r"(func), "r"(p1):
                 "%4", "$5", "%2");


  return ret;
}



int
_DEFUN (_close, (fildes),
        int fildes)
{
  return sysCall(4006, fildes);
}


