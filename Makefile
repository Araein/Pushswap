NAME 			= push_swap

SRCS_LIST		= main.c wetry.c wetry2.c management1.c management2.c management3.c dealwith3.c dealwith5.c stacked.c ft_split.c utils.c dealwith5func.c doesitfitfunc.c

FOLDER			= srcs

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= header

CC				= gcc 
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				gcc -o ${NAME} ${OBJS}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS} ${OUT}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: 		all fclean clean re
