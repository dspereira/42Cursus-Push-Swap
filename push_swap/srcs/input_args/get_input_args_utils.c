#include "../../includes/push_swap.h"
#include "get_input_args_utils.h"

#include <stdio.h>

void	free_matrix(char **m, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

long int	atoi_long(char *str)
{
	int			i;
	long int	num;
	int			mult;

	i = 0;
	num = 0;
	mult = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	return ((num * mult));
}

int	is_longer_than_int(char *str)
{
	if (ft_strlen(str) > 11)
		return (1);
	else
		return (0);
}

int	is_range_int(long int nb)
{
	if (nb >= MIN_INT && nb <= MAX_INT)
		return (1);
	else
		return (0);
}

int	is_numeric(char *str)
{
	int	i;
	
	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
		{
			i++;
			if (ft_strlen(str) > 1)
				continue ;
			else
				return (0);
		}
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
