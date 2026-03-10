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
  while(tmp)
  {
    if(tmp->value == target_value)
    {
      if(tmp == *head)
        *head = tmp->next;
      if(tmp->next!=NULL)
        tmp->next->prev = tmp->prev;
      if(tmp->prev != NULL)
        tmp->prev->next = tmp->next;

      free(tmp);
      return;
    }
    tmp = tmp->next;
  }
}

void  reverse_list(d_list  **head)
{
  if(!head || !(*head))
    return;

  d_list  *tmp = *head;;
  d_list  *prev_tmp = NULL;

  while(tmp)
  {
    prev_tmp = tmp->prev;
    tmp->prev = tmp->next;
    tmp->next = prev_tmp;
    tmp = tmp->prev;
  }

  *head = prev_tmp->prev;

}

void insert_sorted(d_list  **head,int value)
{
  if(!head)
    return;


  d_list *new_node = create_node(value);
  if(!new_node)
    return;

  if(!(*head))
  {
    *head = new_node;
    return;
  }

  d_list    *tmp = *head;


  if(tmp->value >= value)
  {
    tmp->prev = new_node;
    new_node->next = *head;
    *head = new_node;
    return;
  }

  while(tmp->value <= value && tmp->next!=NULL)
    tmp = tmp->next;

  if(tmp->next == NULL && tmp->value < value)
  {
    tmp->next = new_node;
    new_node->prev = tmp;
    return;
  }
  
  new_node->next = tmp;
  new_node->prev = tmp->prev;
  new_node->prev->next = new_node;
  new_node->next->prev = new_node;
  return;
}

void  make_circular(d_list  **head)
{
 if(!head || !(*head))
    return;
  
  d_list  *end = *head;

  while(end->next != NULL)
    end = end->next;

  (*head)->prev = end;
  end->next = *head;

  return;
}

void  append_circular(d_list  **head, int value)
{
  if(!head)
    return;

  d_list  *new_node;
  new_node = create_node(value);

  if(!new_node)
    return;

  if(!(*head))
  {
    *head = new_node;
    (*head)->next = (*head)->prev = *head;
    return;
  }

  d_list  *tail = (*head)->prev;
  new_node->next = *head;
  new_node->prev = tail;
  (*head)->prev = new_node;
  tail->next = new_node;

  return;
}

void delete_circular_head(d_list    **head)
{
  if(!head || !(*head))
    return;

  if((*head)->next == *head)
  {
    free(*head);
    *head = NULL;
    return;
  }

  d_list *tail = (*head)->prev;
  d_list *current_head = *head;

  (*head)->next->prev = tail;
  tail->next = (*head)->next;
  *head = (*head)->next;
  free(current_head);

  return;
}

void  delete_value_circular(d_list   **head, int target_value)
{
  if(!head || !(*head))
    return;

  if((*head)->value == target_value )
  {
    delete_circular_head(head);
    return;
  }

  d_list  *curent = *head;
  while(curent->next != *head && curent->value != target_value)
    curent = curent->next;

  if(curent = *head)
    return;
  
  curent->next->prev = curent->prev;
  curent->prev->next = curent->next;
  free(curent);

  return;  
}

int cycle_list_count(d_list   *head)
{
  if(!head)
    return 0;

  int size = 1;
  d_list  *tmp = head->next;
  while(tmp != head)
  {
    tmp = tmp->next;
    size ++;
  }

  return size;
}

d_list  *return_index (d_list *head, int index)
{
  if(!head)
    return NULL;

  int i = 1;
  d_list *tmp = head;
  while(i != index)
  {
    tmp = tmp->next;
    i++;
  }

  return tmp;
}

void split_circular(d_list  **head, int index, d_list  **second_list)
{
  if(!head || !(*head) || !second_list)
    return;

  int size = cycle_list_count(head);
  if(index >= size - 1 || index < 0)
    return;

  d_list  *list1_tail = return_index(head, index);
  d_list  *list2_head = list1_tail->next;
  d_list  *list2_tail = (*head)->prev;

  list1_tail->next = *head;
  (*head)->prev = list1_tail;

  list2_head->prev = list2_tail;
  list2_tail->next = list2_head;

  *second_list = list2_head;

  return;
}


int main()
{
  d_list *head = NULL;
  insert_sorted(&head,10);
  insert_sorted(&head,30);
  insert_sorted(&head, 20);
  insert_sorted(&head,33);
  insert_sorted(&head,10);
  insert_sorted(&head,33);

  d_list  *tmp = head;
  while(tmp)
  {
    printf("%d-->",tmp->value);
    tmp = tmp->next;
  }
  printf("NULL");

  return 0;
}
