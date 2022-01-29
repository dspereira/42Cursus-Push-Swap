#include "../../includes/push_swap.h"
#include <stdio.h>

int	*array_dup(const int *src, int size)
{
	int	*dst;
	int	i;

	dst = oom_guard(malloc(size * sizeof(int)));
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	swap(int *a, int *b)
{
	int	buff;

	buff = *a;
	*a = *b;
	*b = buff;
	return (1);
}

int	*input_array_sort(const int *src, int size)
{
	int	i;	
	int	j;
	int	*dst;
	int	made_swap;

	dst = array_dup(src, size);
	i = 0;
	made_swap = 0;
	while (i < size)
	{
		j = 0;
		made_swap = 0;
		while (j < size - 1)
		{
			if (dst[j] > dst[j + 1])
				made_swap = swap(&dst[j], &dst[j + 1]);
			j++;
		}
		if (!made_swap)
			break ;
		i++;
	}
	return (dst);
}
