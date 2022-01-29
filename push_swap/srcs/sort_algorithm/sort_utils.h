#ifndef SORT_UTILS_H
# define SORT_UTILS_H

int		is_bigger(int a, int b);
int		is_smaller(int a, int b);
int		get_elem_cont(t_lst *elem);
t_lst	*get_elem(t_stack stack, int pos);
t_lst	*get_next_elem(t_lst *elem, int dir);

#endif