#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double pick(double a, double b) { return a + drand48() * (b - a); }

int main(void) {
  srand48(time(NULL));
  printf("%.2f\n", pick(10, 20));
  return 0;
}
