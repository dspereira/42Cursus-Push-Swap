#include "../../includes/push_swap.h"
#include "sort_utils.h"
#include "sort_big.h"

void	reverse_rotate_stack(t_stack *stack, t_chunk chunk)
{
	int	i;

	i = 0;
	while (stack->last_elem->content != chunk.min)
	{
		stack_reverse_rotate(stack, DO_PRINT);
		i++;
	}
}

int	mov_a_to_b(t_stack *stack_a, t_stack *stack_b, t_chunk *ch_1, t_chunk *ch_2)
{
	int		i;
	int		cont;
	t_lst	*elem;

	elem = get_elem(*stack_a, TOP);
	i = 0;
	while (elem != NULL)
	{
		cont = get_elem_cont(elem);
		if (is_part_of_chunk(cont, *ch_1) || is_part_of_chunk(cont, *ch_2))
		{
			stack_rotate_mult(stack_a, i, DO_PRINT);
			stack_push(stack_a, stack_b, DO_PRINT);
			if (ch_2 && is_part_of_chunk(cont, *ch_1))
				stack_rotate(stack_b, DO_PRINT);
			return (1);
		}
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (0);
}

void	sort_big(t_stack *st_a, t_stack *st_b, t_chunk *ch, int num_ch)
{
	int		i;
	int		j;

	j = num_ch / 2;
	i = j - 1;
	while (j < num_ch)
	{
		while (mov_a_to_b(st_a, st_b, &ch[i], &ch[j]))
			;
		i--;
		j++;
	}
	i = num_ch - 1;
	while (i >= 0)
	{
		while (mov_b_to_a(st_a, st_b, ch[i]))
			;
		reverse_rotate_stack(st_a, ch[i]);
		i--;
	}
}
