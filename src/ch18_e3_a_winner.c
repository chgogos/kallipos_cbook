/*
 * https://www.unix-ag.uni-kl.de/~conrad/shocc/results.html
 */
#include <stdio.h>
#include <stdlib.h>

void o(int n) { printf("%d ", n); }

int main(a, v)
int *v;
{
  for (a = atoi(*++v); o(a), *v = atoi(v[1]) - a; a += *v >> 31 | 1)
    ;
}