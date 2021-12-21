#include "push_swap.h" 

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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
   	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		new->prev = NULL;
		(*lst)->prev = new;
	}
	*lst = new; 
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		(*lst)->next = new;
		new->next = NULL;
		new->prev = *lst;
		*lst = new;
	}
}

void create_list(t_stack *stack, int *content, int size)
{
	int i;
	
	i = 0;
	while(i < size)
	{
		ft_lstadd_front(&(stack->first_elem), ft_lstnew(content[i]));
		if (i == 0)
			stack->last_elem = stack->first_elem;
		i++;
	}
	stack->size = size;
}
