#include <stdio.h>
#include "../includes/push_swap.h"
#include "get_next_line.h"

#define STD_IN_FD 0
#define STD_OUT_FD 1


void free_moves_list(t_list **lst)
{
	ft_lstclear(lst, &free);
}

int is_mov_valid(char *mov)
{
	size_t len;

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

int has_repeted_num(int *input, int size)
{
	int *sorted_arr;
	int has_repeted;

	sorted_arr = input_array_sort(input, size);	
	has_repeted = input_check_repeted_num(sorted_arr, size);
	free(sorted_arr);
	return (has_repeted);
}

int get_moves_list(t_list **lst)
{
	t_list *new;
	char *line;
	int error;

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
			free_moves_list(lst);
			error = 1;
			break;
		}
	}
	return (error);
}

void execute_move(t_stack *stack_a, t_stack *stack_b, const char *cont)
{
	size_t cont_len;

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

void execute_moves(t_stack *stack_a, t_stack *stack_b, t_list *mov_list)
{
	t_list *movs;
	char *cont;

	movs = mov_list;
	while (movs)
	{
		cont = movs->content;
		execute_move(stack_a, stack_b, cont);
		movs = movs->next;
	}
}

int is_sorted_stack(t_stack stack_a, t_stack stack_b)
{
	t_lst	*elem;
	
	if (stack_b.first_elem)
		return (0);
	elem = stack_a.last_elem;
	while(elem->prev)
	{
		if (elem->content > elem->prev->content)
			return (0);
		elem = elem->prev;
	}
	return (1);
}

int analyze_moves(int *input, t_list *mov_list, int in_size)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int is_sorted;

	stack_a = stack_init(STACK_A);
	stack_b = stack_init(STACK_B);
	stack_fill(&stack_a, input, in_size);
	if (mov_list)
		execute_moves(&stack_a, &stack_b, mov_list);
	is_sorted = 0;
	if (is_sorted_stack(stack_a, stack_b))
		is_sorted = 1;
	if (stack_a.first_elem)
		stack_free(&stack_a);
	if (stack_b.first_elem)
		stack_free(&stack_b);
	return (is_sorted);
}

int main(int argc, char **argv)
{
	int *input;
	t_list *lst;
	int size;
	int moves_error;

	size = get_input_args(argv, argc, &input);
	if (size < 0 || has_repeted_num(input, size))
	{
		ft_putstr_fd("Error\n", STD_OUT_FD);
		if (size > 0)
			free(input);
		return (0);
	}
	else if (size == 0)
		return (0);
	moves_error = get_moves_list(&lst);
	if (moves_error)
	{
		ft_putstr_fd("Error\n", STD_OUT_FD);
		free(input);
		free_moves_list(&lst);
		return (0);
	}
	if (analyze_moves(input, lst, size))
		ft_putstr_fd("OK\n", STD_OUT_FD);
	else 
		ft_putstr_fd("KO\n", STD_OUT_FD);
	free(input);
	free_moves_list(&lst);
	return (0);
}
