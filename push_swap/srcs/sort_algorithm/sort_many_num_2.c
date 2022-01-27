#include "../../includes/push_swap.h"
#include "sort_utils.h"
#include "sort_many_num.h"
#include "moves_list.h"

void	reverse_rotate_stack(t_stack *stack_1, t_chunk chunk)
{
	int	i;

	i = 0;
	while (stack_1->last_elem->content != chunk.min)
	{
		stack_reverse_rotate(stack_1);
		i++;
	}
}

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

t_pos	search_elem1(t_stack stack, t_chunk chunk, int (*comp)(int, int))
{
	t_list	*elem;
	t_list	*elem_found;
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

void	get_elem_mov(t_mov *list_mov, t_pos p, int is_bigger)
{
	if (p.dir == FROM_TOP)
		add_mov(list_mov, RB, p.pos);
	else
		add_mov(list_mov, RRB, p.pos + 1);
	add_mov(list_mov, PA, 1);
	if (!is_bigger)
		add_mov(list_mov, RA, 1);
}
