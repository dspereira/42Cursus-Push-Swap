#include "push_swap.h"

int compare_last_elem(t_stack *stack)
{
	int n1;
	int n2;

	if (!(stack->last_elem) || !(stack->last_elem->prev))
	{
		printf("\nINVALIDO: STACK %c COM MENOS DE DOIS ELEMENTOS", stack->id);
		return -1;
	}
	n1 = stack->last_elem->content;
	n2 = stack->last_elem->prev->content;
	if (n1 > n2)
		return (1);
	else 
		return (0);
}

int compare_last_first(t_stack *stack)
{
	int last;
	int first;

	if (!(stack->last_elem) || !(stack->first_elem) || (stack->last_elem == stack->first_elem))
	{
		printf("\nINVALIDO: STACK %c COM MENOS DE DOIS ELEMENTOS", stack->id);
		return -1;
	}
	last = stack->last_elem->content;
	first = stack->first_elem->content;
	if (last > first)
		return (1);
	else 
		return (0);
}

void sort_three_num(t_stack *stack, int max, int min)
{
	int first;
	int last;

	first = stack->first_elem->content;
	last = stack->last_elem->content;
	while (first != max && last != first)
	{
		if(compare_last_elem(stack))
			stack_swap(stack);
		else if (compare_last_first(stack))
			stack_reverse_rotate(stack);
		else 
			stack_rotate(stack);	
		first = stack->first_elem->content;
		last = stack->last_elem->content;
	}
}

void print_stack1(t_stack stack)
{
	while (stack.last_elem != NULL)
	{
		printf("%i\n", stack.last_elem->content);
		stack.last_elem = stack.last_elem->prev;
	}
}

void print_stacks(t_stack stack_a, t_stack stack_b)
{
	printf("##### Print Stacks #####\n");
	print_stack1(stack_a);
	printf("-----\n");
	print_stack1(stack_b);
	printf("########################\n");

}

int get_rotation(t_stack stack, int content, int size)
{
	int i;
	int n1 = 0;
	int n2 = 0;

	i = 0;

	while (stack.last_elem->prev != NULL)
	{
		n1 = stack.last_elem->content;
		n2 = stack.last_elem->prev->content;

		//if (stack.last_elem->content < content && stack.last_elem->prev != NULL && stack.last_elem->prev->content > content)
		if ((n1 > content && n2 < content) || (n1 < content && n2 > content))
		{
			//printf("\nvalores a: %i  b: %i", n1, n2);
			if (i > (int)size/2)
			{
				//printf("\nrotate");
				return (1);
			}
				
			else
			{
				//printf("\nreverse rotate");
				return (0);	
			}	
		}
		stack.last_elem = stack.last_elem->prev;
		i++;
	}
	return (-1);
}


void stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	int max;
	int midle;
	int min;
	int count;
	int i;
	int size;
	int rotate_direction;

	max = stack_a->last_elem->content;
	min = stack_a->last_elem->content;

	stack_push(stack_a, stack_b);
	if (stack_a->last_elem->content > max)
		max = stack_a->last_elem->content;
	else if (stack_a->last_elem->content < min)
		min = stack_a->last_elem->content;
	stack_push(stack_a, stack_b);

	size = 2;


	i = 0;
	while(stack_a->last_elem != NULL)
	{
		if (stack_a->last_elem->content < min)
		{
			while (stack_b->first_elem->content != min)
				stack_rotate(stack_b);
			if (stack_a->last_elem->content > max)
				max = stack_a->last_elem->content;
			else if (stack_a->last_elem->content < min)
				min = stack_a->last_elem->content;	
			stack_push(stack_a, stack_b);
			size++;
		}
		else if (stack_a->last_elem->content > max)
		{
			while (stack_b->last_elem->content != max)
				stack_rotate(stack_b);
			if (stack_a->last_elem->content > max)
				max = stack_a->last_elem->content;
			else if (stack_a->last_elem->content < min)
				min = stack_a->last_elem->content;	
			stack_push(stack_a, stack_b);
			size++;
		}
		else
		{
			rotate_direction = get_rotation(*stack_b, stack_a->last_elem->content, size);
			while (stack_b->first_elem->content < stack_a->last_elem->content 
				|| stack_b->last_elem->content > stack_a->last_elem->content)
				{
					if (rotate_direction)
						stack_reverse_rotate(stack_b);
					else
						stack_rotate(stack_b);
				}
			stack_push(stack_a, stack_b);
			size++;
		}
		i++;
		//print_stacks(*stack_a, *stack_b);
	} 

	while (max != stack_b->last_elem->content)
	{
		stack_rotate(stack_b);
	}

	while (stack_b->last_elem != 0)
	{
		stack_push(stack_b, stack_a);
	}
}