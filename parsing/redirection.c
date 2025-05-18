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

int	check_out_in(t_bash *bash)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while(i < bash->num_cmd)
	{
		while (bash->s_cmd[i].command[j])
		{
			if(bash->s_cmd[i].command[j] == '>')
			{
				bash->s_cmd[i].s_red[x].type = OUTPUT;
				x++;
			}
			else if(bash->s_cmd[i].command[j] == '<')
			{
				bash->s_cmd[i].s_red[x].type = INPUT;
				x++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_hedo_app(t_bash *bash)
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
