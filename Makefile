# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 15:33:20 by kenguyen          #+#    #+#              #
#    Updated: 2018/03/02 18:09:02 by kenguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC		= gcc
FLAGS	= -Wall -Wextra -Werror

SRC_BASE = \
main.c

SRC_DIR	= srcs/
OBJ_DIR	= objs/
INC_DIR	= includes/
LIB_DIR	= libft/

LIBFT_LIB = $(LIB_DIR)libft.a

SRCS	= $(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS	= $(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

C_NO	= "\033[00m"
C_OK	= "\033[35m"
C_GOOD	= "\033[32m"
C_ERROR	= "\033[31m"
C_WARN	= "\033[33m"

SUCCESS	= $(C_GOOD)SUCCESS$(C_NO)
OK		= $(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) \
		-I $(INC_DIR) -I $(LIB_DIR)/$(INC_DIR) \
		$(LIBFT_LIB) $(FLAGS)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIBFT_LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR) -c $< -o $@
	@echo "Linking" [ $< ] $(OK)

cleanlib:
	@make -C $(LIB_DIR) clean

fcleanlib:
	@make -C $(LIB_DIR) fclean

clean: cleanlib
	@rm -rf $(OBJ_DIR)
	@echo "Delete" [ filler/objs ] $(OK)

fclean: fcleanlib
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "Delete" [ filler/objs ] $(OK)
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: all clean fclean re
