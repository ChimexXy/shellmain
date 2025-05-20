#include "../header.h"

// int	count_red(char *str)
// {
// 	int i;
// 	int	red;

// 	i = 0;
// 	red = 0;
// 	while(str[i])
// 	{
// 		if((str[i] == '<' && str[i + 1] == '<')
// 				|| (str[i] == '>' && str[i + 1] == '>'))
// 		{
// 			red++;
// 			i += 2;
// 		}
// 		else if((str[i] == '<') || (str[i] == '>'))
// 		{
// 			red++;
// 			i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (red);
// }

// int	check_out_in(t_bash *bash)
// {
// 	int	i;
// 	int	j;
// 	int	x;

// 	i = 0;
// 	j = 0;
// 	x = 0;
// 	while(i < bash->num_cmd)
// 	{
// 		while (bash->s_cmd[i]->command[j])
// 		{
// 			if(bash->s_cmd[i]->command[j] == '>')
// 			{
// 				bash->s_cmd[i]->s_red[x]->type = OUTPUT;
// 				x++;
// 			}
// 			else if(bash->s_cmd[i]->command[j] == '<')
// 			{
// 				bash->s_cmd[i]->s_red[x]->type = INPUT;
// 				x++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	check_hedo_app(t_bash *bash)
// {
// 	int	i;
// 	int	j;
// 	int	x;

// 	i = 0;
// 	j = 0;
// 	x = 0;
// 	while(i < bash->num_cmd)
// 	{
// 		while (bash->s_cmd[i]->command[j])
// 		{
// 			if((bash->s_cmd[i]->command[j] == '>')
// 				&& (bash->s_cmd[i]->command[j + 1] == '>'))
// 			{
// 				bash->s_cmd[i]->s_red[x]->type = APPEND;
// 				x++;
// 			}
// 			else if((bash->s_cmd[i]->command[j] == '<')
// 				&& (bash->s_cmd[i]->command[j + 1] == '<'))
// 			{
// 				bash->s_cmd[i]->s_red[x]->type = HERE_DOC;
// 				x++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	alloc_red(t_bash *bash, int num_red, int ind)
// {
// 	int	i;

// 	i = 0;
// 	bash->s_cmd[ind]->s_red = malloc(sizeof(t_red *) * (num_red + 1));
// 	if (!bash->s_cmd[ind]->s_red)
// 		return (0);
// 	while(i < num_red)
// 	{
// 		bash->s_cmd[ind]->s_red[i] = malloc(sizeof(t_red));
// 		if(!bash->s_cmd[ind]->s_red[i])
// 			return (0);
// 		bash->s_cmd[ind]->s_red[i]->type = 0;
// 		i++;
// 	}
// 	bash->s_cmd[ind]->s_red[i] = NULL;
// 	return (1);
// }


// {
// 	int	i;
// 	int	j;
// 	int	num_red;

// 	i = 0;
// 	while(i < bash->num_cmd)
// 	{
// 	j = 0;
// 		while(bash->s_cmd[i]->check_red == 0 && i < bash->num_cmd)
// 			i++;
// 		num_red = count_red(bash->s_cmd[i]->command);
// 		if(alloc_red(bash, num_red, i) == 0)
// 			return (0);
// 		check_out_in(bash);
// 		check_hedo_app(bash);
// 		i++;
// 	}
// 	return (1);
// }


int	count_red(char *str)
{
	int i = 0;
	int red = 0;

	while (str[i])
	{
		if ((str[i] == '<' && str[i + 1] == '<') || (str[i] == '>' && str[i + 1] == '>'))
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

void	parse_red_types(t_cmd *cmd)
{
	int i = 0;
	int x = 0;

	while (cmd->command[i])
	{
		if (cmd->command[i] == '>' && cmd->command[i + 1] == '>')
		{
			cmd->s_red[x]->type = APPEND;
			i += 2;
			x++;
		}
		else if (cmd->command[i] == '<' && cmd->command[i + 1] == '<')
		{
			cmd->s_red[x]->type = HERE_DOC;
			i += 2;
			x++;
		}
		else if (cmd->command[i] == '>')
		{
			cmd->s_red[x]->type = OUTPUT;
			i++;
			x++;
		}
		else if (cmd->command[i] == '<')
		{
			cmd->s_red[x]->type = INPUT;
			i++;
			x++;
		}
		else
			i++;
	}
}

int parse_red_files(t_cmd *cmd) {
    int i = 0;
    int x = 0;

    while (cmd->command[i]) {
        if (cmd->command[i] == '>' || cmd->command[i] == '<') {
            // Skip redirection symbols (>>, <<, >, <)
            if ((cmd->command[i] == '>' && cmd->command[i + 1] == '>') ||
                (cmd->command[i] == '<' && cmd->command[i + 1] == '<'))
                i += 2;
            else
                i++;

            // Skip whitespace
            while (cmd->command[i] && (cmd->command[i] == ' ' || cmd->command[i] == '\t'))
                i++;

            // Check if we reached the end
            if (!cmd->command[i]) {
                fprintf(stderr, "Syntax error: no filename after redirection\n");
                return (0);
            }

            int start = i;
            while (cmd->command[i] && cmd->command[i] != ' ' &&
                   cmd->command[i] != '>' && cmd->command[i] != '<' &&
                   cmd->command[i] != '|')
                i++;
            cmd->s_red[x]->file = ft_substr(cmd->command, start, i - start);
            if (!cmd->s_red[x]->file)
                return (0); // malloc failed
			pause();
            x++;
        }
        else
            i++;
    }
    return (1);
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
				parse_red_types(bash->s_cmd[i]);
				parse_red_files(bash->s_cmd[i]);
				
			}
		}
		i++;
	}
	return (1);
}
