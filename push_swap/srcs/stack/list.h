#ifndef LIST_H
# define LIST_H

t_lst	*list_new(int content);
void	list_add_front(t_stack *stack, t_lst *new);
void	list_add_back(t_stack *stack, t_lst *new);

#endif