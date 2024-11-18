/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:01:21 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 16:01:25 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "list.h"

t_stack	stack_init(char id)
{
	t_stack	stack;

	stack.id = id;
	stack.first_elem = 0;
	stack.last_elem = 0;
	return (stack);
}

void	stack_fill(t_stack *stack, int *cont, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		list_add_front(stack, list_new(cont[i]));
		i++;
	}
}

void	stack_free(t_stack *stack)
{
	t_lst	*elem;
	t_lst	*next;

	elem = stack->first_elem;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
}
