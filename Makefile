# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 15:55:39 by pchatagn          #+#    #+#              #
#    Updated: 2025/02/26 15:58:38 by pchatagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFAGS = -Wall -Wextra -Wextra
RM = rm -f
SRCDIR = src
OBJDIR = obj

FILES = 

SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

SUCCESS = "\033[1;35mSuccessful compilation of PIPIEX!\033[0m"
SUCCESS_CLEANING = "\033[1;32mSuccessful cleaning of PIPEX!!\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo $(SUCCESS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2>/dev/null || true  
	@echo $(SUCCESS_CLEANING)

fclean: clean 
	@$(RM) $(NAME)

re: fclean all 

.phony: all clean fclean re