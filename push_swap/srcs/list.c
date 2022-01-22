#include "../includes/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->content = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	ft_lstadd_front(t_stack *stack, t_list *new)
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

void	ft_lstadd_back(t_stack *stack, t_list *new)
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

void create_list(t_stack *stack, int *cont, int size)
{
	int i;
	
	i = 0;
	while(i < size)
	{
		ft_lstadd_front(stack, ft_lstnew(cont[i]));
		i++;
	}
	stack->size = size;
}