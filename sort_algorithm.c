#include "push_swap.h"

// export ARG=$(./get_num 100)  
// ./a.out $ARG | ./checker_linux $ARG
// ./a.out $ARG | wc -l   

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

// Return Position in stack
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

int search_element_from_bottom(t_stack stack, t_chunk chunk)
{
	int i;
	int content;
	t_list *elem;

	elem = stack.first_elem;
	i = 0;	
	while (elem != NULL)
	{
		content = elem->content;
		if (content >= chunk.min && content <= chunk.max)
			return (i);	
		elem = elem->next;
		i++;
	}
	return (-1);
}


t_list *get_elem(t_stack stack, int dir)
{
	if (dir == FROM_TOP)
		return (stack.last_elem);
	else
		return (stack.first_elem);
}

t_list *get_next_elem(t_list *elem, int dir)
{
	if (dir == FROM_TOP)
		return (elem->prev);
	else
		return (elem->next);
}

int get_elem_cont(t_list *elem)
{
	return (elem->content);
}

// Return position
int search_position_bigger_element(t_stack stack, int dir)
{
	t_list *elem;
	int cont;
	int pos;
	int i;

	elem = get_elem(stack, dir);
	cont = get_elem_cont(elem);
	pos = 0;
	i = 0;	
	while (elem != NULL)
	{
		if(get_elem_cont(elem) > cont)
		{
			cont = get_elem_cont(elem);
			pos = i;
		}

		elem = get_next_elem(elem, dir);
		i++;
	}
	return (pos);
}

// THIS FUNCTION HAVE TO BE CHANGEND WIHT "move_element()
void move_elem(t_stack *stack_1, t_stack *stack_2, int pos, int dir)
{
	int end_pos;

	if (dir == FROM_TOP)
		end_pos = 0;
	else 
		end_pos = -1;
	while (pos >= end_pos)
	{
		if (pos == end_pos)
			stack_push(stack_1, stack_2);
		else
		{
			if (dir == FROM_TOP)
				stack_rotate(stack_1);
			else
				stack_reverse_rotate(stack_1);
		}
		pos--;
	}
}


/*
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
*/

void move_element(t_stack *stack_a, t_stack *stack_b, int pos, int dir)
{
	int end_pos;
	//printf("\n---DIR: %i\n", dir);
	
	if (dir == FROM_TOP)
		end_pos = 0;
	else
		end_pos = -1;

	while (pos >= end_pos)
	{
		if (pos == end_pos)
			stack_push(stack_a, stack_b);
		else
		{
			if (dir == FROM_TOP)
				stack_rotate(stack_a);
			else
				stack_reverse_rotate(stack_a);
		}
		pos--;
	}
}

void move_chunck1(t_stack *stack_a, t_stack *stack_b)
{
	int pos_top;
	int pos_bot;
	
	while (get_elem(*stack_b, FROM_BOT) != NULL)
	{
		pos_top = search_position_bigger_element(*stack_b, FROM_TOP);
		pos_bot = search_position_bigger_element(*stack_b, FROM_BOT);
		if (pos_top <= pos_bot)
			move_elem(stack_b, stack_a, pos_top, FROM_TOP);
		else
			move_elem(stack_b, stack_a, pos_bot, FROM_BOT);
	}			
}

void move_chunck(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	int position;
	static int a = 0;

	position = 1;
	while (position >= 0)
	{
		
		if (a > 1)
		{
			position = search_element_from_bottom(*stack_a, chunk);
			if(position >= 0)
				move_element(stack_a, stack_b, position, FROM_BOT);
		}
		else
		{
			position = search_element_from_top(*stack_a, chunk);
			if(position >= 0)
				move_element(stack_a, stack_b, position, FROM_TOP);
		}
		
		
		/*
		position = search_element_from_top(*stack_a, chunk);
		if(position >= 0)
			move_element(stack_a, stack_b, position, FROM_TOP);
		*/
	}
	a++;		
}

void rotate_stack(t_stack *stack_a, t_chunk chunk)
{
	int i = 0;
	while (stack_a->last_elem->content != chunk.min)
	{
		stack_rotate(stack_a);
		i++;
		
	}
	//printf("NUMBER OF ROTATES: %i", i);
}

void stack_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{


	move_chunck(stack_a, stack_b, chunk[2]);
	//print_stacks(*stack_a, *stack_b);
	move_chunck1(stack_a, stack_b);

	move_chunck(stack_a, stack_b, chunk[1]);
	// rotate stack a
	rotate_stack(stack_a, chunk[2]);
	//print_stacks(*stack_a, *stack_b);
	move_chunck1(stack_a, stack_b);

	move_chunck(stack_a, stack_b, chunk[0]);
	move_chunck1(stack_a, stack_b);

	//print_stacks(*stack_a, *stack_b);
}