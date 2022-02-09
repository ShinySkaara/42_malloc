NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

C_PATH = ./srcs/

O_PATH = ./objs/

H_PATH = ./includes/

SRCS_F = ft_hexdump.c ft_indexof.c ft_isspace.c ft_memcpy.c \
		 ft_memrev.c ft_memset.c ft_numlen.c ft_putchar.c ft_putchar_fd.c \
		 ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		 ft_stralloc.c ft_strcasecmp.c ft_strchr.c \
		 ft_strchrnul.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strjoin.c \
		 ft_strlen.c ft_strlwr.c ft_strncasecmp.c ft_strncmp.c \
		 ft_strncpy.c ft_strrchr.c ft_strrev.c ft_strupr.c ft_tolower.c \
		 ft_toupper.c

OBJS_F = $(SRCS_F:.c=.o)

SRCS = $(addprefix $(C_PATH),$(SRCS_F))
OBJS = $(addprefix $(O_PATH),$(OBJS_F))
INCS = $(addprefix -I, $(H_PATH))

all : $(NAME)

$(NAME) : $(OBJS) ./includes/libft.h
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(O_PATH)%.o: $(C_PATH)%.c
	mkdir -p objs
	$(CC) $(FLAGS) $(INCS) -o $@ -c $<

clean :
	rm -rf $(OBJS)
	rm -rf $(O_PATH)

fclean : clean
	rm -rf $(NAME)

re : fclean all
