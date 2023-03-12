# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyoo <eyoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 14:43:54 by eyoo              #+#    #+#              #
#    Updated: 2023/03/11 20:08:17 by eyoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= c++
RM				= rm -f
CCFLAGS			= -Wall -Wextra -Werror -std=c++98
NAME			= RPN

SRCS			= main.cpp RPN.cpp
OBJS_DIR		= objs

OBJS			= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o:%.cpp
				@mkdir -p $(OBJS_DIR)
				$(CC) $(CCFLAGS) -c $< -o $(<:%.cpp=$(OBJS_DIR)/%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

clean:			
				$(RM) $(OBJS)
				rm -rf $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re test
