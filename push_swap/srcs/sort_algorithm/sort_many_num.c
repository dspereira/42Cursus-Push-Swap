#include "../../includes/push_swap.h"
#include "sort_utils.h"
#include "sort_many_num.h"
#include "moves_list.h"

int	get_mov_a_to_b(t_mov *list_mov, t_stack stack, t_chunk *ch_1, t_chunk *ch_2)
{
	int		i;
	int		cont;
	t_lst	*elem;

	init_movs_list(list_mov);
	elem = get_elem(stack, TOP);
	i = 0;
	while (elem != NULL)
	{
		cont = get_elem_cont(elem);
		if (is_part_of_chunk(cont, *ch_1) || is_part_of_chunk(cont, *ch_2))
		{
			add_mov(list_mov, RA, i);
			add_mov(list_mov, PB, 1);
			if (ch_2 && is_part_of_chunk(cont, *ch_1))
				add_mov(list_mov, RB, 1);
			return (1);
		}
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (0);
}

int	get_mov_b_to_a(t_mov *list_mov, t_stack stack, t_chunk chunk)
{
	t_pos	p_big;
	t_pos	p_smal;

	init_movs_list(list_mov);
	p_big = search_elem1(stack, chunk, &is_bigger);
	p_smal = search_elem1(stack, chunk, &is_smaller);
	if (p_big.pos == -1 || p_smal.pos == -1)
		return (0);
	if (p_big.pos <= p_smal.pos)
		get_elem_mov(list_mov, p_big, 1);
	else
		get_elem_mov(list_mov, p_smal, 0);
	return (1);
}

void	mov_a_to_b(t_stack *st_a, t_stack *st_b, t_chunk *ch_1, t_chunk *ch_2)
{
	t_mov	list_movs[MOVS_LIST_SIZE];

	while (get_mov_a_to_b(list_movs, *st_a, ch_1, ch_2))
		exec_movs(list_movs, st_a, st_b);
}

void	mov_b_to_a(t_stack *st_a, t_stack *st_b, t_chunk chunk)
{
	t_mov	list_movs[MOVS_LIST_SIZE];

	while (get_mov_b_to_a(list_movs, *st_b, chunk))
		exec_movs(list_movs, st_a, st_b);
}

void	sort_many_num(t_stack *st_a, t_stack *st_b, t_chunk *ch, int num_ch)
{
	t_mov	list_movs[MOVS_LIST_SIZE];
	int		aux;
	int		i1;
	int		i2;

	aux = (int)(num_ch * 0.85);
	if (aux % 2 == 0)
		aux--;
	aux = (int)(aux / 2);
	i1 = aux;
	i2 = aux + 1;
	while (i2 < num_ch)
	{
		if (i1 >= 0)
			mov_a_to_b(st_a, st_b, &ch[i1--], &ch[i2++]);
		else
			mov_a_to_b(st_a, st_b, &ch[i2++], 0);
	}
	i1 = num_ch - 1;
	while (i1 >= 0)
	{
		mov_b_to_a(st_a, st_b, ch[i1]);
		reverse_rotate_stack(st_a, ch[i1--]);
	}
}
