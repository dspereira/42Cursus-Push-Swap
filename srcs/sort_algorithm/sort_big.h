/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:59:38 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 15:59:39 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_BIG_H
# define SORT_BIG_H

typedef struct s_pos
{
	int	pos;
	int	dir;
}	t_pos;

int		is_part_of_chunk(int cont, t_chunk chunk);
t_pos	get_best_pos(int stack_size, int pos);
t_pos	search_elem(t_stack stack, t_chunk chunk, int (*comp)(int, int));
void	mov_elem(t_stack *stack_a, t_stack *stack_b, t_pos p, int is_bigger);
int		mov_b_to_a(t_stack *stack_a, t_stack *stack_b, t_chunk chunk);

#endif