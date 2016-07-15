# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/07/10 07:42:18 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./sources/ft_printf.c ./sources/percent_percent.c ./sources/percent_s.c\
	   ./sources/padding.c

OBJS = $(SRCS:.c=.o)

FLAGS = -g  -Wall #-Wextra -Werror

CC = clang

HEADS = ./includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C ./libft/
	@cp libft/libft.a $(NAME)
	@echo "\033[33mCompiling in .o ...\033[0m"
	#@$(CC) $(FLAGS) -c $(SRCS) -I $(HEADS)
	@echo "\033[33mCreating library ...\033[0m"
	@ar r $(NAME) $(OBJS)
	@echo "\033[33mIndexing library ...\033[0m"
	@ranlib $(NAME)
	@echo "\033[32mLibrary Created !\033[0m"

%.o : %.c $(HEADS)
	$(CC) -c $(FLAG) $< -o $@

clean:
	@echo "\033[31mdeleting all .o ...\033[0m"
	@rm -f $(OBJS)
	@make -s clean -C ./libft/
	@echo "\033[32mThe folder is clean !\033[0m"

fclean:
	@echo "\033[31mDeleting libftprintf.a and all .o ...\033[0m"
	@rm -f $(NAME) $(OBJS)
	@make -s fclean -C ./libft/
	@echo "\033[32mThe folder is clean\033[0m"

bin:
	@clang main.c libftprintf.a
	@echo main.c ok
	@./a.out

re: fclean all

mc: fclean all clean
