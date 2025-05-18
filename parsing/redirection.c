#include "../header.h"

int	count_red(char *str)
{
	int i;
	int	red;

	i = 0;
	red = 0;
	while(str[i])
	{
		if((str[i] == '<' && str[i + 1] == '<')
				|| (str[i] == '>' && str[i + 1] == '>'))
		{
			red++;
			i += 2;
		}
		else if((str[i] == '<') || (str[i] == '>'))
		{
			red++;
			i++;
		}
		else
			i++;
	}
	return (red);
}

int	check_out_in(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{

	}
}

int	check_hedo_app(char *str)
{

}

void	parse_redirection(t_bash *bash)
{
	int	i;
	int	j;
	int	num_red;

	i = 0;
	j = 0;
	while(i < bash->num_cmd)
	{
		while(bash->s_cmd[i].check_red == 0 && i < bash->num_cmd)
			i++;
		num_red = count_red(bash->s_cmd[i].command);

		
	}
}
