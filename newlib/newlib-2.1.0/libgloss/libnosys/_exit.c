/* Stub version of _exit.  */

#include <limits.h>
#include "config.h"
#include <_ansi.h>
#include <_syslist.h>

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


_VOID
_DEFUN (_exit, (rc),
	int rc)
{
  sysCall(4001, rc);

  /* Convince GCC that this function never returns.  */
  for (;;)
    ;
}
