#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h"
# include "get_next_line.h"

# define STD_IN_FD 0
# define STD_OUT_FD 1

void	free_mem(t_list **movs, int *num_list);
int		is_mov_valid(char *mov);
int		has_repeted_num(int *input, int size);
int		is_sorted_stack(t_stack stack_a, t_stack stack_b);
int		get_movs_list(t_list **lst);
void	execute_mov(t_stack *stack_a, t_stack *stack_b, const char *cont);
void	execute_movs(t_stack *stack_a, t_stack *stack_b, t_list *mov_list);
int		analyze_movs(int *input, t_list *mov_list, int in_size);
int		main(int argc, char **argv);

#endif