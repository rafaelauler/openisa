#include <stdio.h>

float saturatef(float myfloat) {
  if (myfloat < 0.0f) myfloat = 0.0f;
  if (myfloat > 100.0f) myfloat = 100.0f;
  return myfloat;
}

double saturate(double mydouble) {
  if (mydouble < 0.0) mydouble = 0.0;
  if (mydouble > 100.0) mydouble = 100.0;
  return mydouble;
}

int
main() {
  float myfloat;
  double mydouble;
  scanf("%f", &myfloat);
  scanf("%lf", &mydouble);

  printf("saturation of float = %d %f\n", 0, saturatef(myfloat));
  printf("saturation of double = %d %lf\n", 0, saturate(mydouble));
}
