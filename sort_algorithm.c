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


int search_position_smaller_element(t_stack stack, int dir)
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
		if(get_elem_cont(elem) < cont)
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
void move_elem_big(t_stack *stack_1, t_stack *stack_2, int pos, int dir)
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

void move_elem_smal(t_stack *stack_1, t_stack *stack_2, int pos, int dir)
{
	int end_pos;

	if (dir == FROM_TOP)
		end_pos = 0;
	else 
		end_pos = -1;
	while (pos >= end_pos)
	{
		if (pos == end_pos)
		{
			stack_push(stack_1, stack_2);
			stack_rotate(stack_2);
		}
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


int search_big(t_stack stack, int dir, t_chunk chunk)
{
	t_list *elem;
	int cont;
	int pos;
	int i;
	int flag = 0;

	elem = get_elem(stack, dir);
	//cont = get_elem_cont(elem);
	pos = -1;
	i = 0;	
	while (elem != NULL)
	{
		if (!flag && (get_elem_cont(elem) >= chunk.min && get_elem_cont(elem) <= chunk.max))
		{
			cont = get_elem_cont(elem);
			flag = 1;
			pos = i;
		}
		else if(flag && (get_elem_cont(elem) >= chunk.min && get_elem_cont(elem) <= chunk.max) && get_elem_cont(elem) > cont)
		{
			cont = get_elem_cont(elem);
			pos = i;
		}

		elem = get_next_elem(elem, dir);
		i++;
	}
	return (pos);
}


int search_smal(t_stack stack, int dir, t_chunk chunk)
{
	t_list *elem;
	int cont;
	int pos;
	int i;
	int flag = 0;

	elem = get_elem(stack, dir);
	//cont = get_elem_cont(elem);
	pos = -1;
	i = 0;	
	while (elem != NULL)
	{
		if (!flag && (get_elem_cont(elem) >= chunk.min && get_elem_cont(elem) <= chunk.max))
		{
			cont = get_elem_cont(elem);
			flag = 1;
			pos = i;
		}
		else if(flag && (get_elem_cont(elem) >= chunk.min && get_elem_cont(elem) <= chunk.max) && get_elem_cont(elem) < cont)
		{
			cont = get_elem_cont(elem);
			pos = i;
		}

		elem = get_next_elem(elem, dir);
		i++;
	}
	return (pos);
}


//#################################################################################

void reverse_rotate_stack(t_stack *stack_1, t_chunk chunk)
{
	int i = 0;
	while (stack_1->last_elem->content != chunk.min)
	{
		stack_reverse_rotate(stack_1);
		i++;
	}
	//printf("NUMBER OF ROTATES: %i", i);
}


t_list *get_element(t_stack stack, int pos)
{
	if (pos == TOP)
		return (stack.last_elem);
	else
		return (stack.first_elem);
}

t_list *get_next_element(t_list *elem, int dir)
{
	if (dir == DOWN)
		return (elem->prev);
	else
		return (elem->next);
}

/*
	return: 1 -> The content belongs to chunk 
			0 -> The content not belongs to chunk
*/
int is_part_of_chunk(int cont, t_chunk chunk)
{
	if (cont >= chunk.min && cont <= chunk.max)
		return (1);
	else 
		return (0);
}

/*
	return: Returns the position of the element on the stack counting from the top.

	int *ch: 1 -> content belong to chunk_1 
			 2 -> content belong to chunk_2
*/
int search_content_in_the_chunks(t_stack stack, t_chunk *chunk_1, t_chunk *chunk_2, int *ch)
{
	int i;
	int content;
	t_list *elem;

	elem = get_element(stack, TOP);
	i = 0;	
	while (elem != NULL)
	{
		content = get_elem_cont(elem);
		if (chunk_1 && is_part_of_chunk(content, *chunk_1))
		{
			if (ch)
				*ch = 1;
			return (i);
		}
		else if (chunk_2 && is_part_of_chunk(content, *chunk_2))
		{
			if (ch)
				*ch = 2;
			return (i);
		}
		elem = get_next_element(elem, DOWN);
		i++;
	}
	return (-1);
}

void move_chunk_unsorted_order(t_stack *stack_1, t_stack *stack_2, t_chunk chunk)
{
	int pos;
	int ch = 0;

	pos = 1;
	while (pos >= 0)
	{
		pos = search_content_in_the_chunks(*stack_1, &chunk, 0, 0);
		if(pos >= 0)
			move_element(stack_1, stack_2, pos, FROM_TOP);
	}
}

void move_chunks_unsorted_order(t_stack *stack_1, t_stack *stack_2, t_chunk chunk_1, t_chunk chunk_2)
{
	int ch;
	int pos;

	pos = 1;
	ch = 0;
	while (pos >= 0)
	{
		pos = search_content_in_the_chunks(*stack_1, &chunk_1, &chunk_2, &ch);
		
		if (pos >= 0)
			move_element(stack_1, stack_2, pos, FROM_TOP);
		if (pos >= 0 && ch == 2)
			stack_rotate(stack_2);
	}	
}

void move_chunck_sorted_order(t_stack *stack_1, t_stack *stack_2, t_chunk chunk)
{
	int big_top;
	int big_bot;
	int smal_top;
	int smal_bot;
	int smallest;
	int i = 0;

	while (get_elem(*stack_2, FROM_BOT) != NULL)
	{
		big_top = search_big(*stack_2, FROM_TOP, chunk);
		big_bot = search_big(*stack_2, FROM_BOT, chunk);
		smal_top = search_smal(*stack_2, FROM_TOP, chunk);
		smal_bot = search_smal(*stack_2, FROM_BOT, chunk);

		//if (big_top == -1  || big_bot == -1 || smal_top == -1 || smal_bot == -1)
		//	return ;

	/*
		printf("\n\n--- TESTE ---");
		printf("\nbig_top: %i", big_top);
		printf("\nbig_bot: %i", big_bot);
		printf("\nsmal_top: %i", smal_top);
		printf("\nsmal_bot: %i", smal_bot);
*/
	
		if (big_top > -1  || big_bot > -1 || smal_top > -1 || smal_bot > -1)
		{

			if (big_top == -1)
				big_top = 10000;
			if (big_bot == -1)
				big_bot = 10000;
			if (smal_top == -1)	
				smal_top = 10000;
			if (smal_bot == -1)	
				smal_bot = 10000;

			//printf("\nbig_top: %i, big_bot: %i, smal_top: %i, smal_bot: %i", big_top, big_bot, smal_top, smal_bot);

			if (big_top <= big_bot && big_top <= smal_bot && big_top <= smal_top)
			{
				move_elem_big(stack_2, stack_1, big_top, FROM_TOP);
				//printf("\nbig_top menor que todos");
			}
			else if (big_bot <= big_top && big_bot <= smal_bot && big_bot <= smal_top)
			{
				move_elem_big(stack_2, stack_1, big_bot, FROM_BOT);
				//printf("\nbig_bot menor que todos");
			}
			else if (smal_top <= big_top && smal_top <= smal_bot && smal_top <= big_bot)
			{
				move_elem_smal(stack_2, stack_1, smal_top, FROM_TOP);
				//printf("\nsmal_top menor que todos");
			}
			else 
			{
				move_elem_smal(stack_2, stack_1, smal_bot, FROM_BOT);
				//printf("\nsmal_bot menor que todos");
			}
		}
		else 
			return ;
	}	
}

void stack_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{

	/*
	//para 100
	move_chunck_a_to_b2(stack_a, stack_b, chunk[0], chunk[1]);
	move_chunck_a_to_b(stack_a, stack_b, chunk[2]);
	move_chunck_a_to_b(stack_a, stack_b, chunk[3]);
	move_chunck_a_to_b(stack_a, stack_b, chunk[4]);
	*/

	//para 500

	move_chunks_unsorted_order(stack_a, stack_b, chunk[3], chunk[4]);
	move_chunks_unsorted_order(stack_a, stack_b, chunk[2], chunk[5]);
	move_chunks_unsorted_order(stack_a, stack_b, chunk[1], chunk[6]);
	move_chunks_unsorted_order(stack_a, stack_b, chunk[0], chunk[7]);

	move_chunk_unsorted_order(stack_a, stack_b, chunk[8]);
	//print_stacks(*stack_a, *stack_b);
	move_chunk_unsorted_order(stack_a, stack_b, chunk[9]);
	move_chunk_unsorted_order(stack_a, stack_b, chunk[10]);
	move_chunk_unsorted_order(stack_a, stack_b, chunk[11]);


	// SORT
	move_chunck_sorted_order(stack_a, stack_b, chunk[11]);
	reverse_rotate_stack(stack_a, chunk[11]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[10]);
	reverse_rotate_stack(stack_a, chunk[10]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[9]);
	reverse_rotate_stack(stack_a, chunk[9]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[8]);
	reverse_rotate_stack(stack_a, chunk[8]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[7]);
	reverse_rotate_stack(stack_a, chunk[7]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[6]);
	reverse_rotate_stack(stack_a, chunk[6]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[5]);
	reverse_rotate_stack(stack_a, chunk[5]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[4]);
	reverse_rotate_stack(stack_a, chunk[4]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[3]);
	reverse_rotate_stack(stack_a, chunk[3]);

	move_chunck_sorted_order(stack_a, stack_b, chunk[2]);
	reverse_rotate_stack(stack_a, chunk[2]);
	
	//print_stacks(*stack_a, *stack_b);
	move_chunck_sorted_order(stack_a, stack_b, chunk[1]);
	reverse_rotate_stack(stack_a, chunk[1]);
	//print_stacks(*stack_a, *stack_b);

	move_chunck_sorted_order(stack_a, stack_b, chunk[0]);
	reverse_rotate_stack(stack_a, chunk[0]);
	//print_stacks(*stack_a, *stack_b);
	
}