#include <stdio.h>
#include "../includes/push_swap.h"
#include "get_next_line.h"

#define STD_IN_FD 0
#define STD_OUT_FD 1

/*
Receber o standard input e colocar em uma lista da libft e fazer print da mesma pela ordem recebida
Criar ficheiro get_moves.c e get_list_num.c

- Ler parametros de entrada e colocar numa lista. Ler standard input e colocar a stack A.
- ler os movimentos um a um e aplicar à lista usado os movimentos já criados para o push_swap.
- no final verificar se a lista está sorted e se a stack B está vazia

*/

void free_moves_list(t_list **lst)
{
	ft_lstclear(lst, &free);
}

int is_mov_valid(char *mov)
{
	int len;

	len = ft_strlen(mov);
	if (!ft_strncmp("ra\n", mov, len) || !ft_strncmp("rb\n", mov, len)
		|| !ft_strncmp("sa\n", mov, len) || !ft_strncmp("sb\n", mov, len)
		|| !ft_strncmp("pa\n", mov, len) || !ft_strncmp("pb\n", mov, len)
		|| !ft_strncmp("rra\n", mov, len) || !ft_strncmp("rrb\n", mov, len))
	{
		return (1);
	}
	return (0);
}

int has_repeted_num(int *input, int size)
{
	int *sorted_arr;
	int has_repeted;

	sorted_arr = input_array_sort(input, size);	
	has_repeted = input_check_repeted_num(sorted_arr, size);
	free(sorted_arr);
	return (has_repeted);
}

t_list *get_moves_list(void)
{
	t_list *lst;
	t_list *new;
	char *line;

	lst = 0;
	line = get_next_line(STD_IN_FD);
	while (line)
	{
		if (is_mov_valid(line))
		{
			new = oom_guard(ft_lstnew(line));
			ft_lstadd_back(&lst, new);
			line = get_next_line(STD_IN_FD);
		}
		else 
		{
			free_moves_list(&lst);
			lst = 0;
			break;
		}

	}
	return (lst);
}

int main(int argc, char **argv)
{
	int *input;
	t_list *lst;
	int size;

	size = get_input_args(argv, argc, &input);
	if (size < 0 || has_repeted_num(input, size))
	{
		ft_putstr_fd("Error\n", STD_OUT_FD);
		if (size > 0)
			free(input);
		return (0);
	}
	else if (size == 0)
		return (0);
	lst = get_moves_list();
	if (!lst)
	{
		ft_putstr_fd("Error\n", STD_OUT_FD);
		return (0);
	}


	while (lst)
	{
		printf("->%s", (char*)lst->content);

		lst = lst->next;
	}

	free(input);
	free_moves_list(&lst);
	


	return (0);
}

  /*
	char *line;

	printf("\nHello World\n");

	line = get_next_line(0);
		if(line)
			printf("%s", line);
	while (line)
	{
		line = get_next_line(0);
		if(line)
			printf("%s", line);
		free(line);
	}

	free(line);
	*/