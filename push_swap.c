#include "push_swap.h"

// Função de teste
void print_stack(t_list *last_elem)
{
	t_list *tmp; 
	
	tmp = last_elem;
	while (tmp != NULL)
	{
		printf("%i\n", tmp->content);
		tmp = tmp->prev;
	}
}

int main(int args, char **argv)
{
	t_list	*stka_first;
	t_list	*stka_last;
	t_list	*temp;
	t_list	*temp2 = 0;
	
	stka_first = 0;
	stka_last  = 0;

	int arr[10];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;

 	create_list(&stka_first, &stka_last, arr, 4);
	
	printf("\n Stack\n");
	print_stack(stka_last);

	printf("\n Stack rotate\n");
	stack_rotate(&stka_first, &stka_last, STACK_A);
	print_stack(stka_last);
	
	printf("\n Stack swap\n");
	stack_swap(stka_last, STACK_A);
	print_stack(stka_last);

	printf("\n Stack Reverse Rotate\n");
	stack_reverse_rotate(&stka_first, &stka_last, STACK_A);
	print_stack(stka_last);


/*
	temp = stka_first;
	while (temp != NULL)
	{
		printf("content: %i\n", temp->content);
		printf("next   : %p\n", temp->next);
		printf("prev   : %p\n", temp->prev);
		temp = temp->next;
	}

	

	printf("\nInverted list\n");

	temp = stka_first;
	while (temp != NULL)
	{
		printf("content: %i\n", temp->content);
		printf("next   : %p\n", temp->next);
		printf("prev   : %p\n", temp->prev);
		temp = temp->next;
	}*/

	/*
	temp2 = stka_last;
	while (temp2 != NULL)
	{
		printf("content: %i\n", temp2->content);
		printf("next   : %p\n", temp2->next);
		printf("prev   : %p\n", temp2->prev);
		temp2 = temp2->prev;
	}
	*/

	return (0);
	
}