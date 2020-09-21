#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

bool check_vowel(char *str)
{
  char *v;
  if (v == 'a' || v == 'A' || v == 'e' || v == 'E' || v == 'i' || v == 'i' || v == 'o' || v == 'O' || v == 'u' || v == 'U')
  {
    return true;
  }
  else
  {
    return false;
  }
}

int getNewString(char *str, int length)
{
  int n = 0;
  int i;
  for (i = 0; i < length; i++)
  {
    if (check_vowel(str[i]) == false)
    {
      n++;
    }
  }
}

char *disemvowel(char *str)
{
  int length = strlen(str);
  char *final;
  int i;
  int pos;
  int newString = getNewString(str, length);
  final = (char *)calloc(newString + 1, sizeof(char));

  for (i = 0; i < length; i++)
  {
    if (check_vowel(str[i]) == false)
    {
      final[pos] == str[i];
      pos++;
    }

    // Add null to array as required
    final[newString] = '\0';

    return final;
  }
}