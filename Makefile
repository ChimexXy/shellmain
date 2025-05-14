NAME = minishell

CFLAGS = -Wextra -Wall -Werror

SRC = utils/count_pipe.c utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c \
	  parsing/start.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) header.h 
	$(CC) $(OBJ) -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all