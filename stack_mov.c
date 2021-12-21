#include "push_swap.h"


void swap_content(t_list *elem1, t_list *elem2)
{
	int content_tmp;

	content_tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = content_tmp;
}

void stack_swap(t_stack *stack)
{
	if (!(stack->last_elem) || !(stack->last_elem->prev))
		return ;
	swap_content(stack->last_elem, stack->last_elem->prev);
	/*if (stack->id == STACK_A)
		write(1, "sa\n", 3);
	else 
		write(1, "sb\n", 3);*/
}

void stack_rotate(t_stack *stack)
{
	t_list *last_temp;

	last_temp = stack->last_elem->prev;
	last_temp->next = NULL;
	ft_lstadd_front(&(stack->first_elem), stack->last_elem);
	stack->last_elem = last_temp;
	/*if (stack->id == STACK_A)
		write(1, "ra\n", 3);
	else 
		write(1, "rb\n", 3);*/
}


void stack_reverse_rotate1(t_list **first_elem, t_list **last_elem, int stack)
{
	t_list *first_temp;

	first_temp = (*first_elem)->next;
	first_temp->prev = NULL;
	ft_lstadd_back(last_elem, *first_elem);
	*first_elem = first_temp;
	/*if (stack == STACK_A)
		write(1, "rra\n", 4);
	else 
		write(1, "rrb\n", 4);*/
}

void stack_reverse_rotate(t_stack *stack)
{
	t_list *first_temp;

	first_temp = stack->first_elem->next;
	first_temp->prev = NULL;
	ft_lstadd_back(&(stack->last_elem), stack->first_elem);
	stack->first_elem = first_temp;
	/*if (stack->id == STACK_A)
		write(1, "rra\n", 4);
	else 
		write(1, "rrb\n", 4);*/
}



