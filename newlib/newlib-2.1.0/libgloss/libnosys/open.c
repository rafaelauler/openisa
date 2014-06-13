/*
 * Stub version of open.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#undef errno
extern int errno;
#include "warning.h"

// Perform a system call.
// Unused parameters should be set to 0.
static int sysCall(unsigned long func, unsigned long p1, unsigned long p2, unsigned long p3)
{
  int ret = 0;
  asm volatile ( "		\n\
          or $7, $0, %4		\n\
          or $6, $0, %3		\n\
          or $5, $0, %2		\n\
          or $4, $0, %1		\n\
          syscall 		\n\
          or %0, $0, $2" : "=r"(ret) : "r"(func), "r"(p1), "r"(p2), "r"(p3):
                 "%4", "$5",  "$6", "$7", "%2");

  return ret;
}


int
_DEFUN (_open, (file, flags, mode),
        char *file  _AND
        int   flags _AND
        int   mode)
{
  return sysCall(4005, (unsigned long)file, flags, mode);
}


