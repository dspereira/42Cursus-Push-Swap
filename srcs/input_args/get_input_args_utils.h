/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_args_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:55:06 by dsilveri          #+#    #+#             */
/*   Updated: 2022/02/09 15:55:08 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_INPUT_ARGS_UTILS_H
# define GET_INPUT_ARGS_UTILS_H

void		free_matrix(char **m, int size);
long int	atoi_long(char *str);
int			is_longer_than_int(char *str);
int			is_range_int(long int nb);
int			is_numeric(char *str);

#endif