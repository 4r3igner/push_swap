#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct double_list
{
  int                 value;
  struct double_list  *next;
  struct double_list  *prev;
}d_list;

d_list    *create_node(int value)
{
  d_list  *new;
  new = malloc(sizeof(d_list));
  if(!new)
    return NULL;

  new->value = value;
  new->next = NULL;
  new->prev = NULL;

  return new;
}

void  append_node(d_list **head, int value)
{
  if(!head)
    return;
  
  d_list *new_node = create_node(value);
  if(!new_node)
    return;

  if (*head == NULL)
  {
    *head = new_node;
    return;
  }

  d_list  *tmp = *head;
  while(tmp->next)
    tmp = tmp->next;

  tmp->next = new_node;
  new_node->prev = tmp;

  return;
}

void delete_node(d_list **head, int target_value)
{
  if(!head || !(*head))
    return;

  d_list  *tmp = *head;
  while(tmp->next && tmp)
  {
    if(tmp->value == target_value)
    {
      if(tmp->prev == NULL)
      {
        
      }
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
      free(tmp);
      return;
    }
    tmp = tmp->next;
  }
  
  return;
}

int main()
{
  d_list *head = NULL;

  d_list *node1 = create_node(13); 
  printf("%d",node1->value);

  append_node(&head, 22);
  append_node(&head, 32);
  append_node(&head, 42);
  append_node(&head, 52);

  delete_node(&head,22);
  delete_node(&head,52);
  d_list *tmp = head;
  while(tmp)
  {
    printf("%d",tmp->value);
    tmp = tmp->next;
  }
  
}
