#include "../../includes/push_swap.h"
#include "print_mov.h"
#include "list.h"

void	swap_content(t_lst *elem1, t_lst *elem2)
{
	int	content_tmp;

	content_tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = content_tmp;
}

void	stack_swap(t_stack *stack)
{
	if (!(stack->last_elem) || !(stack->last_elem->prev))
		return ;
	swap_content(stack->last_elem, stack->last_elem->prev);
	print_mov("s", stack->id);
}

void	stack_rotate(t_stack *stack)
{
	t_lst	*last_temp;

	if (!(stack->last_elem) || !(stack->last_elem->prev))
		return ;
	last_temp = stack->last_elem->prev;
	last_temp->next = NULL;
	list_add_front(stack, stack->last_elem);
	stack->last_elem = last_temp;
	print_mov("r", stack->id);
}

void	stack_reverse_rotate(t_stack *stack)
{
	t_lst	*first_temp;

	if (!(stack->last_elem) || !(stack->last_elem->prev))
		return ;
	first_temp = stack->first_elem->next;
	first_temp->prev = NULL;
	list_add_back(stack, stack->first_elem);
	stack->first_elem = first_temp;
	print_mov("rr", stack->id);
}

void	stack_push(t_stack *stack_1, t_stack *stack_2)
{
	t_lst	*last_temp;

	if (!(stack_1->last_elem))
		return ;
	last_temp = stack_1->last_elem->prev;
	stack_1->last_elem->next = NULL;
	stack_1->last_elem->prev = NULL;
	list_add_back(stack_2, stack_1->last_elem);
	if (last_temp)
	{
		last_temp->next = NULL;
		stack_1->last_elem = last_temp;
	}
	else
	{
		stack_1->first_elem = NULL;
		stack_1->last_elem = NULL;
	}
	print_mov("p", stack_2->id);
}
