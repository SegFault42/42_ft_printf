# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/06/27 23:43:43 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_SRCS = sources_libft/ft_atoi.c sources_libft/ft_atol.c \
			sources_libft/ft_bzero.c sources_libft/ft_count_2d_tab.c \
			sources_libft/ft_count_line_in_file.c sources_libft/ft_crypt.c \
			sources_libft/ft_debug.c sources_libft/ft_decrypt.c \
			sources_libft/ft_isalnum.c sources_libft/ft_isalpha.c \
			sources_libft/ft_isascii.c sources_libft/ft_isdigit.c \
			sources_libft/ft_isprint.c sources_libft/ft_itoa.c \
			sources_libft/ft_lstadd.c sources_libft/ft_lstdel.c \
			sources_libft/ft_lstdelone.c sources_libft/ft_lstiter.c \
			sources_libft/ft_lstmap.c sources_libft/ft_lstmap.c \
			sources_libft/ft_lstnew.c sources_libft/ft_memalloc.c \
			sources_libft/ft_memccpy.c sources_libft/ft_memchr.c \
			sources_libft/ft_memcmp.c sources_libft/ft_memcpy.c \
			sources_libft/ft_memdel.c sources_libft/ft_memmove.c \
			sources_libft/ft_memset.c sources_libft/ft_putchar.c \
			sources_libft/ft_putchar_fd.c sources_libft/ft_putendl.c \
			sources_libft/ft_putendl_fd.c sources_libft/ft_putnbr.c \
			sources_libft/ft_putnbr_fd.c sources_libft/ft_putstr.c \
			sources_libft/ft_putstr_fd.c sources_libft/ft_sqrt.c \
			sources_libft/ft_strcat.c sources_libft/ft_strchr.c \
			sources_libft/ft_strclr.c sources_libft/ft_strcmp.c \
			sources_libft/ft_strcmp_ext.c sources_libft/ft_strcpy.c \
			sources_libft/ft_strdel.c sources_libft/ft_strdup.c \
			sources_libft/ft_strequ.c sources_libft/ft_striter.c \
			sources_libft/ft_striteri.c sources_libft/ft_strjoin.c \
			sources_libft/ft_strlcat.c sources_libft/ft_strlen.c \
			sources_libft/ft_strmap.c sources_libft/ft_strmapi.c \
			sources_libft/ft_strncat.c sources_libft/ft_strncmp.c \
			sources_libft/ft_strncpy.c sources_libft/ft_strnequ.c \
			sources_libft/ft_strnew.c sources_libft/ft_strnstr.c \
			sources_libft/ft_strrchr.c sources_libft/ft_strrev.c \
			sources_libft/ft_strsplit.c sources_libft/ft_strstr.c \
			sources_libft/ft_strsub.c sources_libft/ft_strtrim.c \
			sources_libft/ft_swap.c sources_libft/ft_tab_free.c \
			sources_libft/ft_tab_len.c sources_libft/ft_tolower.c \
			sources_libft/ft_toupper.c sources_libft/get_next_line.c

FT_PRINTF_SRCS = 

OBJS = $(LIBFT_SRCS:.c=.o) $(FT_PRINTF_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = clang

HEADS = ./sources_libft/includes/libft.h \
		./sources_ft_printf/includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[33mCompiling in .o ...\033[0m"
	@$(CC) $(FLAGS) -c $(SRCS) $(FT_PRINTF_SRCS) -I $(HEADS)
	@echo "\033[33mCreating library ...\033[0m"
	@ar rc $(NAME) $(OBJS)
	@echo "\033[33mIndexing library ...\033[0m"
	@ranlib $(NAME)
	@echo "\033[32mLibrary Created !\033[0m"

%.o : %.c $(HEAD)
	$(CC) -c $(FLAG) $< -o $@

mc: fclean all clean

clean:
	@echo "\033[31mdeleting all .o ...\033[0m"
	@rm -f $(OBJS)
	@echo "\033[32mThe folder is clean !\033[0m"

fclean:
	@echo "\033[31mDeleting libft.a and all .o ...\033[0m"
	@rm -f $(NAME) $(OBJS)
	@echo "\033[32mThe folder is clean\033[0m"

re: fclean all
