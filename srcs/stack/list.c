/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:00:51 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 16:00:54 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "list.h"

t_lst	*list_new(int content)
{
	t_lst	*elem;

	elem = oom_guard(malloc(sizeof(t_lst)));
	elem->content = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	list_add_front(t_stack *stack, t_lst *new)
{
	if (!new)
		return ;
	if (stack->first_elem)
	{
		new->next = stack->first_elem;
		new->prev = NULL;
		stack->first_elem->prev = new;
		stack->first_elem = new;
	}
	else
	{
		stack->first_elem = new;
		stack->last_elem = new;
	}
}

void	list_add_back(t_stack *stack, t_lst *new)
{
	if (!new)
		return ;
	if (stack->last_elem)
	{
		stack->last_elem->next = new;
		new->next = NULL;
		new->prev = stack->last_elem;
		stack->last_elem = new;
	}
	else
	{
		stack->first_elem = new;
		stack->last_elem = new;
	}
}
