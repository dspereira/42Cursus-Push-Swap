#include "push_swap.h"

/*
Falta testar todas as funções em situaçãos em que só existem 1 ou 2 elementos ou stack vazia
*/

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
	stack_print_mov("s", stack->id);
}

void stack_rotate(t_stack *stack)
{
	t_list *last_temp;

	last_temp = stack->last_elem->prev;
	last_temp->next = NULL;
	ft_lstadd_front(&(stack->first_elem), stack->last_elem);
	stack->last_elem = last_temp;
	stack_print_mov("r", stack->id);
}

void stack_reverse_rotate(t_stack *stack)
{
	t_list *first_temp;

	first_temp = stack->first_elem->next;
	first_temp->prev = NULL;
	ft_lstadd_back(&(stack->last_elem), stack->first_elem);
	stack->first_elem = first_temp;
	stack_print_mov("rr", stack->id);
}

void stack_push(t_stack *stack_1, t_stack *stack_2)
{
	t_list *last_temp;
	
	last_temp = stack_1->last_elem->prev;
	stack_1->last_elem->next = NULL;
	stack_1->last_elem->prev = NULL;
	ft_lstadd_back(&(stack_2->last_elem), stack_1->last_elem);
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
	stack_print_mov("p", stack_1->id);
}
