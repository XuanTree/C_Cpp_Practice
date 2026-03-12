#include <stdio.h>
#include <string.h>
#define N 100
char *connectTwoStrings(char *s1, char *s2) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  for (int i = len1 - 1; i < len1 + len2; i++) {
    s1[i + 1] = s2[i - len1 + 1];
  }
  return s1;
}
int main() {
  char s1[N], s2[N];
  printf("Enter the first string:");
  gets_s(s1, N);
  printf("Enter the second string:");
  gets_s(s2, N);
  char *result = connectTwoStrings(s1, s2);
  printf("The connected string is: %s", result);
  strlen(s1);
  return 0;
}
