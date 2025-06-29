#include "./inc/minishell.h"

int main(int ac, char **av, char **env)
{
	t_shell shell;

	(void)ac;
	(void)av;
	ft_init_shell(&shell, env);
}