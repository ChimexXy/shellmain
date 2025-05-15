#include "../header.h"

int count_word(char *str, char c)
{
	int i = 0;
	int j = 0;
	while(str[i] == c)
		i++;
	while(str[i])
	{
		if(str[i] != c && str[i])
			j++;
		while(str[i] != c && str[i])
			i++;
		while(str[i] == c && str[i])
			i++;
	}
	return j;
}

char **ft_split(char *str, char c)
{
	int i;
	int cnt;
	int start;
	int len;
	char **tab;

	i = 0;
	cnt = 0;
	len = count_word(str, c);
	tab = malloc((len + 1) * sizeof(char *));
	while(cnt < len)
	{
		while(str[i] == c && str[i])
			i++;
		start = i;
		while (str[i] != c && str[i])
			i++;
		tab[cnt] = ft_substr(str, start, i);
		cnt++;
	}
	tab[cnt] = "\0";
	return(tab);
}
