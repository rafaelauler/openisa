#include <stdio.h>

#define IM 139968
#define IA   3877
#define IC  29573

#include <math.h>
#include <stdlib.h>
#define PI 3.1415

float gen_random(float max);
void heapsort(int n, double *ra);
void SolveCubic(double  a,
                double  b,
                double  c,
                double  d,
                int    *solutions,
                double *x);

/*
int main(int argc, char **argv)
{
      double  a1 = 1.0, b1 = -10.5, c1 = 32.0, d1 = -30.0;
      double  a2 = 1.0, b2 = -4.5, c2 = 17.0, d2 = -30.0;
      double  x[3];
      double  X;
      int     solutions, i;
      
      SolveCubic(a1, b1, c1, d1, &solutions, x);
      printf("Sol %d: %lf\n",1, x[0]);
      printf("Sol %d: %lf\n",2, x[1]);
      printf("Sol %d: %lf\n",3, x[2]);

      // should get 3 solutions: 2, 6 & 2.5   

      SolveCubic(a2, b2, c2, d2, &solutions, x);
      printf("Sol %d: %lf\n",1, x[0]);

      for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 180)) {
        printf("%d %.12lf radians = \n", 0, X);
      }

      // should get 1 solution: 2.5           
      //      printf("%lf\n", x[0]);
      
      return 0;
}

void SolveCubic(double  a,
                double  b,
                double  c,
                double  d,
                int    *solutions,
                double *x)
{
  printf("%d a=%lf\n", 0, a);
  printf("%d b=%lf\n", 0, b);
  printf("%d c=%lf\n", 0, c);
  printf("%d d=%lf\n", 0, d);
      double    a1 = b/a, a2 = c/a, a3 = d/a;
      double    Q = (a1*a1 - 3.0*a2)/9.0;
      printf("%d %lf\n",0, Q);
      double R = (2.0*a1*a1*a1 - 9.0*a1*a2 + 27.0*a3)/54.0;
      double    R2_Q3 = R*R - Q*Q*Q;

      
      double    theta;

      if (R2_Q3 <= 0)
      {
            *solutions = 3;
            theta = acos(R/sqrt(Q*Q*Q));
            x[0] = -2.0*sqrt(Q)*cos(theta/3.0) - a1/3.0;
            x[1] = -2.0*sqrt(Q)*cos((theta+2.0*PI)/3.0) - a1/3.0;
            x[2] = -2.0*sqrt(Q)*cos((theta+4.0*PI)/3.0) - a1/3.0;
      }
      else
      {
            *solutions = 1;
            x[0] = pow(sqrt(R2_Q3)+fabs(R), 1/3.0);
            x[0] += Q/x[0];
            x[0] *= (R < 0.0) ? 1 : -1;
            x[0] -= a1/3.0;
      }
      
}
*/

/*

int
main() {
  double a, b, c, d;   
  printf("Type a.\n");
  scanf("%lf", &a);
  printf("Type b.\n");
  scanf("%lf", &b);
  printf("Type c.\n");
  scanf("%lf", &c);
  printf("Type d.\n");
  scanf("%lf", &d);
  double    a1 = b/a, a2 = c/a, a3 = d/a;
  double    Q = (a1*a1 - 3.0*a2)/9.0;
  printf("%d\n%lf\n", 0, Q);
}
*/

/*
int
main() {
  float a, b, c, d;   
  printf("Type a.\n");
  scanf("%f", &a);
  printf("Type b.\n");
  scanf("%f", &b);
  printf("Type c.\n");
  scanf("%f", &c);
  printf("Type d.\n");
  scanf("%f", &d);
  float    a1 = b/a, a2 = c/a, a3 = d/a;
  float    Q = (a1*a1 - 3.0*a2)/9.0;
  printf("%d\n%f\n", 0, Q);
}
*/


/*
int main() {
  double d;
  int num;
  scanf("%lf", &d);
  scanf("%d", &num);
  printf("%d %lf\n",num, d);
}
*/

/*
int main() {
  float f;
  int num;
  scanf("%f", &f);
  scanf("%d", &num);
  printf("%d %f\n",num, f);
}
*/


int main() {
    printf("%d %f\n", 0,     gen_random(1.0f));
    printf("%d %f\n", 0,     gen_random(1.0f));
    printf("%d %f\n", 0,     gen_random(1.0f));
    printf("%d %f\n", 0,     gen_random(1.0f));
}



float
gen_random(float max) {
  static long last = 42;
  return( max * (last = (last * IA + IC) % IM) / IM );
}




