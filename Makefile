HEADER_INC	=	-I./include

LIB_PATH	=	./lib/

LIBFT_PATH	=	$(LIB_PATH)libft

LIBS		=	libft

LIB_INC		=	$(addprefix -I$(LIB_PATH), $(LIBS))

SRC_PATH	=	./src/

SRCS		=	init.c \
				main.c \
				print.c \
				algo.c \
				push.c \
				swap.c \
				quick_sort.c \
				reverse_rotate.c \
				rotate.c \
				stack.c \

OBJ_PATH	=	./bin/

OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

CFLAGS_FSAN	=	-Wall -Werror -Wextra -g3 -fsanitize=address

NAME		=	push_swap


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				$(CC) $(CFLAGS) $(HEADER_INC) $(LIB_INC) -c $< -o $@

$(NAME):		$(OBJS)
				make -C $(LIBFT_PATH)
				$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

all:			$(NAME)

clean:
				rm -rf $(OBJ_PATH)
				make -C $(LIBFT_PATH) fclean

fclean:			clean
				rm -f $(NAME) $(NAME_BONUS)

re: 			fclean all

.PHONY:			all clean fclean re bonus
