#include "push_swap.h"

//gcc push_swap.c list.c stack_mov.c stack_mov_print.c sort_algorithm.c

// ./a.out $ARG | wc -l
// ./a.out $ARG | ./checker_linux $ARG
// export ARG=$(./get_num 100)


int	ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			mult;

	i = 0;
	num = 0;
	mult = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	return ((int)(num * mult));
}

// Vai buscar os dados dos argumentos de entrada
int get_data(char *src, int *dst)
{
	int i;
	int j;
	int find_num;

	find_num = 1;
	i = 0;
	j = 0; 
	while(src[i] != '\0')
	{
		if(find_num == 1)
		{
			if (src[i] >= '0' && src[i] <= '9')
			{
				dst[j] = atoi(&src[i]);
				j++;
				find_num = 0;
			}	
		}
		else if (!find_num)
		{
			if (src[i] == ' ')
				find_num = 1;
		}
		i++;
	}
	return j;
}

// Função de teste
void print_stack(t_stack stack)
{
	while (stack.last_elem != NULL)
	{
		printf("%i\n", stack.last_elem->content);
		stack.last_elem = stack.last_elem->prev;
	}
}

void sort_array(int *arr, int size)
{
	int i;	
	int j;
	int buff;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				buff = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buff;
			}
			j++;
		}
		i++;
	}	
}

int get_chunks(t_chunk *chunk, int *num_list, int size)
{
	int div;
	int count;
	int num_chunks;

	sort_array(num_list, size);
	if (size > 5 && size < 50)
		num_chunks = 2; 
	else if (size >= 50 && size < 250)
		num_chunks = 5; 
	else if (size >= 250)
		num_chunks = 13; 	
	div = size / num_chunks;
	count = 0;
	while (count < num_chunks)
	{
		chunk[count].max = num_list[(count + 1) * div - 1];
		chunk[count].min = num_list[count * div];
		if (count == num_chunks - 1)
			chunk[count].max = num_list[size - 1];
		count++;
	}
	return (num_chunks);
}

int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	int n_max;
	int n_min;
	int num_list[1000];
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

	size = get_data(argv[1], num_list);

	//printf("\nSIZE OF LIST: %i", size);
	create_list(&stack_a, num_list, size, &n_max, &n_min);
	// Obter os chunks, como a stack já foi criada o array pode ser alterado
	//num_chunks = get_chunks(chunk, num_list, size);
	//stack_sort(&stack_a, &stack_b, chunk, num_chunks);
	//print_stack(stack_a);
	sort_three_num(&stack_a);
	return (0);
}
