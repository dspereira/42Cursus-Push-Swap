#include "../../includes/push_swap.h"

void *oom_guard(void *p)
{
	if (!p)
	{
		ft_putstr_fd("Out of memory!\n", STD_OUT_FD);
		exit(EXIT_FAILURE);
	}
	return p;
}