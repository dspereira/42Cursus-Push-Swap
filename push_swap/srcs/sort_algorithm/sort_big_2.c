/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:59:25 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 15:59:28 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "sort_utils.h"
#include "sort_big.h"

int	is_part_of_chunk(int cont, t_chunk chunk)
{
	if (cont >= chunk.min && cont <= chunk.max)
		return (1);
	else
		return (0);
}

t_pos	get_best_pos(int stack_size, int pos)
{
	t_pos	new_pos;

	if (pos == -1 || !stack_size)
		new_pos.pos = -1;
	else if (pos > (int)(stack_size / 2))
	{
		new_pos.pos = stack_size - pos - 1;
		new_pos.dir = FROM_BOT;
	}
	else
	{
		new_pos.pos = pos;
		new_pos.dir = FROM_TOP;
	}
	return (new_pos);
}

t_pos	search_elem(t_stack stack, t_chunk chunk, int (*comp)(int, int))
{
	t_lst	*elem;
	t_lst	*elem_found;
	int		i;
	int		pos;

	elem = get_elem(stack, TOP);
	elem_found = 0;
	i = 0;
	pos = -1;
	while (elem != NULL)
	{
		if (is_part_of_chunk(get_elem_cont(elem), chunk))
		{
			if (!elem_found)
				elem_found = elem;
			if (comp(get_elem_cont(elem), get_elem_cont(elem_found)))
				elem_found = elem;
			if (elem_found == elem)
				pos = i;
		}
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (get_best_pos(i, pos));
}

void	mov_elem(t_stack *stack_a, t_stack *stack_b, t_pos p, int is_bigger)
{
	if (p.dir == FROM_TOP)
		stack_rotate_mult(stack_b, p.pos, DO_PRINT);
	else
		stack_reverse_rotate_mult(stack_b, p.pos + 1, DO_PRINT);
	stack_push(stack_b, stack_a, DO_PRINT);
	if (!is_bigger)
		stack_rotate(stack_a, DO_PRINT);
}

int	mov_b_to_a(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	t_pos	p_big;
	t_pos	p_smal;

	p_big = search_elem(*stack_b, chunk, &is_bigger);
	p_smal = search_elem(*stack_b, chunk, &is_smaller);
	if (p_big.pos == -1 || p_smal.pos == -1)
		return (0);
	if (p_big.pos <= p_smal.pos)
		mov_elem(stack_a, stack_b, p_big, 1);
	else
		mov_elem(stack_a, stack_b, p_smal, 0);
	return (1);
}
