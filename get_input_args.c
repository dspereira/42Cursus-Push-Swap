
#include "push_swap.h"
# include <unistd.h>
# include <stdlib.h>


//############################################################
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_size;

	if (!s)
		return (0);
	s_size = ft_strlen(s);
	if (start >= s_size)
		len = 0;
	else if (len > s_size - start)
		len = s_size - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


static size_t	get_size(char const *s, char c)
{
	size_t	size;
	int		flag;

	flag = 0;
	size = 0;
	while (*s != '\0')
	{
		if (*s != c && !flag)
		{
			size++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (size + 1);
}

char	*get_str(char const *s, char c, size_t offset)
{
	size_t	init;

	init = offset;
	while (s[offset] != c && s[offset] != '\0')
		offset++;
	return (ft_substr(s, init, (offset - init)));
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	arr = malloc(get_size(s, c) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			arr[j] = get_str(s, c, i);
			i += ft_strlen(arr[j]) - 1;
			j++;
		}
		i++;
	}
	arr[j] = 0;
	return (arr);
}

//##############################################

long int	atoi_long(char *str)
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
	return ((num * mult));
}

void free_matrix(char **m, int size)
{
    int i;
    
    i = 0;
    while (i < size)
    {
        free(m[i]);
        i++;
    }
    free(m);
}

/*
 *    return: 1 -> conversion sucess
 *            0 -> conversion error
 */
int	convert_number(char *src, int *dst)
{
    long int num;

    if(ft_strlen(src) > 11)
        return (0);
    num = atoi_long(src);
    if (num < MIN_INT || num > MAX_INT)
        return (0);
    *dst = (int)num; 
    return (1);
}

int is_numeric(char *arr)
{
    int i = 0;

    while (arr[i] != '\0')
    {
        if (i == 0 && (arr[i] == '-' || arr[i] == '+'))
        {
            i++;
            if (ft_strlen(arr) > 1)
                continue;
            else 
                return (0);
        }
        if ((arr[i] < '0' || arr[i] > '9')) 
            return (0);
        i++;
    }

    return (1);
}

int get_size_matrix(char **m)
{
    int i;

    if (!m)
        return (0);
    i = 0;
    while (m[i])
        i++;
    return (i);
}

int *get_int_arr(char **m, int size)
{
    int *arr;
    int i;

    arr = malloc(size * sizeof(int));
    if (!arr)
        return (0);
    i = 0;
    while (i < size)
    {
        if(!is_numeric(m[i]) || !convert_number(m[i], &arr[i]))
        {
            free(arr);
            return (0);
        }
        i++;
    }
    return (arr);
}

/*
 *   return size of dst array
 */
int parse_strings_to_array(char **src, int size, int **dst)
{
    char **m;
    int done_split;

    done_split = 0;
    if (size == 1)
    {
       m = ft_split(*src, ' ');
       size = get_size_matrix(m);
       done_split = 1;
    }
    else 
        m = src;
    *dst = get_int_arr(m, size);
    if (done_split)
        free_matrix(m, size);
    if (*dst)
        return (size);
    return (0);
}

/*
 *   return: >0 -> Number of parameters
 *            0 -> No parameters are specified
 *           -1 -> Error
 */
int get_input_args(char **args, int argc, int **dst)
{
    int size;

    if (argc < 2)
        return (0);
    size = parse_strings_to_array((args + 1), (argc - 1), dst);
    if (size)
        return (size);
    return (-1);
}
