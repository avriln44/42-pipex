NAME := pipex

CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR		:= ./library/libft
FT_PRINTF_DIR 	:= ./library/ft_printf

LIBFT			:= ${LIBFT_DIR}/libft.a
FT_PRINTF		:= ${FT_PRINTF_DIR}/libftprintf.a

INCLUDE 		:= -I ${LIBFT_DIR} -I ${FT_PRINTF_DIR} -I ./includes/


SRCS			:= 	./srcs/main.c \
					./srcs/utils.c \
					./srcs/build_valid_cmd.c\
				   	./srcs/get_valid_cmd.c \
					./srcs/extract_path.c  \
					./srcs/file_check.c  \
					./srcs/pipex_exec.c \


OBJS				:= ${SRCS:.c=.o}


all: ${LIBFT} ${FT_PRINTF} ${NAME}

%.o:	%.c
	${CC}	${CFLAGS}	-o $@ -c $< ${INCLUDE}

${NAME}:	${OBJS} ${LIBFT} ${FT_PRINTF}
			@cc ${OBJS} ${LIBFT} ${FT_PRINTF} -o ${NAME}


${LIBFT}:
		@$(MAKE) -C ${LIBFT_DIR}

${FT_PRINTF}:
		@$(MAKE) -C ${FT_PRINTF_DIR}

clean:
	rm	-f	$(OBJS)
	@$(MAKE) -C ${LIBFT_DIR} clean
	@$(MAKE) -C ${FT_PRINTF_DIR} clean


fclean:
	rm	-f	${NAME} ${OBJS}
	@$(MAKE) -C ${LIBFT_DIR} fclean
	@$(MAKE) -C ${FT_PRINTF_DIR} fclean

re:    fclean    all

.PHONY:    all    clean    fclean    re
