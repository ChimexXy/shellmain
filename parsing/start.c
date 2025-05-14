#include "../header.h"

int check_redirection(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if((str[i] == '<') || (str[i] == '>') 
			|| (str[i] == '<' && str[i + 1] == '<')
				|| (str[i] == '>' && str[i + 1] == '>'))
			return (1);
		i++;
	}
	return (0);
}

int check_equal(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int check_env(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if((str[i] == '<') || (str[i] == '>') 
			|| (str[i] == '<' && str[i + 1] == '<')
				|| (str[i] == '>' && str[i + 1] == '>'))
			return (1);
		i++;
	}
	return (0);
}

void allocate_line(t_bash *bash)
{
    char *command;
    int i;

    i = 0;
    command = readline("minishell$ ");
    bash->s_cmd = malloc(sizeof(t_cmd) * bash->num_cmd);
    if (!command || !bash->s_cmd)
        return;

    bash->commands = ft_strdup(command);
    bash->args = ft_split(command, '|');
    bash->num_cmd = count_pipes(command);
	bash->s_cmd->check_env = -1;
	bash->s_cmd->check_red = -1;

    while (i < bash->num_cmd)
    {
        bash->s_cmd[i].command = ft_strdup(bash->args[i]);
        i++;
    }
    free(command);
}


int main()
{
	t_bash *bash;

	bash = malloc(sizeof(t_bash));
	allocate_line(bash);
	check_red_env();

}