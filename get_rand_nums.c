#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//gcc get_rand_nums -o get_num
//export ARG=$(./get_num 100)
//echo $ARG

int	ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			mult;

	i = 0;
	num = 0;
	mult = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	return ((int)(num * mult));
}

int is_repeated(int *arr, int num, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == num)
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int arr [1000];
    int i;
    int num;
    int size;

    size = ft_atoi(argv[1]);
    i = 0;
    srand(time(NULL));
    while (i < size)
    {
        num = rand() % 999;
        if ((rand() % 10) % 2 == 0)
            num *= -1;
        if (!is_repeated(arr, num, i+1))
        {
            arr[i] = num;
            if (i < size - 1)
                printf("%i ", arr[i]);
            else 
                printf("%i", arr[i]);
            i++; 
        }
    }
    return (0);
}