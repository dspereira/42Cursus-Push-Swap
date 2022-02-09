/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:00:03 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 16:00:04 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

int		is_bigger(int a, int b);
int		is_smaller(int a, int b);
int		get_elem_cont(t_lst *elem);
t_lst	*get_elem(t_stack stack, int pos);
t_lst	*get_next_elem(t_lst *elem, int dir);

#endif