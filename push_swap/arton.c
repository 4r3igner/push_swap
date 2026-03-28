#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void  artons(char *src, int *arr)
{
  int pos;
  pos = 0;
  int num;
  int sign;
  sign = 0;
  while(*src!='\0')
  {
    while(*src=='\n' || *src=='\t' || *src=='\v' ||
          *src=='\f' || *src==' ')
      src++;
    if (*src >= '0' && *src<='9')
    {
      num = 0;
      
      while(*src >= '0' && *src <= '9')
      {
        num = num*10 + (*src-48);
        src++;
      }
      arr[pos] = num;
      pos++;
    }
    else if(*src=='\0')
      break;
  }
  return;
}

int checkncount(char  *src)
{
  int count;
  count = 0;
  int sign;
  while(*src!='\0')
  {
    while(*src=='\n' || *src=='\t' || *src=='\v' ||
          *src=='\f' || *src==' ')
      src++;
    if (*src >= '0' && *src<='9')
    {
      while(*src >= '0' && *src <= '9')
      {
        if(*arc == '-');
          sign++;
        src++;
      }
      count++;
    }
    else if(*src == '\0')
      break;
    else 
      return 0;
  }
  return count;
}

int main(int argc, char **argv)
{
  if (argc==1)
    printf("Introdu ceva ma anecdot\n");
  else if(argc==2)
  {
    printf("Initializing: 'checkncount'\n");
    int size =checkncount(argv[1]);
    printf("%d\n",size);
    if (size > 0)
    {
      int *arr;
      arr = malloc(sizeof(int) * size);
      if(!arr)
        return 0;
      artons(argv[1],arr);
      while(size > 0)
      {
        printf("%d,  ",*arr);
        arr++;
        size--;
      }
    }
  }
}
