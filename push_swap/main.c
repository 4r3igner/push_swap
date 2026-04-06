#include "push_swap.h"

static void	free_all(int *arr, t_binary **root, c_llist **head)
{
	if (arr)
		free(arr);
	if (root && *root)
		freenclean_bst(root);
	if (head && *head)
		freenclean_list(head);
}

static void	exit_safely(int *arr, t_binary **root, c_llist **head_l)
{
	free_all(arr, root, head_l);
	error_handler();
}

static void	execute_sort(c_llist **head_l, int *arr, t_binary **root)
{
	int		index;
	c_llist	*b;

	index = 0;
	b = NULL;
	sort_bst(*root, &index);
	free_all(arr, root, NULL);
	sort_stacks(head_l, &b);
	freenclean_list(head_l);
	if (b)
		freenclean_list(&b);
}

static void	indexation_bst(int *arr, int size)
{
	int			i;
	int			is_dupp;
	t_binary	*root;
	c_llist		*head_l;
	c_llist		*new;

	i = 1;
	is_dupp = 0;
	head_l = create_node(arr[0]);
	root = create_bst(arr[0], head_l);
	while (i < size)
	{
		new = add_new_node(arr[i], &head_l);
		if (!new)
			exit_safely(arr, &root, &head_l);
		insert_bst(arr[i], root, new, &is_dupp);
		if (is_dupp)
			exit_safely(arr, &root, &head_l);
		i++;
	}
	execute_sort(&head_l, arr, &root);
}

int	main(int argc, char **argv)
{
	int	*arr;
	int	size;
	int	i;
	int	global_p;

	if (argc < 2)
		return (0);
	size = 0;
	i = 1;
	while (i < argc)
		size += checkncount(argv[i++]);
	if (size == 0)
		return (0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_handler();
	global_p = 0;
	i = 1;
	while (i < argc)
		artons(argv[i++], arr, &global_p);
	indexation_bst(arr, size);
	return (0);
}
