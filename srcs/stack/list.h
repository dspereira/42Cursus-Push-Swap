/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:00:57 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 16:00:59 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

t_lst	*list_new(int content);
void	list_add_front(t_stack *stack, t_lst *new);
void	list_add_back(t_stack *stack, t_lst *new);

#endif