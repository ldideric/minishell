# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ldideric <ldideric@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/09 16:30:23 by ldideric      #+#    #+#                  #
#    Updated: 2020/11/09 16:41:58 by ldideric      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME			=	minishell

SRC_PATH		=	src
LIBFT_PATH		=	./$(SRC_PATH)/libft/
PRINTF_PATH		=	./$(SRC_PATH)/printf/
GNL_PATH		=	./$(SRC_PATH)/gnl/

LIBFT_SRC		=	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_atof.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_lstadd_back_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstmap_bonus.c \
					ft_lstnew_bonus.c \
					ft_lstsize_bonus.c \
					ft_ismatch.c \
					ft_strstr.c \
					ft_skipchar.c

PRINTF_SRC		=	ft_printf.c \
					ft_printf_bonus.c \
					ft_flags.c \
					ft_itoa_base.c \
					ft_ultoa_base.c \
					printf_c.c \
					printf_s.c \
					printf_di.c \
					printf_p.c \
					printf_u.c \
					printf_x.c \
					printf_per.c

GNL_SRC			=	get_next_line.c \
					get_next_line_utils.c

LIBFT_SRC_DIR	=	$(LIBFT_SRC:%=$(LIBFT_PATH)%)
PRINTF_SRC_DIR	=	$(PRINTF_SRC:%=$(PRINTF_PATH)%)
GNL_SRC_DIR		=	$(GNL_SRC:%=$(GNL_PATH)%)

LIBFT_OBJ_DIR	=	$(LIBFT_SRC_DIR:.c=.o)
PRINTF_OBJ_DIR	=	$(PRINTF_SRC_DIR:.c=.o)
GNL_OBJ_DIR		=	$(GNL_SRC_DIR:.c=.o)

C_FILES			=	./$(SRC_PATH)/minishell.c \
					$(LIBFT_SRC_DIR) \
					$(PRINTF_SRC_DIR) \
					$(GNL_SRC_DIR)
O_FILES			=	$(C_FILES:.c=.o)

W_FLAGS			=	-Wall -Werror -Wextra
LIB_FLAGS		=	-Iinc
FLAGS			=	$(W_FLAGS) $(LIB_FLAGS)


ifdef DEBUG
FLAGS	+=	-g
endif
ifdef FSAN
FLAGS	+=	-fsanitize=address
endif

#COLOR CODES
#red
R	= \x1b[38;5;196m
#orange
O	= \x1b[38;5;208m
#yellow
Y	= \x1b[38;5;3m
#green
G	= \x1b[38;5;83m
#blue
B	= \x1b[38;5;21m
#purple
P	= \x1b[38;5;129m
#light pink
PI	= \x1b[38;5;219m
#grey
GR	= \x1b[38;5;244m
#reset to white
RES	= \x1b[0m

SUM		= \x1b[38;5;$(X)m
X		= 1

all: $(NAME)

$(NAME):
	@echo "$(P)Compiling Minishell$(O)"
	@gcc $(C_FILES) $(FLAGS) -o $(NAME)
	@echo "gcc $\(FILES).c $(FLAGS) $(EXTRAS) -o $(NAME)"
	@echo "$(G) > Done compiling!$(RES)\n"

clean:
	@echo "$(P)Cleaning files.$(GR)"
	@echo "rm -rf $\(FILES).o"
	@rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)
	@echo "$(G) > Done Cleaning!$(RES)\n"

re: fclean all

norm:
	@echo "$(R)Norminette:$(RES)"
	@norminette $(C_FILES) \
		./inc/*.h Makefile | grep -c "Error" || printf ""
	@echo "$(R)Norminette+:$(RES)"
	@python ~/norminette+/run.py $(C_FILES) \
		./inc/*.h Makefile | grep -c "Error" || printf ""

normall:
	@echo "$(R)Norminette:$(RES)"
	@norminette $(C_FILES) \
		./inc/*.h Makefile
	@echo "$(R)Norminette+:$(RES)"
	@python ~/norminette+/run.py $(C_FILES) \
		./inc/*.h Makefile
