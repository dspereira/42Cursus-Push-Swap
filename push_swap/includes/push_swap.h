# include <unistd.h>
# include <stdlib.h>

// RETIRAR NO FINAL
#include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

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


/*  list.c  */
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack *stack, t_list *new);
void	ft_lstadd_back(t_stack *stack, t_list *new);
void create_list(t_stack *stack, int *cont, int size);

/*  stack_mov.c  */
void stack_swap(t_stack *stack);
void stack_rotate(t_stack *stack);
void stack_reverse_rotate(t_stack *stack);
void stack_push(t_stack *stack_1, t_stack *stack_2);

/*  stack_mov_print.c  */
void stack_print_mov(char *mov, char stack_id);

// sort algorithm
void	stack_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk, int	num_chunks);
void sort_three_num(t_stack *stack);
void sort_five_num(t_stack *stack_1, t_stack *stack_2);
void sort_two_num(t_stack *stack);
int get_input_args(char **args, int argc, int **arr);


int get_size_matrix(char **m);
void free_matrix(char **m, int size);
long int	atoi_long(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);


/*  get_chunks.c  */
int get_chunks(t_chunk *chunk, int *num_list, int size);

/*  verifications.c  */
int is_longer_than_int(char *str);
int is_range_int(long int nb);
int	is_numeric(char *str);
int is_sorted(int *arr, int size);
int have_repeated_numbers(const int *arr, int size);

/*  sort_array.c  */
int *sort_array(const int *src, int size);


// funções da libft retirar daqui
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);