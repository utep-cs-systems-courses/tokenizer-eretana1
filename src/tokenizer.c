#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 1;
  
  return 0;
}

int non_space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\0')
    return 0;

  return 1;
}

char *word_start(char *str)
{
  while(space_char(*str) == 1 && *str != '\0')
  {
    str++;  
  }
  return str;
}

char *word_terminator(char *word)
{
  word = word_start(word);
  while(non_space_char(*word) == 1 &&  *word != '\0')
  {
    word++;
  }
  return word - 1;
}

int count_words(char *str)
{
  int word_count;

  word_count = 1;
  str = word_start(str);
  while(*str != '\0')
  {
    if(space_char(*str) == 1)
    {
      word_count++;
    }
    str++;
  }

  return word_count;
}

char *copy_str(char *inStr, short len)
{
  char *string_copy = (char*) malloc((len + 1) * sizeof(char));
  int i;
  
  for(i = 0 ; i < len; i++)
  {
    string_copy[i] = inStr[i];
  }
  string_copy[i] = '\0';

  return string_copy;
}
