#include "push_swap.h"

// export ARG=$(./get_num 100)  
// ./a.out $ARG | ./checker_linux $ARG
// ./a.out $ARG | wc -l

int	get_elem_cont(t_list *elem)
{
	return (elem->content);
}

t_list	*get_element(t_stack stack, int pos)
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

void	move_element(t_stack *stack_1, t_stack *stack_2, int pos, int dir, int smal)
{
	int	end_pos;
	
	if (dir == FROM_TOP)
		end_pos = 0;
	else
		end_pos = -1;

	while (pos >= end_pos)
	{
		if (pos == end_pos)
		{
			stack_push(stack_1, stack_2);
			if (smal)
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

void	reverse_rotate_stack(t_stack *stack_1, t_chunk chunk)
{
	int	i;

	i = 0;
	while (stack_1->last_elem->content != chunk.min)
	{
		stack_reverse_rotate(stack_1);
		i++;
	}
}

/*
	return: 1 -> The content belongs to chunk 
			0 -> The content not belongs to chunk
*/
int	is_part_of_chunk(int cont, t_chunk chunk)
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
int	search_content_in_the_chunks(t_stack stack, t_chunk *chunk_1, t_chunk *chunk_2, int *ch)
{
	int	i;
	int	content;
	t_list	*elem;

	elem = get_element(stack, TOP);
	i = 0;	
	while (elem != NULL)
	{
		content = get_elem_cont(elem);
		if (chunk_1 && is_part_of_chunk(content, *chunk_1))
		{
			*ch = 1;
			return (i);
		}
		else if (chunk_2 && is_part_of_chunk(content, *chunk_2))
		{
			*ch = 2;
			return (i);
		}
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (-1);
}

void	move_chunks_unsorted_order(t_stack *stack_1, t_stack *stack_2, t_chunk *chunk_1, t_chunk *chunk_2)
{
	int	ch;
	int	pos;

	pos = 1;
	ch = 0;
	while (pos >= 0)
	{
		pos = search_content_in_the_chunks(*stack_1, chunk_1, chunk_2, &ch);
		if (pos >= 0)
			move_element(stack_1, stack_2, pos, FROM_TOP, 0);
		if (pos >= 0 && ch == 2)
			stack_rotate(stack_2);
	}	
}


/*
	IDEIA: receber os arrays e preencher. Nesse caso não necessita de retorno, nem 1º if
*/
void	find_big_and_smal_elem(int cont, int pos, int init, t_elem *big_elem, t_elem *smal_elem)
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

t_elem	verify_best_move(t_elem big_elem, t_elem smal_elem)
{
	if (big_elem.pos <= smal_elem.pos)
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
t_elem	search_element(t_stack stack, t_chunk chunk, int dir)
{
	t_list	*elem;
	t_elem	big_elem;
	t_elem	smal_elem;
	int		init;
	int		i;

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
	t_elem	elem_1;
	t_elem	elem_2;

	elem_1.pos = 1;
	while (elem_1.pos >= 0 || elem_2.pos >= 0)
	{
		elem_1 = search_element(*stack_2, chunk, FROM_TOP);
		elem_2 = search_element(*stack_2, chunk, FROM_BOT);
		if (elem_1.pos <= elem_2.pos && (elem_1.pos >= 0 &&  elem_1.pos >= 0))
		{
			if (elem_1.id == BIGGER)
				move_element(stack_2, stack_1, elem_1.pos, FROM_TOP, 0);
			else 
				move_element(stack_2, stack_1, elem_1.pos, FROM_TOP, 1);
		}
		else if (elem_1.pos >= 0 &&  elem_1.pos >= 0) 
		{
			if (elem_2.id == BIGGER)
				move_element(stack_2, stack_1, elem_2.pos, FROM_BOT, 0);
			else 
				move_element(stack_2, stack_1, elem_2.pos, FROM_BOT, 1);
		}
	}
}

void	stack_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	int	chunks_size = 13;
	int	aux;
	int	i1;
	int	i2;

	aux = (int)(chunks_size * 0.75);
	if (aux % 2 == 0)
		aux--;
	aux = (int)(aux / 2);
	i1 = aux;
	i2 = aux+1;
	while(i2 < chunks_size)
	{
		if (i1 >= 0)
			move_chunks_unsorted_order(stack_a, stack_b, &chunk[i1--], &chunk[i2++]);
		else 
			move_chunks_unsorted_order(stack_a, stack_b, &chunk[i2++], 0);
	}
	i1 = chunks_size - 1;
	while (i1 >= 0)
	{
		move_chunck_sorted_order(stack_a, stack_b, chunk[i1]);
		reverse_rotate_stack(stack_a, chunk[i1--]);
	}
}
