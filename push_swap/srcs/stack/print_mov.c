#include "../../includes/push_swap.h"

void	print_mov(char *mov, char stack_id)
{
	char	arr[3];

	arr[0] = stack_id;
	arr[1] = '\n';
	arr[2] = '\0';
	ft_putstr_fd(mov, STD_OUT_FD);
	ft_putstr_fd(arr, STD_OUT_FD);
}
