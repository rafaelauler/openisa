/* -*- mode: c -*-
 * $Id: ackermann.gcc,v 1.5 2001/05/04 01:21:38 doug Exp $
 * http://www.bagley.org/~doug/shootout/
 */

#include <stdio.h>
#include <stdlib.h>

int Ack(int M, int N);

int
main(int argc, char *argv[]) {
  int n = 12;

  printf("Ack(3,%d): %d\n", n, Ack(3, n));
  return(0);
}

int 
Ack(int M, int N) {
  if (M == 0) return( N + 1 );
  if (N == 0) return( Ack(M - 1, 1) );
  return( Ack(M - 1, Ack(M, (N - 1))) );
}

