#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum x_type{
	// REDIRECTION,
	// ENVIROMENT,	
	// SINGLE_QUOTE, // '
	// DOUBLE_QUOTE, // "
	INPUT, // <
	OUTPUT, // >
	HERE_DOC, // <<
	APPEND, // >>
	DOLLAR_SIGN, // $
}		t_type;

typedef struct x_red{

	char		*file;
	t_type		type;

}			t_red;

typedef struct x_env{

	char 		*key;
	char 		*value;

}			t_env;

typedef struct x_cmd{

	char 		*command;
	char		**argument;
	int			check_red;
	int			check_env;

	t_red 		**s_red;
	t_env 		**s_env;

}			t_cmd;

typedef struct x_bash{

	char		*commands;
	char		**args;
	int 		num_cmd;

	t_cmd 		**s_cmd;

}			t_bash;

int count_pipes(char *line);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char **ft_split(char *str, char c);
int	ft_strcmp(const char *s1,char *s2);
char *ft_substr(char *str, int start, int end);
// int	ft_strchr(char *str, char c);
char	*ft_strchr(char *s, int c);

int	red_parse(t_bash *bash);
int	parse_redirection(t_bash *bash);
int	parse_env(t_bash *bash);
char *remove_quotes(char *str);
char	**tokenizer(char *str);

#endif