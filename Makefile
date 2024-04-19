NAME = philo

FLAGS = -Wall -Werror -Wextra -g3 -pthread

CC = cc
RM = rm -rf

SRC = test.c \ utils.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS)  -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

