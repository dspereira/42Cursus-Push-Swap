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
		ch: 1 -> the number belong to chunk_1 
			2 -> the number belong to chunk_2
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

void move_chunks_unsorted_order(t_stack *stack_1, t_stack *stack_2, t_chunk *chunk_1, t_chunk *chunk_2)
{
	int ch;
	int pos;

	pos = 1;
	ch = 0;
	while (pos >= 0)
	{
		pos = search_content_in_the_chunks(*stack_1, chunk_1, chunk_2, &ch);
		if (pos >= 0)
			move_element(stack_1, stack_2, pos, FROM_TOP);
		if (pos >= 0 && ch == 2)
			stack_rotate(stack_2);
	}	
}


/*
	IDEIA: receber os arrays e preencher. Nesse caso não necessita de retorno, nem 1º if
*/
void find_big_and_smal_elem(int cont, int pos, int init, t_elem *big_elem, t_elem *smal_elem)
{
	if (init)
	{
		big_elem->cont = cont;
		big_elem->pos = pos;
		smal_elem->cont = cont;
		smal_elem->pos = pos;
	}
	else if (cont > big_elem->cont)
	{
		big_elem->cont = cont;
		big_elem->pos = pos;
	}
	else if (cont < smal_elem->cont)
	{
		smal_elem->cont = cont;
		smal_elem->pos = pos;
	}
}

t_elem verify_best_move(t_elem big_elem, t_elem smal_elem)
{
	if(big_elem.pos <= smal_elem.pos)
		return (big_elem);
	else
		return(smal_elem);
}

/*
		 return: (= -1) -> don't find element
				 (>= 0) -> position of found element 
	big_or_smal: (= 1) -> the biggest element was found
				 (= 0) -> the smallest element was found
*/
t_elem search_element(t_stack stack, t_chunk chunk, int dir)
{
	t_list *elem;
	t_elem big_elem;
	t_elem smal_elem;
	int init;
	int i;

	i = 0;	
	init = 1;
	big_elem.id = BIGGER;
	big_elem.pos = -1;
	smal_elem.id = SMALLER;
	smal_elem.pos = -1;
	elem = get_element(stack, dir);
	while (elem != NULL)
	{
		if (is_part_of_chunk(get_elem_cont(elem), chunk))
		{
			find_big_and_smal_elem(get_elem_cont(elem), i, init, &big_elem, &smal_elem);
			if (init)
				init = 0;
		}
		elem = get_next_elem(elem, dir);
		i++;
	}
	return (verify_best_move(big_elem, smal_elem));
}

void move_chunck_sorted_order(t_stack *stack_1, t_stack *stack_2, t_chunk chunk)
{
	t_elem elem_1;
	t_elem elem_2;

	elem_1.pos = 1;
	while (elem_1.pos >= 0 || elem_2.pos >= 0)
	{
		elem_1 = search_element(*stack_2, chunk, FROM_TOP);
		elem_2 = search_element(*stack_2, chunk, FROM_BOT);
		if (elem_1.pos <= elem_2.pos && (elem_1.pos >= 0 &&  elem_1.pos >= 0))
		{
			if (elem_1.id == BIGGER)
				move_elem_big(stack_2, stack_1, elem_1.pos, FROM_TOP);
			else 
				move_elem_smal(stack_2, stack_1, elem_1.pos, FROM_TOP);
		}
		else if (elem_1.pos >= 0 &&  elem_1.pos >= 0) 
		{
			if (elem_2.id == BIGGER)
				move_elem_big(stack_2, stack_1, elem_2.pos, FROM_BOT);
			else 
				move_elem_smal(stack_2, stack_1, elem_2.pos, FROM_BOT);
		}
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

/*
	move_chunks_unsorted_order(stack_a, stack_b, chunk[3], chunk[4]);
	move_chunks_unsorted_order(stack_a, stack_b, chunk[2], chunk[5]);
	move_chunks_unsorted_order(stack_a, stack_b, chunk[1], chunk[6]);
	move_chunks_unsorted_order(stack_a, stack_b, chunk[0], chunk[7]);

	move_chunk_unsorted_order(stack_a, stack_b, chunk[8]);
	//print_stacks(*stack_a, *stack_b);
	move_chunk_unsorted_order(stack_a, stack_b, chunk[9]);
	move_chunk_unsorted_order(stack_a, stack_b, chunk[10]);
	move_chunk_unsorted_order(stack_a, stack_b, chunk[11]);
*/

	move_chunks_unsorted_order(stack_a, stack_b, &chunk[4], &chunk[5]);
	move_chunks_unsorted_order(stack_a, stack_b, &chunk[3], &chunk[6]);
	move_chunks_unsorted_order(stack_a, stack_b, &chunk[2], &chunk[7]);
	move_chunks_unsorted_order(stack_a, stack_b, &chunk[1], &chunk[8]);
	move_chunks_unsorted_order(stack_a, stack_b, &chunk[0], &chunk[9]);
	move_chunks_unsorted_order(stack_a, stack_b, &chunk[10], 0);
	move_chunks_unsorted_order(stack_a, stack_b, &chunk[11], 0);
	move_chunks_unsorted_order(stack_a, stack_b, &chunk[12], 0);

	// SORT

	move_chunck_sorted_order(stack_a, stack_b, chunk[12]);
	reverse_rotate_stack(stack_a, chunk[12]);

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