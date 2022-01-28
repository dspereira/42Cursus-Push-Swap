#include "../../includes/push_swap.h"
#include "list.h"

t_stack stack_init(char id)
{
	t_stack stack;

	stack.id = id;
	stack.first_elem = 0;
	stack.last_elem = 0;
	return stack;
}

void	stack_fill(t_stack *stack, int *cont, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		list_add_front(stack, list_new(cont[i]));
		i++;
	}
}

void	stack_free(t_stack *stack)
{
	t_list	*elem;
	t_list	*next;

	elem = stack->first_elem;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
}
