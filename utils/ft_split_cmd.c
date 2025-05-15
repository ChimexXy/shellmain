#include "../header.h"

int	check_sin_dou(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (i + 1);
		i--;
	}
	return (i);
}

int count_word_cmd(char *str, char c)
{
	int i = 0;
	int j = 0;
	while(str[i] == c)
		i++;
	while(str[i])
	{
		if(str[i] != c && str[i])
			j++;
		if(str[i] == '\'' || str[i] == '\"')
			i = check_sin_dou(str);
		while(str[i] != c && str[i])
			i++;
		while(str[i] == c && str[i])
			i++;
	}
	return j;
}

char **ft_split_cmd(char *str, char c)
{
	int i;
	int cnt;
	int start;
	int len;
	char **tab;

	i = 0;
	cnt = 0;
	len = count_word_cmd(str, c);
	tab = malloc((len + 1) * sizeof(char *));
	while(cnt < len)
	{
		while(str[i] == c && str[i])
			i++;
		start = i;
		while (str[i] != c && str[i])
		{
			if(str[i] == '\'' || str[i] == '\"')
			{
				i = check_sin_dou(str);
				break;
			}
			i++;
		}
		tab[cnt] = ft_substr(str, start, i);
		cnt++;
	}
	tab[cnt] = "\0";
	return(tab);
}

// int main()
// {
// 	int i = count_word_cmd("hello word \" hello lslls kfd\"  fls ", ' ');
// 	char **str = ft_split_cmd("hello word \" hello lslls kfd\"  fls ", ' ');
// 	printf("%d\n", i);
// 	printf("%s\n", str[2]);
// }
