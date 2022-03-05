HEADER_INC	=	-I./include

LIBFT_PATH	=	./libft/

SRC_PATH	=	./src/

SRCS		=	main.c \
				init.c \
				validation.c \
				stack.c \
				print.c \
				quick_sort.c \
				push_swap.c \
				a_to_b.c\
				b_to_a.c\
				push.c \
				swap.c \
				reverse_rotate.c \
				rotate.c \

OBJ_PATH	=	./bin/

OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

CHECK_PATH	=	./src_checker/

CHECK_SRCS	=	main.c \
				init.c \
				stack.c \
				print.c \
				validation.c \
				push_swap.c \
				push.c \
				swap.c \
				reverse_rotate.c \
				rotate.c \

CHECK_O_PATH=	$(CHECK_PATH)bin/

CHECK_OBJS	=	$(addprefix $(CHECK_O_PATH), $(CHECK_SRCS:.c=.o))

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

CFLAGS_FSAN	=	-Wall -Werror -Wextra -g3 -fsanitize=address

NAME		=	push_swap

CHECKER		=	checker


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAGS) $(HEADER_INC) -I$(LIBFT_PATH) -c $< -o $@

$(CHECK_O_PATH)%.o: $(CHECK_PATH)%.c
				@mkdir -p $(CHECK_O_PATH)
				@$(CC) $(CFLAGS) $(HEADER_INC) -I$(LIBFT_PATH) -c $< -o $@

$(NAME):		$(OBJS)
				@make -C $(LIBFT_PATH)
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)


$(CHECKER):		$(CHECK_OBJS)
				@$(CC) $(CFLAGS) $(CHECK_OBJS) -L$(LIBFT_PATH) -lft -o $(CHECKER)


all:			$(NAME)

bonus:			re $(CHECKER)

clean:
				@rm -rf $(OBJ_PATH)
				@rm -rf $(CHECK_O_PATH)
				@make -C $(LIBFT_PATH) fclean

fclean:			clean
				@rm -f $(NAME)
				@rm -f $(CHECKER)

re: 			fclean all

.PHONY:			all clean fclean re bonus
