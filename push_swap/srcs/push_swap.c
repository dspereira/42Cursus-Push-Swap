#include "../includes/push_swap.h"

//gcc sort_algorithm/*.c push_swap.c list.c stack_mov.c stack_mov_print.c get_input_args.c get_input_args_utils.c utils.c get_chunks.c input_verifications.c sort_array.c
//gcc sort_algorithm/*.c input_args/*.c push_swap.c list.c stack_mov.c stack_mov_print.c utils.c get_chunks.c sort_array.c


// ./a.out $ARG | wc -l
// ./a.out $ARG | ./checker_linux $ARG
// export ARG=$(./get_num 100)


// Função de teste
void print_stack(t_stack stack)
{
	while (stack.last_elem != NULL)
	{
		printf("%i\n", stack.last_elem->content);
		stack.last_elem = stack.last_elem->prev;
	}
}

t_stack init_stack(char id)
{
	t_stack stack;

	stack.id = id;
	//stack.size = 0;
	stack.first_elem = 0;
	stack.last_elem = 0;
	return stack;
} 

int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	int *num_list;
	int size;
	t_chunk chunk[50];
	int num_chunks;

	int *sorted_arr;


	stack_a = init_stack(STACK_A);
	stack_b = init_stack(STACK_B);

	size = get_input_args(argv, argc, &num_list);
	if (size < 0)
	{
		printf("Error\n");
		return (0);
	}
	else if (size == 0)
		return (0);

	sorted_arr = input_array_sort(num_list, size);
	if (input_check_repeted_num(sorted_arr, size))
	{
		printf("Error\n");
		free(sorted_arr);
		return (0);
	}

	/// TESTE
	/*create_list(&stack_a, num_list, size);
	num_chunks = get_chunks(chunk, sorted_arr, size);
	printf("\n-------chunk 1-------\n");
	printf("\nmax: %i  min: %i", chunk[0].max, chunk[0].min);

	sort_more_five_num(&stack_a, &stack_b, chunk, num_chunks);
	printf("\n-------STACK A-------\n");
	print_stack(stack_a);
	printf("\n-------STACK B-------\n");
	print_stack(stack_b);*/

	
	if (!input_check_is_sort(num_list, size))
	{
		stack_create(&stack_a, num_list, size);
		if (size == 2)
			sort_two_num(&stack_a);
		else if (size == 3)
			sort_three_num(&stack_a);
		else if (size > 3 && size <= 5)
			sort_five_num(&stack_a, &stack_b);
		else if (size > 5)
		{
			num_chunks = get_chunks(chunk, sorted_arr, size);
			sort_many_num(&stack_a, &stack_b, chunk, num_chunks);
			//stack_sort(&stack_a, &stack_b, chunk, num_chunks);

		}
		stack_free(&stack_a);
	}
	
	
	free(sorted_arr);
	

	return (0);
}