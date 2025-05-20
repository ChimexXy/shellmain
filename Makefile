NAME = minishell

# CFLAGS = -Wextra -Wall -Werror 

SRC = utils/count_pipe.c utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c  utils/ft_substr.c utils/ft_strchr.c \
	  parsing/start.c utils/ft_split_cmd.c parsing/redirection.c parsing/envirement.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) header.h 
	$(CC) $(OBJ) -lreadline -fsanitize=address -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all