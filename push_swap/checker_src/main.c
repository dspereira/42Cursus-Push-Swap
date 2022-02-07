#include "checker.h"

/*
 *	return: 0 -> OK
 *			1 -> Error
 */
int	get_movs_list(t_list **lst)
{
	t_list	*new;
	char	*line;
	int		error;

	*lst = 0;
	error = 0;
	line = get_next_line(STD_IN_FD);
	while (line)
	{
		if (is_mov_valid(line))
		{
			new = oom_guard(ft_lstnew(line));
			ft_lstadd_back(lst, new);
			line = get_next_line(STD_IN_FD);
		}
		else
		{
			free(line);
			error = 1;
			break ;
		}
	}
	return (error);
}

void	execute_mov(t_stack *stack_a, t_stack *stack_b, const char *cont)
{
	size_t	cont_len;

	cont_len = ft_strlen(cont) + 1;
	if (!ft_strncmp("ra\n", cont, cont_len)
		|| !ft_strncmp("rr\n", cont, cont_len))
		stack_rotate(stack_a, DONT_PRINT);
	if (!ft_strncmp("rb\n", cont, cont_len)
		|| !ft_strncmp("rr\n", cont, cont_len))
		stack_rotate(stack_b, DONT_PRINT);
	if (!ft_strncmp("rra\n", cont, cont_len)
		|| !ft_strncmp("rrr\n", cont, cont_len))
		stack_reverse_rotate(stack_a, DONT_PRINT);
	if (!ft_strncmp("rrb\n", cont, cont_len)
		|| !ft_strncmp("rrr\n", cont, cont_len))
		stack_reverse_rotate(stack_b, DONT_PRINT);
	if (!ft_strncmp("sa\n", cont, cont_len)
		|| !ft_strncmp("ss\n", cont, cont_len))
		stack_swap(stack_a, DONT_PRINT);
	if (!ft_strncmp("sb\n", cont, cont_len)
		|| !ft_strncmp("ss\n", cont, cont_len))
		stack_swap(stack_b, DONT_PRINT);
	if (!ft_strncmp("pa\n", cont, cont_len))
		stack_push(stack_b, stack_a, DONT_PRINT);
	if (!ft_strncmp("pb\n", cont, cont_len))
		stack_push(stack_a, stack_b, DONT_PRINT);
}

void	execute_movs(t_stack *stack_a, t_stack *stack_b, t_list *mov_list)
{
	t_list	*movs;
	char	*cont;

	movs = mov_list;
	while (movs)
	{
		cont = movs->content;
		execute_mov(stack_a, stack_b, cont);
		movs = movs->next;
	}
}

int	analyze_movs(int *input, t_list *mov_list, int in_size)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		is_sorted;

	stack_a = stack_init(STACK_A);
	stack_b = stack_init(STACK_B);
	stack_fill(&stack_a, input, in_size);
	if (mov_list)
		execute_movs(&stack_a, &stack_b, mov_list);
	is_sorted = is_sorted_stack(stack_a, stack_b);
	if (stack_a.first_elem)
		stack_free(&stack_a);
	if (stack_b.first_elem)
		stack_free(&stack_b);
	return (is_sorted);
}

int	main(int argc, char **argv)
{
	int		*input;
	t_list	*lst;
	int		size;

	input = 0;
	lst = 0;
	size = get_input_args(argv, argc, &input);
	if (size <= 0 || has_repeted_num(input, size))
	{
		if (size != 0)
			ft_putstr_fd("Error\n", STD_OUT_FD);
	}
	else if (get_movs_list(&lst))
		ft_putstr_fd("Error\n", STD_OUT_FD);
	else if (analyze_movs(input, lst, size))
		ft_putstr_fd("OK\n", STD_OUT_FD);
	else
		ft_putstr_fd("KO\n", STD_OUT_FD);
	free_mem(&lst, input);
	return (0);
}
