Project 1: Tokenizer
====================
This directory contains the source code for the tokenizer project. The purpose
of the tokenizer is to divide a string into tokens and maintain its
history to be recalled.

## Tokenizing a string

Complete the methods within [tokenizer.c](tokenizer.c) which include:
- space_char
- non_space_char
- word_start
- word_terminator
- count_words
- copy_str

- tokenize
- print_tokens
- free_tokens
which will allow us to tokenize, print its tokens, and free the tokens. For
- e.g. :
```
Type a phrase to tokenize: Hello world, this is a test
```
will result in the world being tokenized and displaying the following:
```
tokens[0] = Hello
tokens[1] = world,
tokens[2] = this
tokens[3] = is
tokens[4] = a
tokens[5] = test
```
## Adding to history

Once a word has been tokenized, then the code within [history.c](history.c) takes care of the following:
- Mantain word history by adding history to list.
- User is able to view by specifying what index to view.
After adding multiple items to the history such as "hello world", "this is",
"a", "test", the code should print the following:
```
-----Current history-----
hello world
this is
a
test
```
and recalling history at !1 will result in the code fetching index 1 in the
list:
```
History at [1] = this is
```
