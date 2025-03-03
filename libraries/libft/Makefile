# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 09:30:05 by pchatagn          #+#    #+#              #
#    Updated: 2025/02/27 20:45:40 by pchatagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT = libft.h
CC = gcc
CFLAGS =  -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = ft_atoi \
				ft_atol \
				ft_bzero \
				ft_calloc \
				ft_isalnum \
				ft_isalpha \
				ft_isascii \
				ft_isdigit \
				ft_isprint \
				ft_memchr \
				ft_memcmp \
				ft_memcpy \
				ft_memmove \
				ft_memset \
				ft_strchr \
				ft_strdup \
				ft_strjoin \
				ft_strlcat \
				ft_strlcpy \
				ft_strlen \
				ft_strncmp \
				ft_strcmp \
				ft_strnstr \
				ft_strrchr \
				ft_strtrim \
				ft_substr \
				ft_tolower \
				ft_toupper \
				ft_split \
				ft_itoa \
				ft_strmapi \
				ft_striteri \
				ft_putchar_fd \
				ft_putstr_fd \
				ft_putendl_fd \
				ft_putnbr_fd \
				get_next_line_utils \
				get_next_line \

FILESBONUS = ft_lstnew \
			ft_lstadd_front \
			ft_lstsize \
			ft_lstlast \
			ft_lstadd_back \
			ft_lstdelone \
			ft_lstclear \
			ft_lstiter \
			ft_lstmap \

SRCS = $(FILES:=.c)
SRCSBONUS = $(FILESBONUS:=.c)
OBJS = $(SRCS:.c=.o)
OBJBONUS = $(SRCSBONUS:.c=.o)
SUCCESS = "\033[1;36mSuccessful compilation of LIBFT!\033[0m"

.c.o : ${CC} ${CFLAGS} -c $< -o ${<:.c=.0}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(AR) $(NAME) $(OBJS)
	@echo $(SUCCESS)

bonus: $(OBJBONUS)
	@$(AR) $(NAME) $(OBJBONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJBONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re