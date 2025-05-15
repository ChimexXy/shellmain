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

int check_envirment(char *str)
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

int check_comand(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|')
		return (0);
	while(str[i])
	{
		if(str[i] == '|' && str[i + 1] == '|')
			return (i);
		i++;
	}
	return (i);
}

void check_red_env(t_bash *bash)
{
	int	i;

	i = 0;
	while(i < bash->num_cmd)
	{
		if(check_envirment(bash->s_cmd[i].command) == 1)
			bash->s_cmd[i].check_env = 1;
		if(check_redirection(bash->s_cmd[i].command) == 1)
			bash->s_cmd[i].check_red = 1;
		i++;
	}
}

void allocate_line(t_bash *bash)
{
    char *command;
    int i;
    int check;

    i = 0;
    command = readline("minishell$ ");
	check = check_comand(command);
    bash->s_cmd = malloc(sizeof(t_cmd) * bash->num_cmd);
    if (!command || !bash->s_cmd || check == 0)
        return;
    bash->commands = ft_substr(command, 0, check);
    bash->args = ft_split(command, '|');
    bash->num_cmd = count_pipes(command);
	bash->s_cmd->check_env = 0;
	bash->s_cmd->check_red = 0;

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
	check_red_env(bash);
	// printf("%d\n", bash->s_cmd[1].check_red);
}