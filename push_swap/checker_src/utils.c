#include "checker.h"

void	free_mem(t_list **movs, int *num_list)
{
	if (movs)
		ft_lstclear(movs, &free);
	if (num_list)
		free(num_list);
}

int	is_mov_valid(char *mov)
{
	size_t	len;

	len = ft_strlen(mov) + 1;
	if (!ft_strncmp("ra\n", mov, len) || !ft_strncmp("rb\n", mov, len)
		|| !ft_strncmp("sa\n", mov, len) || !ft_strncmp("sb\n", mov, len)
		|| !ft_strncmp("pa\n", mov, len) || !ft_strncmp("pb\n", mov, len)
		|| !ft_strncmp("rra\n", mov, len) || !ft_strncmp("rrb\n", mov, len)
		|| !ft_strncmp("rr\n", mov, len) || !ft_strncmp("rr\n", mov, len)
		|| !ft_strncmp("rrr\n", mov, len) || !ft_strncmp("rrr\n", mov, len)
		|| !ft_strncmp("ss\n", mov, len) || !ft_strncmp("ss\n", mov, len))
	{
		return (1);
	}
	return (0);
}

int	has_repeted_num(int *input, int size)
{
	int	*sorted_arr;
	int	has_repeted;

	sorted_arr = input_array_sort(input, size);
	has_repeted = input_check_repeted_num(sorted_arr, size);
	free(sorted_arr);
	return (has_repeted);
}

int	is_sorted_stack(t_stack stack_a, t_stack stack_b)
{
	t_lst	*elem;

	if (stack_b.first_elem)
		return (0);
	elem = stack_a.last_elem;
	while (elem->prev)
	{
		if (elem->content > elem->prev->content)
			return (0);
		elem = elem->prev;
	}
	return (1);
}
