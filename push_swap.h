# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int             content;
	struct s_list	*next;
    struct s_list	*prev;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void create_list(t_list **first, t_list **last, int *list_elem, int size);