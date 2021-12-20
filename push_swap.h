# include <unistd.h>
# include <stdlib.h>

// RETIRAR NO FINAL
#include <stdio.h>

#define STACK_A 0
#define STACK_B 1

typedef struct s_list
{
	int             content;
	struct s_list	*next;
    struct s_list	*prev;
}	t_list;

// list
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void create_list(t_list **first, t_list **last, int *list_elem, int size);

// stack movements
void stack_swap(t_list *last_elem, int stack);