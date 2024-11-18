NAME			= push_swap
CHECKER_NAME	= checker

PUSH_SWAP		= $(wildcard srcs/push_swap/*.c)
INPUT_ARGS		= $(wildcard srcs/input_args/*.c)
GET_CHUNKS		= $(wildcard srcs/get_chunks/*.c)
STACK			= $(wildcard srcs/stack/*.c)
SORT_ALG		= $(wildcard srcs/sort_algorithm/*.c)
UTILS			= $(wildcard srcs/utils/*.c)
CHECKER			= $(wildcard checker_src/*.c)
LIBFT			= libft/libft.a

SRCS		= $(PUSH_SWAP) \
			  $(INPUT_ARGS) \
			  $(GET_CHUNKS) \
			  $(STACK) \
			  $(SORT_ALG) \
			  $(UTILS)

			  				
OBJS		= $(SRCS:.c=.o)

CHECKER_SRC		= $(CHECKER) \
				  $(INPUT_ARGS) \
				  $(UTILS) \
				  $(STACK)

CHECKER_OBJS	= $(CHECKER_SRC:.c=.o)

CC			= gcc 
CFLAGS		=  -Wall -Wextra -Werror -I./includes
RM			= rm -f

MAKE_LIBFT		= make bonus -C libft/
CLEAN_LIBFT		= make clean -C libft/
FCLEAN_LIBFT	= make fclean -C libft/

all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE_LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) 

checker: $(OBJS) $(CHECKER_OBJS) 
	$(MAKE_LIBFT)
	$(CC) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER_NAME) 

clean:
	$(CLEAN_LIBFT)
	$(RM) $(OBJS) $(CHECKER_OBJS)
	

fclean: clean
	$(FCLEAN_LIBFT)
	$(RM) $(NAME) $(CHECKER_NAME)

re:	fclean all checker