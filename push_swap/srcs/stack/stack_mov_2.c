#include "../../includes/push_swap.h"

void	stack_exec_moves(t_stack *s, int n, int do_print, void (*f)())
{
	while (n > 0)
	{
		f(s, do_print);
		n--;
	}
}

void	stack_rotate_mult(t_stack *stack, int n, int do_print)
{
	stack_exec_moves(stack, n, do_print, &stack_rotate);
}

void	stack_reverse_rotate_mult(t_stack *stack, int n, int do_print)
{
	stack_exec_moves(stack, n, do_print, &stack_reverse_rotate);
}
