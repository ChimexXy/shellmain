#include "../header.h"

char *ft_substr(char *s, int start, int len)
{

	int i = 0;
	char *sub = malloc(len + 1);
	if (!s || start < 0 || len < 0 || !sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';

	return sub;
}
