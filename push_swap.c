#include "push_swap.h"

//gcc push_swap.c list.c stack_mov.c stack_mov_print.c sort_algorithm.c

// Função de teste
void print_stack(t_stack stack)
{
	while (stack.last_elem != NULL)
	{
		printf("%i\n", stack.last_elem->content);
		stack.last_elem = stack.last_elem->prev;
	}
}

int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	int n_max;
	int n_min;

	n_max = 0;
	n_min = 0;
	stack_a.id = STACK_A;
	stack_a.size = 0;
	stack_a.first_elem = 0;
	stack_a.last_elem = 0;

	stack_b.id = STACK_B;
	stack_b.size = 0;
	stack_b.first_elem = 0;
	stack_b.last_elem = 0;

	int arr[10];
	arr[0] = 10;
	arr[1] = 5;
	arr[2] = 3;
	arr[3] = 6;
	arr[4] = 35;
	arr[5] = 21;


	create_list(&stack_a, arr, 6, &n_max, &n_min);
	print_stack(stack_a);

/*
	stack_sort(&stack_a, &stack_b);

	printf("print das stacks\n");
	print_stack(stack_a);
	printf("----\n");
	print_stack(stack_b);
*/
	return (0);
}