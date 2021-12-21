#include "push_swap.h"


void swap_content(t_list *elem1, t_list *elem2)
{
	int content_tmp;

	content_tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = content_tmp;
}

void stack_swap(t_list *last_elem, int stack)
{
	if (!last_elem || !(last_elem->prev))
		return ;
	swap_content(last_elem, last_elem->prev);
	/*if (stack == STACK_A)
		write(1, "sa", 2);
	else 
		write(1, "sb", 2);*/
}

void stack_rotate(t_list **first_elem, t_list **last_elem, int stack)
{
	t_list *last_temp;

	last_temp = (*last_elem)->prev;
	last_temp->next = NULL;
	ft_lstadd_front(first_elem, *last_elem);
	*last_elem = last_temp;
	/*if (stack == STACK_A)
		write(1, "ra", 2);
	else 
		write(1, "rb", 2);*/
}

void stack_reverse_rotate(t_list **first_elem, t_list **last_elem, int stack)
{
	t_list *first_temp;

	first_temp = (*first_elem)->next;
	first_temp->prev = NULL;
	ft_lstadd_back(last_elem, *first_elem);
	*first_elem = first_temp;
	/*if (stack == STACK_A)
		write(1, "rra", 2);
	else 
		write(1, "rrb", 2);*/
}

