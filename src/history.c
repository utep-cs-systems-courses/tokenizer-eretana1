#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history()
{
  List* initial_list = (List*) malloc(sizeof(List));
  return initial_list;
}

void add_history(List *list, char *str)
{
  Item *new_data = (Item*) malloc(sizeof(Item));
  Item *temp = list->root;
  int item_id = 0;

  // Find length of str
  int str_len = 0;
  while(str[str_len] != '\0')
    str_len++;

  // Set Item node string to contain new string copy
  new_data->str = copy_str(str, str_len);
  new_data->next = NULL;

  if(temp == NULL)
  {
    new_data->id = item_id;
    list->root = new_data;
    return;
  }
  
  while(temp->next != NULL)
  {
    item_id++;
    temp = temp->next;
  }
  
  item_id++;
  new_data->id = item_id;
  temp->next = new_data;
}

char *get_history(List *list, int id)
{
  if(id < 0){
    printf("Invalid ID. Please try again.");
    return "ERROR: Invalid ID.";
  }
  
  Item *temp = list->root;
  while(temp != NULL)
  {
    if(temp->id == id)
    {
      return temp->str;
    }
    temp = temp->next;
  }
  return "ERROR: Invalid ID.";
}

void print_history(List *list)
{
  Item *temp = list->root;
  for(int i = 0 ; temp != NULL; i++)
  {
    printf("%s", temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{  
  Item *prev = list->root;
  while(list->root != NULL)
  {
    list->root = list->root->next;
    free(prev->str); free(prev);
    prev = list->root;
  }
  free(list);
}
