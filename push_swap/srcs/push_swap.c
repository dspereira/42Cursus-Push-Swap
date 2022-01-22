#include "../includes/push_swap.h"

//gcc push_swap.c list.c stack_mov.c stack_mov_print.c sort_algorithm.c get_input_args.c get_input_args_utils.c utils.c get_chunks.c

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




int *array_dup(const int *src, int size)
{
	int *dst;
	int i;

	dst = malloc(size * sizeof(int));
	if (!dst)
		return (0);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return(dst);
}

int *sort_array(const int *src, int size)
{
	int i;	
	int j;
	int buff;
	int *dst;

	dst = array_dup(src, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (dst[j] > dst[j + 1])
			{
				buff = dst[j];
				dst[j] = dst[j + 1];
				dst[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
	return (dst);	
}

int is_sorted(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int have_repeated_numbers(const int *arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}




int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	int n_max;
	int n_min;

	int *num_list;
	int size;
	t_chunk chunk[50];
	int num_chunks;

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

	int *sorted_arr;

	size = get_input_args(argv, argc, &num_list);
	if (size < 0)
	{
		printf("Error\n");
		return (0);
	}
	else if (size == 0)
		return (0);

	sorted_arr = sort_array(num_list, size);
	if (have_repeated_numbers(sorted_arr, size))
	{
		printf("Error\n");
		free(sorted_arr);
		return (0);
	}
		
	if (!is_sorted(num_list, size))
	{
		create_list(&stack_a, num_list, size, &n_max, &n_min);

		if (size == 2)
			sort_two_num(&stack_a);
		else if (size == 3)
			sort_three_num(&stack_a);
		else if (size > 3 && size <= 5)
			sort_five_num(&stack_a, &stack_b);
		else if (size > 5)
		{
			num_chunks = get_chunks(chunk, sorted_arr, size);
			stack_sort(&stack_a, &stack_b, chunk, num_chunks);
		}
	}
	free(sorted_arr);
	return (0);
}
