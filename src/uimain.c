#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define STRING_SIZE 100

int main()
{
  char userinput[STRING_SIZE], word[STRING_SIZE];
  char *p, *output, **tokenizer;
  int is_space, is_non_space, word_count;

  word_count = 0;
  p = &word[0];

  // Echoes user input back into console
  printf("Type a word to echo back:\n");
  putchar('>');
  fgets(userinput, 100, stdin);
  printf("%s\n", userinput);

  // User input for given phrase
  printf("---------------------\nType word to use: ");
  fgets(word, STRING_SIZE, stdin);
  
  // Check if tab is space char
  is_space = space_char('\t');
  printf("Space_char: ' ' == %d\n", is_space);

  // Check if tab is non-space char
  is_non_space = non_space_char('\t');
  printf("Non_space_char: ' ' == %d\n", is_non_space);

  printf("\nGiven phrase: %s", word);

  // Find the start of the word in given phrase
  output = word_start(p);
  printf("Start of word: %c\n", *output);

  // Find the end of the word in given phrase
  output = word_terminator(p);
  printf("End of Word: %c\n", *output);

  // Return number of words contained in given phrase
  word_count = count_words(p);
  printf("Number of words: %d\n", word_count);

  // Return a copy of word from (0,len) given len.
  output = copy_str(p, 4);
  printf("New word copy: %s\n", output);

  // Tokenize a given phrase
  tokenizer = tokenize(p);

  // Print all tokens
  printf("\n------Printing tokens------\n");
  print_tokens(tokenizer);

  // Free previously allocated tokens
  free_tokens(tokenizer);
  
  return 0;
}
