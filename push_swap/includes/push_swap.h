# include <unistd.h>
# include <stdlib.h>

#include "../libft/libft.h"


#define STACK_A 'a'
#define STACK_B 'b'

#define FROM_TOP 1
#define FROM_BOT 0

#define UP 0
#define DOWN 1

#define TOP 1
#define BOT 0

#define BIGGER 1
#define SMALLER 0

#define MAX_INT 2147483647
#define MIN_INT -2147483648

# define FD 1



typedef struct s_lst
{
	int             content;
	struct s_lst	*next;
    struct s_lst	*prev;
}	t_lst;


typedef struct s_stack
{
	char id;	
	t_lst *first_elem;
	t_lst *last_elem;
}	t_stack;

typedef struct s_chunk
{
	int max;
	int min;
}	t_chunk;

typedef struct s_elem
{
	int cont;
	int pos;
	int id;
}	t_elem;


typedef void (*t_func)();

typedef struct s_mov_elm
{
	t_stack	*stack_1;
	t_stack	*stack_2; 
	void	(*func)();
}	t_mov_elm;



/*  stack.c  */
t_stack	stack_init(char id);
void stack_fill(t_stack *stack, int *cont, int size);
void stack_free(t_stack *stack);

/*  stack_mov.c  */
void stack_swap(t_stack *stack);
void stack_rotate(t_stack *stack);
void stack_reverse_rotate(t_stack *stack);
void stack_push(t_stack *stack_1, t_stack *stack_2);

// sort algorithm
void sort_three_num(t_stack *stack);
void sort_five_num(t_stack *stack_1, t_stack *stack_2);
void sort_two_num(t_stack *stack);
void	sort_many_num(t_stack *st_a, t_stack *st_b, t_chunk *ch, int num_ch);

/* get_input_args */
int	get_input_args(char **args, int argc, int **dst);

/*  input_check  */
int input_check_is_sort(int *arr, int size);
int input_check_repeted_num(int *arr, int size);


/*  get_chunks.c  */
int get_chunks(t_chunk *chunk, int *num_list, int size);



/*  sort_array.c  */
int *input_array_sort(const int *src, int size);

/*  push_swap.c  */
void push_swap(int in_size, char **in);


void *oom_guard(void *p);

void	stack_rotate_mult(t_stack *stack, int n);
void	stack_reverse_rotate_mult(t_stack *stack, int n);