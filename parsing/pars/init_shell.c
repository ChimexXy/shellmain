#include "../../inc/minishell.h"

char	**copy_env(char **env)
{
	int	i;
	char **new_env;

	i  = 0;
	while(env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while(env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

void ft_init_shell(t_shell *shell, char **env)
{
	shell->env = copy_env(env);
	shell->exit_status = 0;
	shell->cmd = NULL;
}

void	ft_init_cmd(t_shell *shell)
{
	char	*command;
	t_token	*tokens;

	while (1)
	{
		command = readline("minishell$ ");
		if (!command)
		{
			free(command);
			printf("\nexit\n");
			break ;
		}
		add_history(command);
		ft_init_cmd2(shell, command);
	}
	if (command)
		free(command);
}

void	ft_init_cmd2(t_shell *shell, char *command)
{

}
