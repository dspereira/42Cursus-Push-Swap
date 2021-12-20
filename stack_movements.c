#include "push_swap.h"


void swap_content(t_list *elem1, t_list *elem2)
{
	int content_tmp;

	content_tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = content_tmp;

}

void stack_swap(t_list *last_elem, int stack)
{
	if (!last_elem || !(last_elem->prev))
		return ;
	swap_content(last_elem, last_elem->prev);

	if (stack == STACK_A)
		write(1, "sa", 2);
	else 
		write(1, "sb", 2);
}
