# include <unistd.h>
# include <stdlib.h>

// RETIRAR NO FINAL
#include <stdio.h>

#define STACK_A 'a'
#define STACK_B 'b'

typedef struct s_list
{
	int             content;
	struct s_list	*next;
    struct s_list	*prev;
}	t_list;


typedef struct s_stack
{
	char id;	
	int size;
	t_list *first_elem;
	t_list *last_elem;
}	t_stack;


// list
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack *stack, t_list *new);
void	ft_lstadd_back(t_stack *stack, t_list *new);
void create_list(t_stack *stack, int *content, int size, int *max, int *min);

// stack movements
void stack_swap(t_stack *stack);
void stack_rotate(t_stack *stack);
void stack_reverse_rotate(t_stack *stack);
void stack_push(t_stack *stack_1, t_stack *stack_2);

// stack print
void stack_print_mov(char *mov, char stack_id);

// sort algorithm
void stack_sort(t_stack *stack_a, t_stack *stack_b);