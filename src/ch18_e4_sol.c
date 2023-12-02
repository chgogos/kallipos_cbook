#include <stdio.h>
#include <string.h>

int main(void) {
  char *names[] = {"Mr. Chris", "Ms. Ada", "Alex",
                   "Mr. John",  "Anna",    "Ms. Sofia"};
  for (size_t i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
    const char *t = strncmp(names[i], "Mr. ", 4) ? names[i] : names[i] + 4;
    const char *t2 = strncmp(t, "Ms. ", 4) ? t : t + 4;
    printf("%s\n", t2);
  }
  return 0;
}