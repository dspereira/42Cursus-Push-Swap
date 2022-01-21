#include "../includes/push_swap.h"

/*
 *    return: 1 -> conversion sucess
 *            0 -> conversion error
 */
int	convert_number(char *src, int *dst)
{
	long int	num;

	if (ft_strlen(src) > 11)
		return (0);
	num = atoi_long(src);
	if (num < MIN_INT || num > MAX_INT)
		return (0);
	*dst = (int)num;
	return (1);
}

int	is_numeric(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (i == 0 && (arr[i] == '-' || arr[i] == '+'))
		{
			i++;
			if (ft_strlen(arr) > 1)
				continue ;
			else
				return (0);
		}
		if ((arr[i] < '0' || arr[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

/*
 *	return array of integers, or 0 if an error occurred
 */
int	*get_int_arr(char **m, int size)
{
	int	*arr;
	int	i;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!is_numeric(m[i]) || !convert_number(m[i], &arr[i]))
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
int	parse_strings_to_array(char **src, int size, int **dst)
{
	char	**m;
	int		done_split;

	done_split = 0;
	if (size == 1)
	{
		m = ft_split(*src, ' ');
		size = get_size_matrix(m);
		done_split = 1;
	}
	else
		m = src;
	*dst = get_int_arr(m, size);
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
	size = parse_strings_to_array((args + 1), (argc - 1), dst);
	if (size)
		return (size);
	return (-1);
}
