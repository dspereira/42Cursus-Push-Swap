/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:02:16 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 16:24:22 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*oom_guard(void *p)
{
	if (!p)
	{
		ft_putstr_fd("Out of memory!\n", STD_OUT_FD);
		exit(EXIT_FAILURE);
	}
	return (p);
}
