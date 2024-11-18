/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:59:55 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 15:59:56 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "sort_utils.h"

void	sort_two_num(t_stack *stack)
{
	int	top;
	int	bot;

	top = get_elem_cont(get_elem(*stack, TOP));
	bot = get_elem_cont(get_elem(*stack, BOT));
	if (is_bigger(top, bot))
		stack_swap(stack, DO_PRINT);
}
