#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

bool check_vowel(char v) {
  bool output = false;
  output = (v == 'a' || v == 'A' || v == 'e' || v == 'E' || v == 'i' || v == 'I' || v == 'o' || v == 'O' || v == 'u' || v == 'U');
  return output;
}

int getDisemvowelSize(char *str) {
  int i;
  int n = 0;
  for (i = 0; i < strlen(str); i++) {
    if (!check_vowel(str[i])) {
      n++;
    }
  }
  return n;
}

char *disemvowel(char *str) {
  int length = strlen(str);
  char* final;
  int i;
  int pos = 0;
  int disemvowelSize = getDisemvowelSize(str);
  final = (char *)calloc(disemvowelSize + 1, sizeof(char));

  for (i = 0; i < length; i++) {
    if (!check_vowel(str[i])) {
      final[pos] = str[i];
      pos++;
    }

    // Add null terminator to array
    final[disemvowelSize] = '\0';
  }
  return final;
}
