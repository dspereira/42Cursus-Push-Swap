#include "push_swap.h"

//gcc push_swap.c list.c stack_mov.c stack_mov_print.c sort_algorithm.c

// ./a.out ARG | wc -l
// ./a.out $ARG | ./checker_linux $ARG


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

void get_chunks(t_chunk *chunk, int *num_list, int size)
{
	int i;	
	int j;
	int k;
	int a;
	int div;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (num_list[j] > num_list[j + 1])
			{
				a = num_list[j];
				num_list[j] = num_list[j + 1];
				num_list[j + 1] = a;
			}
			j++;
		}
		i++;
	}

	int teste = 0;
	div = size / 3;

	//printf("\n Valor DIV: %i", div);

	/*
	chunk[0].max = num_list[div - 1];
	chunk[0].min = num_list[0];

	chunk[1].max = num_list[size - 1];
	chunk[1].min = num_list[1 * div];
	*/



	/*
	chunk[0].max = num_list[div - 1];
	chunk[0].min = num_list[0];

	chunk[1].max = num_list[2 * div - 1];
	chunk[1].min = num_list[div];

	chunk[2].max = num_list[3 * div - 1];
	chunk[2].min = num_list[2 * div];

	chunk[3].max = num_list[4 * div - 1];
	chunk[3].min = num_list[3 * div];

	chunk[4].max = num_list[5 * div - 1];
	chunk[4].min = num_list[4 * div];

	chunk[5].max = num_list[6 * div - 1];
	chunk[5].min = num_list[5 * div];

	chunk[6].max = num_list[7 * div - 1];
	chunk[6].min = num_list[6 * div];

	chunk[7].max = num_list[8 * div - 1];
	chunk[7].min = num_list[7 * div];

	chunk[8].max = num_list[9 * div - 1];
	chunk[8].min = num_list[8 * div];

	chunk[9].max = num_list[size - 1];
	chunk[9].min = num_list[9 * div];
	*/


/*
	printf("\nLISTA VALORES\n");
	while (teste < size)
	{
		printf("%i ", num_list[teste]);
		teste++;
	}
	printf("\n***************");

	printf("\n Valor DIV: %i", div);
*/

	//printf("\n Valor DIV: %i", div);	
	
	chunk[0].max = num_list[div - 1];
	chunk[0].min = num_list[0];

	chunk[1].max = num_list[2 * div - 1];
	chunk[1].min = num_list[div];

	chunk[2].max = num_list[size - 1];
	chunk[2].min = num_list[2 * div];
	

	//printf("\n\nchunk0 - min: %i  max: %i", chunk[0].min, chunk[0].max);
	//printf("\nchunk1 - min: %i  max: %i", chunk[1].min, chunk[1].max);
	//printf("\nchunk2 - min: %i  max: %i\n", chunk[2].min, chunk[2].max);


	/*
	chunk[0].max = num_list[div - 1];
	chunk[0].min = num_list[0];

	chunk[1].max = num_list[2 * div - 1];
	chunk[1].min = num_list[div];

	chunk[2].max = num_list[3 * div - 1];
	chunk[2].min = num_list[2 * div];

	chunk[3].max = num_list[size - 1];
	chunk[3].min = num_list[3 * div];
	*/
	
/*
	printf("\n\nchunk0 - min: %i  max: %i", chunk[0].min, chunk[0].max);
	printf("\nchunk1 - min: %i  max: %i", chunk[1].min, chunk[1].max);
	printf("\nchunk2 - min: %i  max: %i", chunk[2].min, chunk[2].max);
	printf("\nchunk3 - min: %i  max: %i", chunk[3].min, chunk[3].max);
*/

/*
	//TESTE APENAS
	k = 0;
	while (k < size)
	{
		printf("%i ", num_list[k]);
		k++;
	}
	printf("\n\nchunk0 - min: %i  max: %i", chunk[0].min, chunk[0].max);
	printf("\nchunk1 - min: %i  max: %i", chunk[1].min, chunk[1].max);
*/	
	//printf("\n\nchunk0 - min: %i  max: %i", chunk[0].min, chunk[0].max);
	//printf("\nchunk1 - min: %i  max: %i", chunk[1].min, chunk[1].max);
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
	create_list(&stack_a, num_list, size, &n_max, &n_min);
	// Obter os chunks, como a stack já foi criada o array pode ser alterado
	get_chunks(chunk, num_list, size);
	stack_sort(&stack_a, &stack_b, chunk);
	//print_stack(stack_a);
	return (0);
}

/*
394 681 134 44 342 309 952 650 165 177
*/