#include "../../includes/push_swap.h"
#include "get_input_args_utils.h"

int	get_size_matrix(char **m)
{
	int	i;

	if (!m)
		return (0);
	i = 0;
	while (m[i])
		i++;
	return (i);
}

/*
 *    return: 1 -> conversion sucess
 *            0 -> conversion error
 */
int	convert_str_to_nb(char *src, int *dst)
{
	long int	nb;

	if (is_longer_than_int(src))
		return (0);
	nb = atoi_long(src);
	if (!is_range_int(nb))
		return (0);
	*dst = (int)nb;
	return (1);
}

/*
 *	return array of integers, or 0 if an error occurred
 */
int	*get_nb_array(char **m, int size)
{
	int	*arr;
	int	i;

	arr = oom_guard(malloc(size * sizeof(int)));
	i = 0;
	while (i < size)
	{
		if (!is_numeric(m[i]) || !convert_str_to_nb(m[i], &arr[i]))
		{
			free(arr);
			return (0);
		}
		i++;
	}
	return (arr);
}

/*
 *   return size of dst array
 */
int	parse_input_args(char **src, int size, int **dst)
{
	char	**m;
	int		done_split;

	done_split = 0;
	if (size == 1)
	{
		m = oom_guard(ft_split(src[0], ' '));
		size = get_size_matrix(m);
		done_split = 1;
	}
	else
		m = src;
	*dst = get_nb_array(m, size);
	if (done_split)
		free_matrix(m, size);
	if (*dst)
		return (size);
	return (0);
}

/*
 *   return: >0 -> Number of parameters
 *            0 -> No parameters are specified
 *           -1 -> Error
 */
int	get_input_args(char **args, int argc, int **dst)
{
	int	size;

	if (argc < 2)
		return (0);
	size = parse_input_args((args + 1), (argc - 1), dst);
	if (size)
		return (size);
	return (-1);
}
