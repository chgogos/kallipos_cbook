#include <math.h>
#include <stdio.h>
#define N 10000

int sum_factors(int x) {
  int sum = 0;
  int min_factor = 0;
  int max_factor = x - 1;
  for (int i = 1; i <= sqrt(x) + 1; i++) {
    if (x % i == 0) {
      if (i > min_factor && i < max_factor) {
        min_factor = i;
        sum += i;
      }
      if (x / i > min_factor && x / i < max_factor) {
        max_factor = x / i;
        sum += x / i;
      }
    }
  }
  return sum;
}

int main(void) {
  for (int num1 = 1; num1 <= N; num1++) {
    int sum1 = sum_factors(num1);
    for (int num2 = num1 + 1; num2 <= N; num2++) {
      int sum2 = sum_factors(num2);
      if (sum1 == num2 && sum2 == num1) {
        printf("%d and %d are friends!\n", num1, num2);
      }
    }
  }
  return 0;
}
