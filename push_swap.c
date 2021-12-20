#include "push_swap.h"


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
 	create_list(&stka_first, &stka_last, arr, 2);

	//stack_swap(stka_last, STACK_A);

	temp = stka_first;
	while (temp != NULL)
	{
		printf("content: %i\n", temp->content);
		printf("next   : %p\n", temp->next);
		printf("prev   : %p\n", temp->prev);
		temp = temp->next;
	}

	printf("\nInverted list\n");
	temp2 = stka_last;
	while (temp2 != NULL)
	{
		printf("content: %i\n", temp2->content);
		printf("next   : %p\n", temp2->next);
		printf("prev   : %p\n", temp2->prev);
		temp2 = temp2->prev;
	}
	return (0);
	
}