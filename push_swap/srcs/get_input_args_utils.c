#include "../includes/push_swap.h"

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
