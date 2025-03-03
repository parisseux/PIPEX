# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 15:55:39 by pchatagn          #+#    #+#              #
#    Updated: 2025/02/27 20:49:28 by pchatagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBDIR = libraries
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./include -I$(LIBDIR)/libft -I$(LIBDIR)/ft_printf -g

RM = rm -f

SRCDIR = src
OBJDIR = obj

FILES = pipex.c
		
LIBFT = $(LIBDIR)/libft/libft.a
FT_PRINTF = $(LIBDIR)/ft_printf/libftprintf.a

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

SUCCESS = "\033[1;35mSuccessful compilation of PIPEX!\033[0m"
SUCCESS2 = "\033[1;32mSuccessful cleaning of PIPEX!\033[0m"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo $(SUCCESS)

$(LIBFT):
	@make all -C $(LIBDIR)/libft

$(FT_PRINTF):
	@make -C $(LIBDIR)/ft_printf

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

	
clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true  
	@make -C $(LIBDIR)/libft clean      
	@make -C $(LIBDIR)/ft_printf clean 

fclean: clean
	@$(RM) $(NAME) $(BONUSNAME)
	@make -C $(LIBDIR)/libft fclean     
	@make -C $(LIBDIR)/ft_printf fclean
	@echo $(SUCCESS2)

re: fclean all

.PHONY: all clean fclean re bonus