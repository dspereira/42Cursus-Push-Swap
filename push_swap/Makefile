NAME		= push_swap

PUSH_SWAP		= $(wildcard srcs/push_swap/*.c)
INPUT_ARGS		= $(wildcard srcs/input_args/*.c)
GET_CHUNKS		= $(wildcard srcs/get_chunks/*.c)
STACK			= $(wildcard srcs/stack/*.c)
SORT_ALG		= $(wildcard srcs/sort_algorithm/*.c)
LIBFT			= libft/libft.a

SRCS		= $(PUSH_SWAP) \
			  $(INPUT_ARGS) \
			  $(GET_CHUNKS) \
			  $(STACK) \
			  $(SORT_ALG) \

			  				
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./includes
RM			= rm -f

MAKE_LIBFT		= make -C libft/
CLEAN_LIBFT		= make clean -C libft/
FCLEAN_LIBFT	= make fclean -C libft/

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE_LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) 

clean:
	$(CLEAN_LIBFT)
	$(RM) $(OBJS) $(BONUS_OBJS)
	

fclean: clean
	$(FCLEAN_LIBFT)
	$(RM) $(NAME)

re:	fclean all
