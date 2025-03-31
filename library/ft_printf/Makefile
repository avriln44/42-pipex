NAME := libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror

SOURCES :=     format_check.c    \
		ft_printf.c      \
		ft_putchar.c     \
		ft_putptr.c      \
		ft_putstr.c      \
		ft_strlen.c    	 \
		ft_putnbr_base.c \


OBJECTS    :=    $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
	ar	rcs	$(NAME)	$(OBJECTS)

%.o:	%.c
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

clean:
	rm	-f	$(OBJECTS)

fclean:	clean
	rm	-f	$(NAME)

re:    fclean    all

.PHONY:    all    clean    fclean    re
