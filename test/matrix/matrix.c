/* -*- mode: c -*-
 * $Id: matrix.gcc,v 1.6 2001/03/31 15:52:48 doug Exp $
 * http://www.bagley.org/~doug/shootout/
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 30

int **mkmatrix(int rows, int cols);
void zeromatrix(int rows, int cols, int **m);
void freematrix(int rows, int **m);
int **mmult(int rows, int cols, int **m1, int **m2, int **m3);
void initialize(int **m1, int **m2);
void sum(int rows, int cols, int **m1, int **m2, int **m3);

int main(int argc, char *argv[]) {
  int i, n = 3000; 
    
  int **m1 = mkmatrix(SIZE, SIZE);
  int **m2 = mkmatrix(SIZE, SIZE);
  //initialize(m1, m2);
  int **mm = mkmatrix(SIZE, SIZE);

  for (i=0; i<n; i++) {
    mm = mmult(SIZE, SIZE, m1, m2, mm);
    //sum(SIZE, SIZE, m1, m2, mm);
  }
  printf("%d %d", mm[0][0], mm[2][3]);
  printf(" %d %d\n", mm[3][2], mm[4][4]);

  freematrix(SIZE, m1);
  freematrix(SIZE, m2);
  freematrix(SIZE, mm);
  return(0);
}

void initialize(int **m1, int **m2) {
  int  i, j, cur = 0;
  for (i = 0; i < SIZE; ++i) {
    for (j = 0; j < SIZE; ++j) {
      m1[i][j] = cur++;
      if (cur > 10)
        cur = 0;
    }
  }
  for (i = SIZE - 1; i >= 0; --i) {
    for (j = SIZE - 1; j >= 0; --j) {
      m2[i][j] = cur++;
      if (cur > 10)
        cur = 0;
    }
  }
}

int **mkmatrix(int rows, int cols) {
  int i, j, count = 0;
  int **m = (int **) malloc(rows * sizeof(int *));
  for (i=0; i<rows; i++) {
    m[i] = (int *) malloc(cols * sizeof(int));
    for (j=0; j<cols; j++) {
      m[i][j] = count++;
    }
  }
  return(m);
}

void zeromatrix(int rows, int cols, int **m) {
  int i, j;
  for (i=0; i<rows; i++)
    for (j=0; j<cols; j++)
      m[i][j] = 0;
}

void freematrix(int rows, int **m) {
  while (--rows > -1) { free(m[rows]); }
  free(m);
}

void sum(int rows, int cols, int **m1, int **m2, int **m3) {
  int i, j;
  for (i = 0; i < rows; ++i) {
    for (j = 0; j < cols; ++j) {
      m3[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

int **mmult(int rows, int cols, int **m1, int **m2, int **m3) {
  int i, j, k, val;
  for (i=0; i<rows; i++) {
    for (j=0; j<cols; j++) {
      val = 0;
      for (k=0; k<cols; k++) {
        val += m1[i][k] * m2[k][j];
      }
      m3[i][j] = val;
    }
  }
  return(m3);
}

