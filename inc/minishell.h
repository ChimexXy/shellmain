#ifndef MINISHELL_H
#define MINISHELL_H

typedef struct s_cmd
{
    char **args;
	struct s_cmd *next;
}   t_cmd;


typedef struct s_shell{
    char **env;
    int exit_status;
    t_cmd *cmd;
}   t_shell;

#endif