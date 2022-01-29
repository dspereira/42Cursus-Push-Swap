#include "../../includes/push_swap.h"
#include "sort_utils.h"

int	get_stack_size(t_stack stack)
{
	t_lst	*elem;
	int		i;

	i = 0;
	elem = get_elem(stack, TOP);
	while (elem != NULL)
	{
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (i);
}

int	get_pos_smaller(t_stack stack)
{
	t_lst	*elem;
	int		cont;
	int		pos;
	int		i;

	elem = get_elem(stack, TOP);
	cont = get_elem_cont(elem);
	pos = 0;
	i = 0;
	while (elem != NULL)
	{
		if (get_elem_cont(elem) < cont)
		{
			cont = get_elem_cont(elem);
			pos = i;
		}
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (pos);
}

void	move_smaller_elem(t_stack *stack_1, t_stack *stack_2)
{
	int	size;
	int	pos;

	size = get_stack_size(*stack_1);
	pos = get_pos_smaller(*stack_1);
	if ((pos * 2) <= size)
	{
		while (pos > 0)
		{
			stack_rotate(stack_1);
			pos--;
		}
		stack_push(stack_1, stack_2);
	}
	else
	{
		while (pos < size)
		{
			stack_reverse_rotate(stack_1);
			pos++;
		}
		stack_push(stack_1, stack_2);
	}
}

void	sort_five_num(t_stack *stack_1, t_stack *stack_2)
{
	while (get_stack_size(*stack_1) > 3)
		move_smaller_elem(stack_1, stack_2);
	sort_three_num(stack_1);
	while (get_stack_size(*stack_2) > 0)
		stack_push(stack_2, stack_1);
}
