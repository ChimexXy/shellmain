#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum x_type{
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	INPUT,
	OUTPUT,
	HERE_DOC,
	APPEND,
}		t_type;

typedef struct x_red{

	char		*file;
	int			type;

}			t_red;

typedef struct x_env{

	char 		*key;
	char 		*value;

}			t_env;

typedef struct x_cmd{

	char 		*command;
	// int 		pipe;

	t_red 		*red;

}			t_cmd;

typedef struct x_bash{

	char		*commands;
	char		**args;
	int 		num_cmd;

	t_cmd 		**cmd;
	t_env 		*env;

}			t_bash;

int count_pipes(char *line);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char **ft_split(char *str, char c);

#endif