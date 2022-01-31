#include "../../includes/push_swap.h"

void stack_exec_moves(t_stack *stack, int n, void (*f)(t_stack *))
{
    while (n > 0)
    {
        f(stack);
        n--;
    }
}

void	stack_rotate_mult(t_stack *stack, int n)
{
    stack_exec_moves(stack, n, &stack_rotate);
}

void	stack_reverse_rotate_mult(t_stack *stack, int n)
{
    stack_exec_moves(stack, n, &stack_reverse_rotate);
}