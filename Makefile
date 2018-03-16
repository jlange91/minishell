.PHONY : all clean fclean re

NAME = minishell
HEADER = include/minishell.h
CC = gcc
IFLAGS = -Iinclude
CFLAGS = -g -Wall -Wextra -Werror

SRCS = 	src/main.c							\
		src/perror/ft_perror.c				\
		src/perror/error.c					\
		src/perror/ft_useless_norme.c		\
		src/quote/count1.c					\
		src/quote/count2.c					\
		src/quote/check.c					\
		src/quote/main.c					\
		src/quote/fill.c					\
		src/quote/tools.c					\
		src/builtins/cd.c					\
		src/builtins/cd2.c					\
		src/builtins/echo.c					\
		src/builtins/echo2.c				\
		src/builtins/env.c					\
		src/builtins/env2.c					\
		src/builtins/setenv.c				\
		src/builtins/unsetenv.c				\
		src/builtins/pwd.c					\
		src/replace/ft_replace.c			\
		src/replace/ft_replace_dollar.c		\
		src/replace/ft_replace_line.c		\
		src/exec/ft_exec.c					\
		src/other/charcat.c					\
		src/other/prompt.c					\
		src/other/fill_line.c				\
		src/other/free_tab_2d.c				\
		src/other/tab_2d_len.c				\
		src/other/ft_cp_env.c				\
		src/other/ft_fill_env.c				\
		src/other/ft_display_env.c			\
		src/other/ft_getenv.c				\
		src/other/ft_replace_env.c			\
		src/other/ft_remove_useless_path.c	\
		src/other/ft_replace_str.c			\
		src/other/ft_chdir_error.c			\

OBJS = $(SRCS:.c=.o)

all : $(NAME).a

$(NAME).a : $(OBJS) $(HEADER)
	ar rc $(NAME).a $(OBJS)
	ranlib $(NAME).a
	make -C libft
	$(CC) $(CFLAGS) libft/libft.a $(NAME).a -o $(NAME) 

%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

clean :
	make clean -C libft
	rm -rf $(OBJS)
	rm -f $(NAME).a

fclean :
	make fclean -C libft
	rm -rf $(OBJS)
	rm -f $(NAME).a
	rm -f $(NAME)

re : fclean all
