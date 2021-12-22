#include "push_swap.h"

void stack_print_mov(char *mov, char stack_id)
{
	int i;

	i = 0;
	while (mov[i] != '\0')
		i++;
	write(1, mov, i);
	write(1, &stack_id, 1);
	write(1, "\n", 1);
}