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

int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	int n_max;
	int n_min;
	int arr[1000];
	int size;

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

	size = get_data(argv[1], arr);

	create_list(&stack_a, arr, size, &n_max, &n_min); 
	stack_sort(&stack_a, &stack_b);


	return (0);
}