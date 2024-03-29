/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:25:58 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 16:25:59 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h"
# include "get_next_line.h"

# define STD_IN_FD 0
# define STD_OUT_FD 1
# define STD_ERR_FD 2

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