#include "push_swap.h"

static void init_loop_atoi(char *src, int  *error_flag, int *sign)
{
  if (!src || !error_flag)
      return;

  while (*src == ' ' || *src == '\n' || *src == '\t' || 
         *src == '\r' || *src == '\v' || *src == '\f')
      src++;

  if (*src == '+' || *src == '-')
  {
    if (*src == '-')
      *sign = -1;
    src++;
  }

  if (*src < '0' || *src > '9')
  {
    *error_flag = 1;
    return;
  }

}


long og_atoi(char *src, int *error_flag)
{
  long num = 0;
  int sign = 1;

  init_loop_atoi(src,error_flag,&sign);
  while (*src != '\0')
  {
      if (*src < '0' || *src > '9')
      {
        *error_flag = 1;
        return (0);
      }
      num = num * 10 + (*src - '0');

      if ((sign == 1 && num > 2147483647) || (sign == -1 && (-num) < -2147483648))
      {
        *error_flag = 1;
        return (0);
      }
     src++;
  }

  return (num * (long)sign);
}

int main(int argc, char **argv)
{
  int error_status = 0;
  long parsed_value;
  int i = 1;

  if (argc < 2)
      return (0);

  while (i < argc)
  {
    parsed_value = og_atoi(argv[i], &error_status);
        
    if (error_status == 1)
    {
      write(2, "Error\n", 6);
      // Free any allocated memory here before exiting
      return (1); 
    }
    // Proceed to check for duplicates and add parsed_value to your stack
    i++;
  }
  return (0);
}


