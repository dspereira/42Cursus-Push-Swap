#include "push_swap.h"

int compare_last_elem(t_stack *stack)
{
	int n1;
	int n2;

	if (!(stack->last_elem) || !(stack->last_elem->prev))
	{
		printf("\nINVALIDO: STACK %c COM MENOS DE DOIS ELEMENTOS", stack->id);
		return -1;
	}
	n1 = stack->last_elem->content;
	n2 = stack->last_elem->prev->content;
	if (n1 > n2)
		return (1);
	else 
		return (0);
}

int compare_last_first(t_stack *stack)
{
	int last;
	int first;

	if (!(stack->last_elem) || !(stack->first_elem) || (stack->last_elem == stack->first_elem))
	{
		printf("\nINVALIDO: STACK %c COM MENOS DE DOIS ELEMENTOS", stack->id);
		return -1;
	}
	last = stack->last_elem->content;
	first = stack->first_elem->content;
	if (last > first)
		return (1);
	else 
		return (0);
}

void sort_three_num(t_stack *stack, int max, int min)
{
	int first;
	int last;

	first = stack->first_elem->content;
	last = stack->last_elem->content;
	while (first != max && last != first)
	{
		if(compare_last_elem(stack))
			stack_swap(stack);
		else if (compare_last_first(stack))
			stack_reverse_rotate(stack);
		else 
			stack_rotate(stack);	
		first = stack->first_elem->content;
		last = stack->last_elem->content;
	}
}

void print_stack1(t_stack stack)
{
	while (stack.last_elem != NULL)
	{
		printf("%i\n", stack.last_elem->content);
		stack.last_elem = stack.last_elem->prev;
	}
}

void print_stacks(t_stack stack_a, t_stack stack_b)
{
	printf("##### Print Stacks #####\n");
	print_stack1(stack_a);
	printf("-----\n");
	print_stack1(stack_b);
	printf("########################\n");

}


/*
	Criar funções que recebem a stack por parametro e devolvem os valores que quero isso ivita ter comparações muito grandes nos if
*/
void stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	int max;
	int midle;
	int min;
	int count;

	//35 21 10 6 5 3

	stack_push(stack_a, stack_b);
	stack_push(stack_a, stack_b);
	if(!compare_last_elem(stack_b))
		stack_rotate(stack_b);
	max = stack_b->last_elem->content;
	min = stack_b->first_elem->content;

	while (stack_a->last_elem != NULL)
	{
		if (stack_a->last_elem->content < min)
		{
			stack_push(stack_a, stack_b);
			stack_rotate(stack_b);
			min = stack_b->first_elem->content;
		}
		else if (stack_a->last_elem->content > max)
		{
			stack_push(stack_a, stack_b);
			max = stack_b->last_elem->content;
		}
		else
		{
			count = 0;
			while (stack_a->last_elem->content < stack_b->last_elem->content)
			{
				stack_rotate(stack_b);
				count++;
			}
			stack_push(stack_a, stack_b);
			while (count > 0)
			{
				stack_reverse_rotate(stack_b);
				count--;
			}

			/*
			//Criar aqui o código para fazer a ordenação corretamente
			stack_rotate(stack_b);
			stack_push(stack_a, stack_b);
			stack_reverse_rotate(stack_b);
			*/
		}

		//print_stacks(*stack_a, *stack_b);
	}
	
	while (stack_b->last_elem != NULL)
	{
		stack_push(stack_b, stack_a);
	}

	//print_stacks(*stack_a, *stack_b);
}



/*
	stack_push(stack_a, stack_b);
	stack_push(stack_a, stack_b);
	if(!compare_last_elem(stack_b))
		stack_rotate(stack_b);
	max = stack_b->first_elem->content;
	min = stack_b->last_elem->content;

	if (stack_a->last_elem->content < min)
	{
		stack_push(stack_a, stack_b);
		stack_rotate(stack_b);
		min = stack_b->last_elem->content;
	}
	
	// ainda não sei como fazer
	stack_rotate(stack_b);
	stack_push(stack_a, stack_b);
	stack_reverse_rotate(stack_b);

	if (stack_a->last_elem->content > max)
	{
		stack_push(stack_a, stack_b);
		max = stack_b->first_elem->content;
	}

	stack_rotate(stack_b);
	stack_push(stack_a, stack_b);
	stack_reverse_rotate(stack_b);
*/





/*
void stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	int max;
	int midle;
	int min;

	stack_push(stack_a, stack_b);
	stack_push(stack_a, stack_b);
	if(!compare_last_elem(stack_b))
		stack_rotate(stack_b);

	max = stack_b->first_elem->content;
	midle = stack_b->first_elem->next->content;
	min = stack_b->last_elem->content;

	//printf("\n max: %i, midle: %i, max: %i", max, midle, min);

	

	// se o valor for inferior que o minimo tem de fazer este movimento
	// faz push do valor e depois rotate para ficar em último
	stack_push(stack_a, stack_b);
	stack_rotate(stack_b);

	//preciso decobrir o valor do centro
	//se o valor for inferior ao maximo e superior ao meio
	//rodar até ao valor do topo do "b" ser inferior ao valor valor do "a"
	//fazer push e rodar novamente ao contrario  
	stack_rotate(stack_b);
	stack_push(stack_a, stack_b);
	stack_reverse_rotate(stack_b);

	//se se for superior que o maximo então so precisa de push para ficar no topo
	stack_push(stack_a, stack_b);

	//preciso decobrir o valor do centro
	//se o valor for inferior ao maximo e superior ao meio
	//rodar até ao valor do topo do "b" ser inferior ao valor valor do "a"
	//fazer push e rodar novamente ao contrario  
	stack_rotate(stack_b);
	stack_push(stack_a, stack_b);
	stack_reverse_rotate(stack_b);

	//Voltar a colocar tudo na stack "a"
	stack_push(stack_b, stack_a);
	stack_push(stack_b, stack_a);
	stack_push(stack_b, stack_a);
	stack_push(stack_b, stack_a);
	stack_push(stack_b, stack_a);
	stack_push(stack_b, stack_a);

	

	print_stacks(*stack_a, *stack_b);
	
}*/
