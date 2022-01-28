#ifndef LIST_H
# define LIST_H

t_list	*list_new(int content);
void	list_add_front(t_stack *stack, t_list *new);
void	list_add_back(t_stack *stack, t_list *new);

#endif