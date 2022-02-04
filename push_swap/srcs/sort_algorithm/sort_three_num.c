#include "../../includes/push_swap.h"
#include "sort_utils.h"

void	sort_three_num(t_stack *stack)
{
	t_lst	*top;
	t_lst	*bot;
	t_lst	*mid;
	int		i;

	i = 0;
	while (i <= 1)
	{
		top = get_elem(*stack, TOP);
		mid = get_next_elem(top, DOWN);
		bot = get_elem(*stack, BOT);
		if (is_bigger(top->content, bot->content))
			stack_rotate(stack, DO_PRINT);
		else if (is_bigger(top->content, mid->content))
			stack_swap(stack, DO_PRINT);
		else if (is_bigger(mid->content, bot->content))
			stack_reverse_rotate(stack, DO_PRINT);
		i++;
	}
}
