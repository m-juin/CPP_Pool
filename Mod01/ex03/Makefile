# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 15:23:54 by mjuin             #+#    #+#              #
#    Updated: 2023/02/28 16:25:17 by mjuin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	c++

CFLAGS =	-g -Werror -Wextra -Wall -std=c++98 -I./includes

NAME =	Violence

SRC =	srcs/main.cpp \
		srcs/HumanA.cpp \
		srcs/HumanB.cpp \
		srcs/Weapon.cpp

OBJ =	${SRC:.cpp=.o}

all:	${NAME}

$(NAME): ${OBJ}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJ}
	@printf '\e[1;37m%-6s\e[m' "Compilation complete"

%.o: %.cpp
	@printf "Compiling .cpp to .o \r"
	@${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	@n=1; \
	for file in $(OBJ); do \
		if test -e $$file; then \
			if [ $$n -eq 1 ]; then \
				printf "Cleaning .o files \n"; \
			fi; \
			n=$$((n + 1)); \
			rm $$file; \
		fi \
	done

fclean:	clean
	@n=1; \
	if test -e ${NAME}; then \
		if [ $$n -eq 1 ]; then \
			printf "Cleaning files\n"; \
		fi; \
		n=$$((n + 1)); \
		rm ${NAME}; \
	fi

re:	fclean all

.PHONY:	all clean fclean re 
