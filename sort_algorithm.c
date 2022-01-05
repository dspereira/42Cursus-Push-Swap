#include "push_swap.h"

// FUNÇAO APENAS DE TESTE
void print_stack1(t_stack stack)
{
	while (stack.last_elem != NULL)
	{
		printf("%i\n", stack.last_elem->content);
		stack.last_elem = stack.last_elem->prev;
	}
}

// FUNÇAO APENAS DE TESTE
void print_stacks(t_stack stack_a, t_stack stack_b)
{
	printf("##### Print Stacks #####\n");
	print_stack1(stack_a);
	printf("-----\n");
	print_stack1(stack_b);
	printf("########################\n");
}

int get_bottom_num(t_stack stack)
{
	return (stack.first_elem->content); 
}

int get_top_num(t_stack stack)
{
	return (stack.last_elem->content); 
}

int search_element_from_top(t_stack stack, t_chunk chunk)
{
	int i;
	int content;
	t_list *elem;

	elem = stack.last_elem;
	i = 0;	
	while (elem != NULL)
	{
		content = elem->content;
		if (content >= chunk.min && content <= chunk.max)
			return (i);	
		elem = elem->prev;
		i++;
	}
	return (-1);
}

void move_element(t_stack *stack_a, t_stack *stack_b, int position)
{
	while (position >= 0)
	{
		if (position == 0)
			stack_push(stack_a, stack_b);
		else
			stack_rotate(stack_a);
		position--;
	}
}

void move_chunck(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	int position;
	
	position = 1;
	while (position >= 0)
	{
		position = search_element_from_top(*stack_a, chunk);
		move_element(stack_a, stack_b, position);
	}			
}

void stack_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	move_chunck(stack_a, stack_b, chunk[0]);
	print_stacks(*stack_a, *stack_b);
}