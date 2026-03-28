#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

///------------------------------------------------------------///
///                       HANDLERs
///-----------------------------------------------------------///

void error_handler()
{
  write(2,"Error\n",6);
  exit(0);
}


int check_sign_format (char **src)
{
  int sign;
  sign = 1;
  if(**src == '+' || **src == '-')
  {
    if(**src=='-')
      sign = -1;
    (*src)++;
    if(!(**src <= '9' && **src >= '0'))
      error_handler();
  }
  return sign;
}





//------------------------------------------------------------- 
struct linked_l;

typedef struct bst
{
  int             root;
  int             index; 
  struct linked_l *ref2dll;
  struct bst      *left;
  struct  bst     *right;
}t_binary;

typedef struct linked_l
{
  int             num;
  int             index;
  struct linked_l *next;
  struct linked_l *prev;
}dll;

//-------------------------------------------------------------

dll *find_node(int num,dll *head)
{

  if(head->num == num)
    return head;

  dll *tmp;
  tmp = head->next;

  while(tmp->num != num)
    tmp = tmp->next;

  return tmp;
}


//------------------------------------------------------------ 


void  artons(char *src, int *arr, int *global_p)
{
  float num;
  int sign;
  sign = 0;
  while(*src!='\0')
  {
    while(*src==' ' || (*src>=9 && *src<=13))
      src++;
    if(*src=='\0')
      break;

    sign = check_sign_format(&src);

    if (*src >= '0' && *src<='9')
    {
      num = 0;
      while(*src >= '0' && *src <= '9')
      {
        num = num*10 + (*src-48);
        src++;
      }
      arr[*global_p] = num * (float)sign;
      (*global_p)++;
    }
    else
      error_handler();
  }
  return;
}

int checkncount(char  *src)
{
  int count;
  count = 0;
  
  while(*src!='\0')
  {
    while(*src==' ' || (*src>=9 && *src<=13))
      src++;
    if(*src=='\0')
      break;

    if(*src== '-' || *src == '+')
      src++;
    if (*src >= '0' && *src<='9')
    {
      while(*src >= '0' && *src <= '9')
      {
        src++;
        if(*src=='-' || *src=='+')
        {
          write(2,"err\n",4);
          exit(0);
        }
      }
      count++;
    }
    else 
      error_handler();
  }
  return count;
}

void  sort_bst(t_binary *root, int  *arr,int *index)
{
  if(!root)
    return;

  
  sort_bst(root->left,arr, index,divider);
  if(root->root < 0)
    root->ref2dll->index = index;
  else
    root->ref2dll->index += index;

  (*index)++;  
  sort_bst(root->right,arr,index,divider);
}

t_binary  *create_bst(int num,dll *head)
{
  t_binary  *new_node;
  new_node = malloc(sizeof(t_binary) * 1);
  if(!new_node)
    return NULL;

  new_node->ref2dll = find_node(num,head);
  new_node->root = num;
  new_node->index = 0;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

t_binary  *insert_bst(int num,t_binary *root,int index)
{
  if(!root)
    return create_bst(num,index);


  if(num == root->root)
    error_handler();
  else if(num < root->root)
    root->left = insert_bst(num,root->left,index);
  else if(num > root->root)
    root->right = insert_bst(num,root->right,index); 
  return root;
}

void indexation_bst(int *arr, int size)
{
  int i;
  i = 1;
  t_binary  *head;
  head = create_bst(arr[0],0);

  while(i<size)
  {
    insert_bst(arr[i],head,i);
    i++;
  }
  int index;
  index = 0;
  sort_bst(head,&arr[0],&index);

  printf("\n");
  i = 0;
  while(i < size)
  {
    printf("%d ",arr[i]);
    i++;
  }
  //printf("\n");
  return;
}

void  init(int argc, char **argv)
{
  int size;
  int i;
  i = 1;
  size = 0;
  while(i<argc)
  {
    size += checkncount(argv[i]);
    i++;
  }
  if(size == 0 || size == 1)
    return;
  int *arr;
  arr = malloc(sizeof(int) * size);
  if(!arr)
    return ;
  i = 1;
  int global_p;
  global_p = 0;
  while(i<argc)
  {
    artons(argv[i],arr,&global_p);
    i++;
  }
 
  i = 0;
  while(i<size)
  {
    printf("%d ",arr[i]);
    i++;
  }

  indexation_bst(arr,size);
  return;
}

int main(int argc, char **argv)
{
  if(argc == 1)
    printf("Introdu ceva amigos\n");
  else
    init(argc,argv);
  
  return 0;
}
