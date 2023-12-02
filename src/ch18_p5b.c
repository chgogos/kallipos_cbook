#include <stdio.h>

void DoSomethingWith(int *x) { printf("%d\n", *x); }

int main(void) {
  int items[] = {8, 17, 9, 42, 73, 21};
  for (size_t i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
    DoSomethingWith(&items[i]);
  }
  return 0;
}
