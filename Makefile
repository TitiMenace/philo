# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschecro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 05:15:52 by tschecro          #+#    #+#              #
#    Updated: 2023/11/30 23:42:40 by tschecro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		= main.c error_management.c philo_utils.c monitor.c fork.c \
				  routine.c checking.c init_philo.c init_data.c
  
SRC_DIR 		= srcs

SRC		=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

INCLUDES_DIR	= includes

INCLUDES_FILES	= 	includes.h\
					philo.h\
					struct.h

INCLUDES		= $(addprefix $(INCLUDES_DIR)/,$(INCLUDES_FILES))

OBJ_DIR = .build

OBJ		= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC) )

NAME	=	philo

CC		=	cc

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) 
			@echo "\033[1;32m\nDone!\033[0m"

$(OBJ_DIR)/%.o 		:	$(SRC_DIR)/%.c $(INCLUDES)
						@printf "\033[0;33m Generating fdf object... %-38.38s \r" $@
						@mkdir -p $(OBJ_DIR)
						@$(CC) -Wall -Wextra -Werror -pthread -g -c -I $(INCLUDES_DIR) $< -o $@

clean	:
			rm -rf $(OBJ_DIR)
			rm -rf $(OBJ_BONUS_DIR)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

bonus	:	all

.PHONY	:	all clean fclean re
