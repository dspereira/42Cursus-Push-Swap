#include "push_swap.h"

//gcc push_swap.c list.c stack_mov.c stack_mov_print.c 

// Função de teste
void print_stack(t_stack stack)
{
	while (stack.last_elem != NULL)
	{
		printf("%i\n", stack.last_elem->content);
		stack.last_elem = stack.last_elem->prev;
	}
}

int main(void)
{
	t_stack stack_a;
	t_stack stack_b;

	stack_a.id = STACK_A;
	stack_a.size = 0;
	stack_a.first_elem = 0;
	stack_a.last_elem = 0;

	stack_b.id = STACK_B;
	stack_b.size = 0;
	stack_b.first_elem = 0;
	stack_b.last_elem = 0;

	int arr[10];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;

	create_list(&stack_a, arr, 4);

	print_stack(stack_a);
	printf("\n Stack swap\n");
	stack_swap(&stack_a);
	print_stack(stack_a);

	printf("\n Stack rotate\n");
	stack_rotate(&stack_a);
	print_stack(stack_a);
	
	printf("\n Stack reverse rotate\n");
	stack_reverse_rotate(&stack_a);
	print_stack(stack_a);

	printf("\n Stack push a to b\n");
	stack_push(&stack_a, &stack_b);
	printf("\n Stack A\n");
	print_stack(stack_a);
	printf("\n Stack B\n");
	print_stack(stack_b);

	printf("\n Stack push a to b\n");
	stack_push(&stack_a, &stack_b);
	printf("\n Stack A\n");
	print_stack(stack_a);
	printf("\n Stack B\n");
	print_stack(stack_b);

	printf("\n Stack push a to b\n");
	stack_push(&stack_a, &stack_b);
	printf("\n Stack A\n");
	print_stack(stack_a);
	printf("\n Stack B\n");
	print_stack(stack_b);

	printf("\n Stack push a to b\n");
	stack_push(&stack_a, &stack_b);
	printf("\n Stack A\n");
	print_stack(stack_a);
	printf("\n Stack B\n");
	print_stack(stack_b);

	printf("\n Stack push a to b\n");
	stack_push(&stack_b, &stack_a);
	printf("\n Stack A\n");
	print_stack(stack_a);
	printf("\n Stack B\n");
	print_stack(stack_b);


	return (0);
}