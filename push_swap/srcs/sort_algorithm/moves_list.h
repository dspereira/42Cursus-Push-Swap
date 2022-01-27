#ifndef MOVES_LIST_H
# define MOVES_LIST_H

# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8
# define MOVS_LIST_SIZE 10

typedef struct s_mov
{
	int	size;
	int	mov_id;
}	t_mov;

int		get_number_movs(t_mov *list_movs);
void	init_movs_list(t_mov *list_movs);
void	add_mov(t_mov *list_movs, int mov_id, int size);
void	exec_movs(t_mov *list_movs, t_stack *stack_1, t_stack *stack_2);

#endif