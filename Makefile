SRCS				=	ft_strlen.s \
						ft_write.s \
						ft_read.s \
						ft_strcpy.s \
						# ft_strcmp.s \
						ft_strdup.s


OBJS				= $(SRCS:.s=.o)

NAME				= libasm.a

CC 					= gcc
RM 					= rm -f
CFLAGS				= -Wall -Wextra -Werror #-g -fsanitize=address

AS					= nasm
ASFLAGS				= -f macho64

all:				$(NAME)

$(NAME):			$(OBJS)
					ar -rcs $(NAME) $(OBJS)

test:				all
					$(CC) $(CFLAGS) -c main.c
					$(CC) $(CFLAGS) main.o -L. -lasm -o test

bonus:				all

clean:
					$(RM) $(OBJS) main.o test

fclean:				clean
					$(RM) $(NAME)

re:					fclean all


sc:
					rm -rf *.o *.a */*.o */*.a test

.PHONY:				all clean fclean re bonus sc

#.SILENT:
