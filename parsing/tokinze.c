#include "../header.h"

int is_redir(char c)
{
	return (c == '>' || c == '<');
}

int count_tokens(char *str)
{
	int i = 0, count = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;

		if (!str[i])
			break;

		// check redirection operators
		if ((str[i] == '>' && str[i+1] == '>') || (str[i] == '<' && str[i+1] == '<'))
		{
			count++;
			i += 2;
		}
		else if (is_redir(str[i]))
		{
			count++;
			i++;
		}
		else
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && !is_redir(str[i]))
			{
				if (str[i] == '\'' || str[i] == '\"')
				{
					char quote = str[i++];
					while (str[i] && str[i] != quote)
						i++;
					if (str[i])
						i++;
				}
				else
					i++;
			}
		}
	}
	return (count);
}

char	**tokenizer(char *str)
{
	int i = 0, start, t = 0;
	if (!str)
		return NULL;
	int nb_tokens = count_tokens(str);
	char **tokens = malloc(sizeof(char *) * (nb_tokens + 1));

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			break;

		if ((str[i] == '>' && str[i+1] == '>') || (str[i] == '<' && str[i+1] == '<'))
		{
			tokens[t++] = ft_substr(str, i, 2);
			i += 2;
		}
		else if (is_redir(str[i]))
		{
			tokens[t++] = ft_substr(str, i, 1);
			i++;
		}
		else
		{
			start = i;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && !is_redir(str[i]))
			{
				if (str[i] == '\'' || str[i] == '\"')
				{
					char quote = str[i++];
					while (str[i] && str[i] != quote)
						i++;
					if (str[i])
						i++;
				}
				else
					i++;
			}
			tokens[t++] = ft_substr(str, start, i - start);
		}
	}
	tokens[t] = NULL;
	return (tokens);
}
