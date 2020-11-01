NAME = ft_ls

FLAGS = -Wall -Wextra -Werror -MMD -MP -g

CC = gcc

DIR = src

INC = -I inc

SRC = help_print.c \
		main.c \
		init.c \
		exit.c \
		heap_1.c heap_2.c \
		list.c stack.c \
		work.c \
		free.c \
		sort.c \
		print.c

SRCS = $(addprefix $(DIR)/,$(SRC))
OBJS = $(addprefix $(DIR)/,$(SRC:.c=.o))
DEPS = $(addprefix $(DIR)/,$(patsubst %.c,%.d,$(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $@ $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@ $(INC)

-include $(DEPS)

clean:
		rm -f $(OBJS) $(DEPS)

fclean: clean
		rm -f $(NAME)

re: fclean all