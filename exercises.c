#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
  int             value;
  struct s_node   *next;
}t_node;

t_node  *create_node(int value)
{
  t_node  *new;
  new = malloc(sizeof(t_node));
  if(!new)
    return (NULL);

  new->value = value;
  new->next = NULL;

  return new;
}

void push_front(t_node **head, t_node *new)
{
  new->next = *head;
  *head = new;
}

void push_back(t_node **head, int value)
{
  t_node  *new;
  new = malloc(sizeof(t_node));
  if(!new)
    return;
  
  new->value = value;
  new->next = NULL;

  if(*head == NULL)
  {
    *head = new;
    return;
  }
  t_node *tmp;
  tmp = *head;
  while(tmp->next)
    tmp = tmp->next;

  tmp->next = new;
}

int list_size(t_node  *head)
{
  int i;
  i = 0;
  t_node *tmp;
  tmp = head;
  while(tmp)
  {
    tmp = tmp->next;
    i++;
  }

  return i;
}

t_node  *last_node(t_node *head)
{
  if(!head)
    return NULL;

  t_node *tmp;
  tmp = head;
  while(tmp->next)
    tmp = tmp->next;

  return tmp;
}

void  pop_front(t_node **head)
{
  if(!*head)
    return;

  t_node *tmp;
  tmp = (*head)->next;
  free(*head);
  (*head) = tmp;
}

void pop_back(t_node **head)
{
  if(!head || !*head)
    return;

  if((*head)->next == NULL)
  {
    free(*head);
    *head = NULL;
    return;
  }

  t_node *tmp = *head;
  while(tmp->next && tmp->next->next)
    tmp = tmp->next;
  free(tmp->next);
  tmp->next = NULL;
}

void list_clear(t_node **head)
{
  if(!head || !*head)
    return;

  t_node *tmp ;
  while(*head)
  {
    tmp = (*head)->next;
    free(*head);
    *head = tmp;
  }
}

void reverse_list(t_node  **head)
{
  if(!head || !(*head))
    return;

  t_node  *curent = *head;
  t_node  *prev = NULL;
  t_node  *next;
  while(curent)
  {
    next = curent->next;
    curent->next = prev;
    prev = curent;
    curent = next;
  }
  *head = prev;   
}

void insert_sorted(t_node **head, int value)
{
  t_node  *new = create_node(value);
  if(!new)
    return;
  
  if(!head || !(*head))
  {
    *head = new;
    new->next = NULL;
    return;
  }

  if((*head)->value >= value)
  {
    t_node  *curent = *head;
    *head = new;
    new->next = curent;
    return;
  }
  
  t_node  *tmp = *head;
  t_node  *prev = NULL;

  while(tmp->value <= value &&tmp->next)
  {
    prev = tmp;
    tmp = tmp->next;
  }
  if(tmp->next == NULL)
  {
    tmp->next = new;
    new->next = NULL;
    return;
  }
  prev->next = new;
  new->next = tmp;
}

int remove_value(t_node **head, int value)
{
  if(!head || !(*head))
    return 0;

  t_node *next = (*head)->next;

  if((*head)->value == value)
  {
    free(*head);
    *head = next;
    return 1;
  }

  t_node  *tmp = *head;
  t_node  *prev = NULL;
  while(tmp->next && tmp->value != value)
  {
    prev = tmp;
    tmp = tmp->next;
  }
  
  if(tmp->value != value)
    return 0;
  else if(tmp->value == value && tmp->next == NULL)
  {
    free(tmp);
    prev->next = NULL;
    return 1;
  }
  
  next = tmp->next;
  free(tmp);
  prev->next = next;

  return 1;
}

int has_cycle(t_node  *head)
{
  if(!head)
    return 0;

  t_node  *slow = head;
  t_node  *fast = head;
  while(fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    
    if(slow == fast)
      return 1;
  }

  return 0;
}

t_node  *find_cycle_strt(t_node *head)
{
  if(!head)
    return NULL;

  t_node  *slow = head;
  t_ndoe  *fast = head;

  while(fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
      break;
  }

  if(!fast || !fast->next)
    return NULL;

  t_node *tmp = head;
  while(tmp != slow)
  {
    slow = slow->next;
    tmp = tmp->next;
  }
  return tmp;
}

t_node   *merge_sorted(t_node *a, t_node *b)
{
  if(!a && !b)
    return NULL;
  if(!a)
    return b;
  if(!b)
    return a;


  t_node *head = NULL;
  t_node *tail = NULL;

  if(a->value == b->value)
  {
    head = tail = a;
    a = a->next;
    tail->next = b;
    tail = b;
    b = b->next;
  }
  else if(a->value < b->value)
  {
    head = tail = a;
    a = a->next;
  }
  else if(a->value > b->value)
  {
    head = tail = b;
    b = b->next;
  }

  while(a&&b)
  {
    if(a->value == b->value)
    {
      tail->next = a;
      tail = a;
      a = a->next;
      tail->next = b;
      tail = b;
      b = b->next;
    }
    else if(a->value < b->value)
    {
      tail->next = a;
      tail = a;
      a = a->next;
    }
    else if(a->value > b->value)
    {
      tail->next = b;
      tail = b;
      b = b->next;
    }
  }

  if(a == NULL)
  {
    while(b)
    {
      tail->next = b;
      tail = b;
      b = b->next;
    }
  }
  else if(b == NULL)
  {
    while(a)
    {
      tail->next = a;
      tail = a;
      a = a->next;
    }
  }
  tail->next = NULL;
  return head;

 }




int main()
{
  /*
  t_node *head = NULL;
  push_back(&head,3);
  push_back(&head,7);
  push_back(&head,13);
  push_back(&head,22);
  push_back(&head,33);


  printf("The size of the list is %d\n", list_size(head));
  printf("Value of the last node is %d\n",last_node(head)->value);

  pop_front(&head);
  t_node *tmp2 = head;
  while(tmp2)
  {
    printf("%d\n",tmp2->value);
    tmp2 = tmp2->next;
  }

  printf("\n");
  pop_back(&head);
  t_node *tmp3 = head;
  while(tmp3)
  {
    printf("%d\n", tmp3->value);
    tmp3 = tmp3->next;
  }

  printf("%d", head->value);

  
  int i = list_size(head);
  t_node  *tmp4 = head;
  while(i > 1)
  {
    tmp4 = tmp4->next;
    i--;
  }

  printf("\n%d",tmp4->value);


  push_back(&head,42);
  push_back(&head,128);

  printf("\nLinked list before insetion\t");
  
  t_node *tmp_5 = head;
  while(tmp_5)
  {
    printf("%d-->",tmp_5->value);
    tmp_5 = tmp_5->next;
  }

  
  printf("\nLinked list after insetion\t");
  insert_sorted(&head,222);
  insert_sorted(&head,0);

  remove_value(&head,222);

  t_node *tmp_6 = head;
  while(tmp_6)
  {
    printf("%d-->",tmp_6->value);
    tmp_6 = tmp_6->next;
  }


  
  printf("\n");
  reverse_list(&head);
  t_node *tmp5 = head;

  while(tmp5)
  {
    printf("%d-->", tmp5->value);
    tmp5 = tmp5->next;
  }
  printf("The size of the linked list after reverse is: %d\n", list_size(head));
  */


  return 0;
}
