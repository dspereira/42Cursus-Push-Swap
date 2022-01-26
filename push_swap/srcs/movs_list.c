#include "../includes/push_swap.h"

int get_number_movs(t_mov *list_movs)
{ 
    int movs;
    int i;

    movs = 0;
    i = 0;
    while(list_movs[i].size >= 0)
    {
        movs += list_movs[i].size;
        i++;
    }
    return (movs);
}

void init_movs_list(t_mov *list_movs)
{
	int i;

	i = 0;
	while (i < MOVS_LIST_SIZE)
	{
		list_movs[i].size = -1;
		i++;
	}
}

void add_mov(t_mov *list_movs, int mov_id, int size, int index)
{
	list_movs[index].size = size;
	list_movs[index].mov_id = mov_id;
}

void exec_mov(int id_mov, t_stack *stack_a, t_stack *stack_b)
{
	t_stack *stack;

	if (id_mov == SA || id_mov == RA || id_mov == RRA )
		stack = stack_a;
	else 
		stack = stack_b;

	if (id_mov == SA || id_mov == SB)
		stack_swap(stack);
	else if (id_mov == RA || id_mov == RB)
		stack_rotate(stack);
	else if (id_mov == RRA || id_mov == RRB)
		stack_reverse_rotate(stack);
	else if (id_mov == PA)
		stack_push(stack_b, stack_a);
	else if (id_mov == PB)
		stack_push(stack_a, stack_b);

}

void exec_movs(t_mov *list_movs, t_stack *stack_1, t_stack *stack_2)
{
	int i;
	int j;

	i = 0;
	while (list_movs[i].size > -1)
	{
		j = 0;
		while(j < list_movs[i].size)
		{
			exec_mov(list_movs[i].mov_id, stack_1, stack_2);
			j++;
		}
		i++;
	}
}