ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc

FLAGS = -Wall -Wextra -Werror

C_PATH = ./srcs/

O_PATH = ./objs/

H_PATH = ./includes/

SRCS_F = calloc.c free.c malloc.c mlc_fuse_node.c mlc_split_node.c \
		 mlc_start.c mlc_verify_ptr.c realloc.c show_alloc_mem.c 

OBJS_F = $(SRCS_F:.c=.o)

SRCS = $(addprefix $(C_PATH),$(SRCS_F))
OBJS = $(addprefix $(O_PATH),$(OBJS_F))
INCS = $(addprefix -I, $(H_PATH))

all : $(NAME)

$(NAME) : $(OBJS) ./libft/includes/libft.h ./includes/malloc.h
	make -C libft
	$(CC) -shared $(FLAGS) $(OBJS) -L libft -lft -o $(NAME)
	ln -s $(NAME) libft_malloc.so

$(O_PATH)%.o: $(C_PATH)%.c
	mkdir -p objs
	$(CC) $(FLAGS) $(INCS) -I libft/includes -o $@ -c $<

clean :
	rm -rf $(OBJS)
	rm -rf $(O_PATH)
	rm -rf libft_malloc.so

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all
