#include "../header.h"

int	count_red(char *str)
{
	int i = 0;
	int red = 0;

	while (str[i])
	{
		if ((str[i] == '<' && str[i + 1] == '<') 
			|| (str[i] == '>' && str[i + 1] == '>'))
		{
			red++;
			i += 2;
		}
		else if (str[i] == '<' || str[i] == '>')
		{
			red++;
			i++;
		}
		else
			i++;
	}
	return (red);
}

int	alloc_red(t_bash *bash, int num_red, int ind)
{
	int i = 0;

	bash->s_cmd[ind]->s_red = malloc(sizeof(t_red *) * (num_red + 1));
	if (!bash->s_cmd[ind]->s_red)
		return (0);
	while (i < num_red)
	{
		bash->s_cmd[ind]->s_red[i] = malloc(sizeof(t_red));
		if (!bash->s_cmd[ind]->s_red[i])
			return (0);
		bash->s_cmd[ind]->s_red[i]->type = 0;
		bash->s_cmd[ind]->s_red[i]->file = NULL;
		i++;
	}
	bash->s_cmd[ind]->s_red[i] = NULL;
	return (1);
}

void	parse_red_types(t_bash *bash, int ind)
{
	int i = 0;
	int x = 0;

	while (bash->s_cmd[ind]->command[i])
	{
		if (bash->s_cmd[ind]->command[i] == '>' && bash->s_cmd[ind]->command[i + 1] == '>')
		{
			bash->s_cmd[ind]->s_red[x++]->type = APPEND;
			i += 2;
		}
		else if (bash->s_cmd[ind]->command[i] == '<' && bash->s_cmd[ind]->command[i + 1] == '<')
		{
			bash->s_cmd[ind]->s_red[x++]->type = HERE_DOC;
			i += 2;
		}
		else if (bash->s_cmd[ind]->command[i] == '>')
		{
			bash->s_cmd[ind]->s_red[x++]->type = OUTPUT;
			i++;
		}
		else if (bash->s_cmd[ind]->command[i] == '<')
		{
			bash->s_cmd[ind]->s_red[x++]->type = INPUT;
			i++;
		}
		else
			i++;
	}
}

void	parse_red_files(t_bash *bash, int ind)
{
	int i;
	int x;
	int start;

	i = 0;
	x = 0;
	while (bash->s_cmd[ind]->command[i])
	{
		if (bash->s_cmd[ind]->command[i] == '>' || bash->s_cmd[ind]->command[i] == '<')
		{
			if (bash->s_cmd[ind]->command[i + 1] == '>' || bash->s_cmd[ind]->command[i + 1] == '<')
				i += 2;
			else
				i++;
			while (bash->s_cmd[ind]->command[i] == ' ' || bash->s_cmd[ind]->command[i] == '\t')
				i++;
			start = i;
			while (bash->s_cmd[ind]->command[i] && bash->s_cmd[ind]->command[i] != ' ' && bash->s_cmd[ind]->command[i] != '\t'
				&& bash->s_cmd[ind]->command[i] != '>' && bash->s_cmd[ind]->command[i] != '<')
				i++;
			if (i > start)
				bash->s_cmd[ind]->s_red[x]->file = ft_substr(bash->s_cmd[ind]->command, start, i - start);
			else
				bash->s_cmd[ind]->s_red[x]->file = NULL;
			x++;
		}
		else
			i++;
	}
}



int	parse_redirection(t_bash *bash)
{
	int i;
	int num_red;	

	i = 0;
	while (i < bash->num_cmd)
	{
		if (bash->s_cmd[i]->check_red == 1)
		{
			num_red = count_red(bash->s_cmd[i]->command);
			if (num_red > 0)
			{
				if (alloc_red(bash, num_red, i) == 0)
					return (0);
				parse_red_types(bash, i);
				parse_red_files(bash, i);
			}
		}
		i++;
	}
	return (1);
}
