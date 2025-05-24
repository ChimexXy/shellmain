#include "../header.h"

int check_redirection(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
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
	if(!str)
		return 0;
	while(str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int check_command(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|')
	{
		if(str[i] == '|' && str[i + 1] == '|')
			printf("bash: syntax error near unexpected token `||'\n");
		else
			printf("bash: syntax error near unexpected token `|'\n");
		return (0);
	}
	while(str[i])
	{
		if(str[i] == '|' && str[i + 1] == '|')
		{
			printf("invalid token :( \n");
			return (0);
		}	
		i++;
	}
	return (1);
}

int	check_command1(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while(str[i] == ' ' && i >= 0)
		i++;
	if(str[i] == '|')
		return (0);
	return (1);	
}

void check_red_env(t_bash *bash)
{
	int	i;

	i = 0;
	while(i < bash->num_cmd)
	{
		if(check_envirment(bash->s_cmd[i]->command) == 1)
			bash->s_cmd[i]->check_env = 1;
		if(check_redirection(bash->s_cmd[i]->command) == 1)
			bash->s_cmd[i]->check_red = 1;
		i++;
	}
}



void allocate_line(t_bash *bash)
{
    char *command;
    int i;
    int check;
	int check1;

    i = 0;
    command = readline("minishell$ ");
	check = check_command(command);
	check1 = check_command1(command);
    if (!command || check == 0 || check1 == 0)
	{
		free(command);
        return ;
	}
    bash->num_cmd = count_pipes(command);
    bash->s_cmd = malloc(sizeof(t_cmd *) * bash->num_cmd);
	if (!bash->s_cmd )
		return;
    bash->commands = ft_strdup(command);
    bash->args = ft_split(command, '|');
    while (i < bash->num_cmd)
    {
        bash->s_cmd[i] = malloc(sizeof(t_cmd));
		if(!bash->s_cmd[i])
			return ;
        bash->s_cmd[i]->command = ft_strdup(bash->args[i]);
		bash->s_cmd[i]->s_red = NULL;
		bash->s_cmd[i]->s_env = NULL;
		bash->s_cmd[i]->check_env = 0;
		bash->s_cmd[i]->check_red = 0;
        i++;
    }
	bash->s_cmd[i] = NULL;
	if (red_parse(bash) == 0)
	{
		printf("bash: syntax error near unexpected token `newline'\n");
		return ;
	}
    free(command);
}

void command_splited(t_bash *bash)
{
    int i;
    int j;
	char *temp;

	i = 0;
    while (i < bash->num_cmd)
    {
		if (!bash->s_cmd[i]->command)
			return;
        bash->s_cmd[i]->argument = tokenizer(bash->s_cmd[i]->command);
        j = 0;
        while (bash->s_cmd[i]->argument[j])
        {
            if (bash->s_cmd[i]->argument[j])
            {
                temp = remove_quotes(bash->s_cmd[i]->argument[j]);
                if (temp)
                {
                    free(bash->s_cmd[i]->argument[j]);
                    bash->s_cmd[i]->argument[j] = temp;
                }
            }
            j++;
        }
        i++;
    }
}

int main(int ac , char **av, char **env)
{
	t_bash *bash;

	bash = malloc(sizeof(t_bash));
	while(1)
	{	
		allocate_line(bash);
		check_red_env(bash);
		command_splited(bash);
		parse_redirection(bash);
		parse_env(bash);
	
		int i = 0;
		while(i < bash->num_cmd)
		{
       		int j = 0;
        	while (bash->s_cmd[i]->argument[j])
        	{
				if (!bash->s_cmd[i]->argument[j])
					return 0;
           		printf("command: %s\n", bash->s_cmd[i]->argument[j]);
            	j++;
    		}
			i++;
		}
		ft_free(bash);
	}
}