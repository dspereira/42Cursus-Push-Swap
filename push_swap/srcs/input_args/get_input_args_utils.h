#ifndef GET_INPUT_ARGS_UTILS_H
# define GET_INPUT_ARGS_UTILS_H

void		free_matrix(char **m, int size);
long int	atoi_long(char *str);
int			is_longer_than_int(char *str);
int			is_range_int(long int nb);
int			is_numeric(char *str);

#endif