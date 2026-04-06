#include "push_swap.h"

#include "push_swap.h"

static int check_sign_format(char **src)
{
	int sign;

	sign = 1;
	if (**src == '+' || **src == '-')
	{
		if (**src == '-')
			sign = -1;
		(*src)++;
	}
	if (!(**src <= '9' && **src >= '0'))
		error_handler();
	return (sign);
}

static void arton_loop(char **src, int *arr, int *global_p)
{
	long long	num;
	int			sign;

	num = 0;
	sign = check_sign_format(src);
	while (**src >= '0' && **src <= '9')
	{
		num = num * 10 + (**src - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			error_handler();
		(*src)++;
	}
	arr[*global_p] = (int)(num * sign);
	(*global_p)++;
}

void artons(char *src, int *arr, int *global_p)
{
	while (*src != '\0')
	{
		while (*src == ' ' || (*src >= 9 && *src <= 13))
			src++;
		if (*src == '\0')
			break ;
		arton_loop(&src, arr, global_p);
	}
}

int checkncount(char *src)
{
	int count;

	count = 0;
	while (*src != '\0')
	{
		while (*src == ' ' || (*src >= 9 && *src <= 13))
			src++;
		if (*src == '\0')
			break ;
		if (*src == '-' || *src == '+')
			src++;
		if (*src >= '0' && *src <= '9')
		{
			while (*src >= '0' && *src <= '9')
				src++;
			count++;
		}
		else
			error_handler();
	}
	return (count);
}
