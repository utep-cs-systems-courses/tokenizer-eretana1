#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define STRING_SIZE 100

int main()
{
  char userinput[STRING_SIZE], word[STRING_SIZE];
  char *p, *output, **tokenizer;
  int is_space, is_non_space, word_count, exit;

  List *test_list = init_history();
  exit = word_count = 0;
  p = &word[0];

  // Echoes user input back into console
  printf("Type a word to echo back:\n");
  putchar('>');
  fgets(userinput, 100, stdin);
  printf("%s\n", userinput);

  // User input for given phrase
  while(exit == 0)
  {
    printf("---------------------\nType word to tokenize, ![desired id number] to" 
	   " view a specific existing word, or e to exit:\n");
    fgets(word, STRING_SIZE, stdin);

    // Exit program
    if(word[0] == 'e' || word[0] == 'E')
    {
      printf("Exiting program...\n");
      exit = 1;
      break;
    }
    else if(word[0] == '!')
    {
      int index = word[1] - '0';
      printf("History at [%c]: %s\n", word[1], get_history(test_list, index));
    }
    else
    {
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

      // Add word history to list
      add_history(test_list, word);

      // Print current token history
      printf("\n------Current token history-----\n");
      print_history(test_list);
    
      // Free previously allocated tokens
      free_tokens(tokenizer);
    } // end of else
  } // end of user input while loop

  free_history(test_list);
  return 0;
}
