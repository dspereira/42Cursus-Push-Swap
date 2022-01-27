#ifndef SORT_MANY_NUM_H
# define SORT_MANY_NUM_H

# include "moves_list.h"

typedef struct s_pos
{
	int	pos;
	int	dir;
}	t_pos;

void	reverse_rotate_stack(t_stack *stack_1, t_chunk chunk);
int		is_part_of_chunk(int cont, t_chunk chunk);
t_pos	get_best_pos(int stack_size, int pos);
t_pos	search_elem1(t_stack stack, t_chunk chunk, int (*comp)(int, int));
void	get_elem_mov(t_mov *list_mov, t_pos p, int is_bigger);

#endif