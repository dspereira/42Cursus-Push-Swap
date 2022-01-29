#include "../../includes/push_swap.h"

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

int	*input_array_sort(const int *src, int size)
{
	int	i;	
	int	j;
	int	buff;
	int	*dst;
	int	made_swap;

	dst = array_dup(src, size);
	i = 0;
	made_swap = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			//ft_putstr_fd("\npassou aqui", FD);
			if (dst[j] > dst[j + 1])
			{
				buff = dst[j];
				dst[j] = dst[j + 1];
				dst[j + 1] = buff;
				made_swap = 1;
			}
			j++;
		}
		//if (!made_swap)
		//	break;
		i++;
	}
	return (dst);
}
