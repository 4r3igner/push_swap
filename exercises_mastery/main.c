#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Buffer
{
  int num;
}Buffer;

typedef struct numStack
{
  int   num;
  struct numStack  *next;
  struct numStack  *prev;
} numStack;

void newNode(Buffer data)
{
  
  numStack *node;
  node = malloc(sizeof(numStack));
  

  node->num = data.num;
}

int main(int argc,char  **argv)
{
  int i;
  i = 1;
  i = argc;
  if (argc > i)
    while(i <= argc)
    {
      Buffer buff = argv[i];
      numStack = newNode(buff);
      printf("%d", numStack->num);
      i++;
    }
  return 0;
}
