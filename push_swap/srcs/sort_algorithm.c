#include "../includes/push_swap.h"

// export ARG=$(./get_num 100)  
// ./a.out $ARG | ./checker_linux $ARG
// ./a.out $ARG | wc -l

typedef struct s_pos
{
	int pos;
	int dir;
}	t_pos;

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


int get_mov_a_to_b(t_mov *list_mov, t_stack stack, t_chunk *chunk_1, t_chunk *chunk_2)
{
	int	i;
	int cont;
	t_list	*elem;
	
	init_movs_list(list_mov);
	elem = get_element(stack, TOP);
	i = 0;	
	while (elem != NULL)
	{
		cont = get_elem_cont(elem);
		if (is_part_of_chunk(cont, *chunk_1) || is_part_of_chunk(cont, *chunk_2))
		{
			add_mov(list_mov, RA, i, 0);
			add_mov(list_mov, PB, 1, 1);
			if (chunk_2 && is_part_of_chunk(cont, *chunk_1))
				add_mov(list_mov, RB, 1, 2);	
			return (1);
		}
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (0);
}

void	mov_a_to_b(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk_1, t_chunk *chunk_2)
{
	t_mov	list_movs[MOVS_LIST_SIZE];

	while (get_mov_a_to_b(list_movs, *stack_a, chunk_1, chunk_2))
		exec_movs(list_movs, stack_a, stack_b);
}


int is_bigger1(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

int is_smaller1(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}


t_pos get_best_pos(int stack_size, int pos)
{
	t_pos new_pos;

	if (pos == -1 || !stack_size)
		new_pos.pos = -1;
	else if (pos > (int)(stack_size / 2))
	{
		new_pos.pos = stack_size - pos - 1;
		new_pos.dir = FROM_BOT;
	}
	else
	{
		new_pos.pos = pos;
		new_pos.dir = FROM_TOP;
	}
	return (new_pos);
}

t_pos search_elem1(t_stack stack, t_chunk chunk, int (*comp)(int, int))
{
	t_list	*elem;
	t_list	*elem_found;
	int i;
	int pos;

	elem = get_element(stack, TOP);
	elem_found = 0;
	i = 0;
	pos = -1;
	while (elem != NULL)
	{
		if (is_part_of_chunk(get_elem_cont(elem), chunk))
		{
			if (!elem_found)
				elem_found = elem;
			if(comp(get_elem_cont(elem), get_elem_cont(elem_found)))
				elem_found = elem;
			if (elem_found == elem)
				pos = i;
		}
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (get_best_pos(i, pos));
}

void get_elem_mov(t_mov *list_mov, t_pos p, int is_bigger)
{
	if (p.dir == FROM_TOP)
		add_mov(list_mov, RB, p.pos, 0);
	else 
		add_mov(list_mov, RRB, p.pos + 1, 0);
	add_mov(list_mov, PA, 1, 1);
	if (!is_bigger)
		add_mov(list_mov, RA, 1, 2);
}

int get_mov_b_to_a(t_mov *list_mov, t_stack stack, t_chunk chunk)
{
	t_pos p_big;
	t_pos p_smal;

	init_movs_list(list_mov);
	p_big = search_elem1(stack, chunk,  &is_bigger1);
	p_smal = search_elem1(stack, chunk, &is_smaller1);
	if (p_big.pos == -1 || p_smal.pos == -1)
		return (0);
	if (p_big.pos <= p_smal.pos)
		get_elem_mov(list_mov, p_big, 1);
	else
		get_elem_mov(list_mov, p_smal, 0);
	return (1);
}

void	mov_b_to_a(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	t_mov	list_movs[MOVS_LIST_SIZE];


	while (get_mov_b_to_a(list_movs, *stack_b, chunk))
		exec_movs(list_movs, stack_a, stack_b);
}

void	sort_more_five_num(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk, int num_chunks)
{
	t_mov	list_movs[MOVS_LIST_SIZE];
	int	aux;
	int	i1;
	int	i2;
	
	aux = (int)(num_chunks * 0.85);
	if (aux % 2 == 0)
		aux--;
	aux = (int)(aux / 2);
	i1 = aux;
	i2 = aux+1;
	while(i2 < num_chunks)
	{
		if (i1 >= 0)
			mov_a_to_b(stack_a, stack_b, &chunk[i1--], &chunk[i2++]);
		else 
			mov_a_to_b(stack_a, stack_b, &chunk[i2++], 0);
	}
	i1 = num_chunks - 1;
	while (i1 >= 0)
	{
		mov_b_to_a(stack_a, stack_b, chunk[i1]);
		//move_chunck_sorted_order(stack_a, stack_b, chunk[i1]);
		reverse_rotate_stack(stack_a, chunk[i1--]);
	}
}


//#############################################
//SORT 3
/*
	return: 1 -> e1 > e2
			2 -> e2 > e1 
*/
int compare_cont(t_list *e1, t_list *e2)
{
	int n1;
	int n2;
	
	n1 = e1->content;
	n2 = e2->content;
	if (n1 > n2)
		return (1);
	else
		return (0);
}

int is_bigger(t_stack stack, t_list *el)
{
	t_list	*elem;
	int cont;

	elem = get_element(stack, TOP);
	cont = get_elem_cont(elem);
	while (elem != NULL)
	{
		if (get_elem_cont(elem) > get_elem_cont(el))
			return (0);
		elem = get_next_elem(elem, DOWN);
	}
	return (1);
}

int is_smaller(t_stack stack, t_list *el)
{
	t_list	*elem;
	int cont;

	elem = get_element(stack, TOP);
	cont = get_elem_cont(elem);
	while (elem != NULL)
	{
		if (get_elem_cont(elem) < get_elem_cont(el))
			return (0);
		elem = get_next_elem(elem, DOWN);
	}
	return (1);
}

void sort_three_num(t_stack *stack)
{
	t_list *top;
	t_list *bot;
	t_list *mid;
	int i;

	i = 0;
	while(i <= 1)
	{
		top = get_element(*stack, TOP);
		mid = get_next_elem(top, DOWN);
		bot = get_element(*stack, BOT);
		if(compare_cont(top, mid) && !is_bigger(*stack, top))
			stack_swap(stack);
		else if (is_bigger(*stack, top))
			stack_rotate(stack);
		else if (is_smaller(*stack, bot))
			stack_reverse_rotate(stack);
		else if (is_bigger(*stack, mid))
			stack_swap(stack);		
		i++;
	}
}

//######################################
//SORT 5
int get_stack_size(t_stack stack)
{
	t_list	*elem;
	int i;

	i = 0;
	elem = get_element(stack, TOP);
	while (elem != NULL)
	{
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (i);
}

int get_pos_smaller(t_stack stack)
{
	t_list	*elem;
	int cont;
	int pos;
	int i;

	elem = get_element(stack, TOP);
	cont = get_elem_cont(elem);
	pos = 0;
	i = 0;
	while (elem != NULL)
	{
		if (get_elem_cont(elem) < cont)
		{
			cont = get_elem_cont(elem);
			pos = i;
		}
		elem = get_next_elem(elem, DOWN);
		i++;
	}
	return (pos);	
}

void move_smaller_elem(t_stack *stack_1, t_stack *stack_2)
{
	int size;
	int pos;

	size = get_stack_size(*stack_1);
	pos = get_pos_smaller(*stack_1);
	if ((pos * 2) <= size)
	{
		while (pos > 0)
		{
			stack_rotate(stack_1);
			pos--;
		}
		stack_push(stack_1, stack_2);
	}
	else
	{
		while (pos < size)
		{
			stack_reverse_rotate(stack_1);
			pos++;
		}
		stack_push(stack_1, stack_2);
	}
}

void sort_five_num(t_stack *stack_1, t_stack *stack_2)
{
	while (get_stack_size(*stack_1) > 3)
		move_smaller_elem(stack_1, stack_2);
	sort_three_num(stack_1);
	while(get_stack_size(*stack_2) > 0)
		stack_push(stack_2, stack_1);
}

// SORT TWO NUMBERS
void sort_two_num(t_stack *stack)
{
	t_list	*top;
	t_list	*bot;

	top = get_element(*stack, TOP);
	bot = get_element(*stack, BOT);
	if (compare_cont(top, bot))
		stack_swap(stack);
}