#include "../../includes/push_swap.h"
#include "list.h"

t_list	*list_new(int content)
{
	t_list	*elem;

	elem = oom_guard(malloc(sizeof(t_list)));
	elem->content = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	list_add_front(t_stack *stack, t_list *new)
{
	if (!new)
		return ;
	if (stack->first_elem)
	{
		new->next = stack->first_elem;
		new->prev = NULL;
		stack->first_elem->prev = new;
		stack->first_elem = new;
	}
	else
	{
		stack->first_elem = new;
		stack->last_elem = new;
	}
}

void	list_add_back(t_stack *stack, t_list *new)
{
	if (!new)
		return ;
	if (stack->last_elem)
	{
		stack->last_elem->next = new;
		new->next = NULL;
		new->prev = stack->last_elem;
		stack->last_elem = new;
	}
	else
	{
		stack->first_elem = new;
		stack->last_elem = new;
	}
}
