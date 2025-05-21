NAME = minishell

# CFLAGS = -Wextra -Wall -Werror 

SRC = utils/count_pipe.c utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c  utils/ft_substr.c utils/ft_strchr.c \
	  parsing/start.c parsing/sin_dou_quote.c parsing/redirection.c parsing/envirement.c parsing/parsing.c\
	  

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