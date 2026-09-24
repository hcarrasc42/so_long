# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 12:52:04 by hcarrasc          #+#    #+#              #
#    Updated: 2022/12/22 10:11:28 by hcarrasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
DIR_OBJS		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
LINKS			=	-L . -lmlx -framework OpenGL -framework AppKit

SRCS			=	srcs/map.c									\
					srcs/main.c									\
					srcs/hook.c									\
					srcs/utils.c								\
					srcs/check.c								\
					srcs/sprite.c								\
					srcs/libft/ft_split.c						\
					srcs/libft/ft_strcmp.c						\
					srcs/libft/ft_memset.c						\
					srcs/get_next_line/get_next_line.c			\
					srcs/get_next_line/get_next_line_utils.c	\

OBJS			=	$(SRCS:.c=.o)
PREFIXED	=	$(addprefix $(DIR_OBJS), $(OBJS))

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)/srcs
	@mkdir -p $(DIR_OBJS)/srcs/libft
	@mkdir -p $(DIR_OBJS)/srcs/get_next_line
	@echo "${YELLOW}Compiling with >>${RESET} $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(PREFIXED)
	@$(MAKE) -C ./minilibx
	@cp ./minilibx/libmlx.a .
	@$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $(PREFIXED)
	@echo "\n${GREEN}Mandatory part compiled!${RESET}\n"

all: $(NAME)

clean:
	@$(MAKE) -C ./minilibx clean
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "\n${BLUE}Cleaned!${RESET}\n"

fclean: clean
	@$(RM) libmlx.a
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re print

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
BLUE			=	"\\x1b[34m"
RESET			=	"\\x1b[37m"
ORANGE			=	"\\x1b[38m"
