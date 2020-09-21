#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString)
{
  char *final = disemvowel((char *)"");
  ASSERT_STREQ("", final);
  free(final);
}

TEST(Disemvowel, HandleNoVowels)
{
  char *final = disemvowel((char *)"pqrst");
  ASSERT_STREQ("pqrst", final);
  free(final);
}

TEST(Disemvowel, HandleOnlyVowels)
{
  char *final = disemvowel((char *)"aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", final);
  free(final);
}

TEST(Disemvowel, HandleMorrisMinnesota)
{
  char *final = disemvowel((char *)"Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst",
               disemvowel(final));
  free(final);
}

TEST(Disemvowel, HandlePunctuation)
{
  char *final = disemvowel((char *)"An (Unexplained) Elephant!");

  ASSERT_STREQ("n (nxplnd) lphnt!",
               final);
               free(final);
}

TEST(Disemvowel, HandleLongString)
{
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char *)calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size - 1; ++i)
  {
    str[i] = 'a';
  }
  str[size - 1] = '\0';

  char *final = disemvowel(str);
  ASSERT_STREQ("xyz", final);

  free(str);
  free(final);
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
