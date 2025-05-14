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
			return (0);
		i++;
	}
	return (1);
}

void allocate_line(t_bash *bash)
{
    char *command;
    int i;

    i = 0;
    command = readline("minishell$ ");
    if (!command)
        return;

    bash->commands = ft_strdup(command);
    bash->args = ft_split(command, '|');
    bash->num_cmd = count_pipes(command);

    bash->cmd = malloc(sizeof(t_cmd) * bash->num_cmd);
    if (!bash->cmd)
        return;

    while (i < bash->num_cmd)
    {
        bash->cmd[i].command = ft_strdup(bash->args[i]);
        i++;
    }

    free(command);
}


int main()
{
	t_bash bash;
	while(1)
	{
		allocate_line(&bash);
	}
}