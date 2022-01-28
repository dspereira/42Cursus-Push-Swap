#include "../../includes/push_swap.h"

int	*array_dup(const int *src, int size)
{
	int	*dst;
	int	i;

	dst = malloc(size * sizeof(int));
	if (!dst)
		return (0);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	*input_array_sort(const int *src, int size)
{
	int	i;	
	int	j;
	int	buff;
	int	*dst;

	dst = array_dup(src, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (dst[j] > dst[j + 1])
			{
				buff = dst[j];
				dst[j] = dst[j + 1];
				dst[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
	return (dst);
}
