#include "../../includes/push_swap.h"
#include "sort_utils.h"

int	is_bigger(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

int	is_smaller(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}

int	get_elem_cont(t_list *elem)
{
	return (elem->content);
}

t_list	*get_elem(t_stack stack, int pos)
{
	if (pos == TOP)
		return (stack.last_elem);
	else
		return (stack.first_elem);
}

t_list	*get_next_elem(t_list *elem, int dir)
{
	if (dir == DOWN)
		return (elem->prev);
	else
		return (elem->next);
}
