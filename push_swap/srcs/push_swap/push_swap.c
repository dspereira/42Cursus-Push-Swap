#include "../../includes/push_swap.h"

void free_inp(int *a, int *b)
{
	free(a);
	free(b);
}

void	stack_sort(int *in_arr, int *in_arr_sort, int size_arr)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_chunk	chunk[20];
	int		num_chunks;

	stack_a = stack_init(STACK_A);
	stack_b = stack_init(STACK_B);
	stack_fill(&stack_a, in_arr, size_arr);
	if (size_arr == 2)
		sort_two_num(&stack_a);
	else if (size_arr == 3)
		sort_three_num(&stack_a);
	else if (size_arr > 3 && size_arr <= 5)
		sort_five_num(&stack_a, &stack_b);
	else if (size_arr > 5)
	{
		num_chunks = get_chunks(chunk, in_arr_sort, size_arr);
		sort_big(&stack_a, &stack_b, chunk, num_chunks);
	}
	stack_free(&stack_a);
}

void	push_swap(int in_size, char **in)
{
	int	*in_arr;
	int	*in_arr_sort;
	int	size;

	size = get_input_args(in, in_size, &in_arr);
	if (size < 0)
	{
		ft_putstr_fd("Error\n", FD);
		return ;
	}
	else if (size == 0)
		return ;
	in_arr_sort = input_array_sort(in_arr, size);
	if (input_check_repeted_num(in_arr_sort, size))
	{
		ft_putstr_fd("Error\n", FD);
		free_inp(in_arr, in_arr_sort);
		return ;
	}
	if (!input_check_is_sort(in_arr, size))
	{
		stack_sort(in_arr, in_arr_sort, size);
	}
	free_inp(in_arr, in_arr_sort);
}
