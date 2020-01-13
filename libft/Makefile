# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twakrim <taha.wakrim.pro@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 11:02:51 by twakrim           #+#    #+#              #
#    Updated: 2018/10/29 18:50:25 by twakrim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c

OBJC = *.o

all : $(NAME)

$(NAME) :
	gcc -Werror -Wextra -Wall -c $(SRCS)
	ar rc $(NAME) $(OBJC)

clean :
	rm -f $(OBJC)

fclean : clean
	rm -f $(NAME)
	
re : fclean all
