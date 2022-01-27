#include "../../includes/push_swap.h"
#include "sort_utils.h"

void	sort_three_num(t_stack *stack)
{
	t_list	*top;
	t_list	*bot;
	t_list	*mid;
	int		i;

	i = 0;
	while (i <= 1)
	{
		top = get_elem(*stack, TOP);
		mid = get_next_elem(top, DOWN);
		bot = get_elem(*stack, BOT);
		if (is_bigger(top->content, bot->content))
			stack_rotate(stack);
		else if (is_bigger(top->content, mid->content))
			stack_swap(stack);
		else if (is_bigger(mid->content, bot->content))
			stack_reverse_rotate(stack);
		i++;
	}
}
