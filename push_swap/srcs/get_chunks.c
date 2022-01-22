#include "../includes/push_swap.h"

int get_chunks(t_chunk *chunk, int *num_list, int size)
{
	int div;
	int count;
	int num_chunks;

	if (size > 5 && size < 50)
		num_chunks = 2; 
	else if (size >= 50 && size < 250)
		num_chunks = 5; 
	else if (size >= 250)
		num_chunks = 13; 	
	div = size / num_chunks;
	count = 0;
	while (count < num_chunks)
	{
		chunk[count].max = num_list[(count + 1) * div - 1];
		chunk[count].min = num_list[count * div];
		if (count == num_chunks - 1)
			chunk[count].max = num_list[size - 1];
		count++;
	}
	return (num_chunks);
}