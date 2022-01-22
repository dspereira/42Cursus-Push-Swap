#include "../includes/push_swap.h"

int is_longer_than_int(char *str)
{
	if (ft_strlen(str) > 11)
		return (1);
	else 
		return (0);
}

int is_range_int(long int nb)
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

int is_sorted(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int have_repeated_numbers(const int *arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

