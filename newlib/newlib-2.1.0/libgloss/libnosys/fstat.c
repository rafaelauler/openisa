/*
 * Stub version of fstat.
 */

#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#undef errno
extern int errno;
#include "warning.h"

// Perform a system call.
// Unused parameters should be set to 0.
static int sysCall(unsigned long func, unsigned long p1, unsigned long p2)
{
  int ret = 0;
  asm volatile ( "		\n\
          or $6, $0, %3		\n\
          or $5, $0, %2		\n\
          or $4, $0, %1		\n\
          syscall 		\n\
          or %0, $0, $2" : "=r"(ret) : "r"(func), "r"(p1), "r"(p2): 
                 "%4", "$5",  "$6", "%2");
  return ret;
}


int
_DEFUN (_fstat, (fildes, st),
        int          fildes _AND
        struct stat *st)
{
  return sysCall(4108, fildes, (unsigned long)st);
}

