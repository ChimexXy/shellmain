#include "../header.h"

void	allocate_line(t_bash *bash)
{
	char *command;

	command = readline("minishell$ ");
	bash->num_cmd = count_pipes(command);
	bash->cmd = malloc(sizeof(t_cmd) * bash->num_cmd);
	if(!bash->cmd)
		return ;
	bash->cmd->command = ft_strdup(command);
	bash->cmd->args = ft_split(command, '|');
	printf
}

int main()
{
	t_bash bash;
	while(1)
	{
		allocate_line(&bash);
	}
}