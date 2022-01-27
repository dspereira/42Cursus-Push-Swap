#ifndef SORT_UTILS_H
# define SORT_UTILS_H

int		is_bigger(int a, int b);
int		is_smaller(int a, int b);
int		get_elem_cont(t_list *elem);
t_list	*get_elem(t_stack stack, int pos);
t_list	*get_next_elem(t_list *elem, int dir);

#endif