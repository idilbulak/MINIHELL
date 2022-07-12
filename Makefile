GREEN = \033[32m
BLUE = \033[34m
YELLOW = \e[0;33m
RESET = \033[0m

NAME			=	minishell

NAME_BONUS		=	checker

SRCS_DIR		=	./src/

INCLUDES		=	./inc/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	tokenizer/tokenizer.c tokenizer/tokenlist_utils.c tokenizer/tokenizer_helper.c \
					tokenizer/tokenizer_helper2.c \
					parser/parser.c parser/parser_utils.c parser/parser_checks.c \
					executor/exec.c \
					main.c libft.c
		

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS 			= $(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-lreadline  #-Wall -Wextra -Werror 

.c.o:			
				$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)


$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)MINIHELL$(RESET)"

all:			$(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus

