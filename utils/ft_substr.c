#include "../header.h"

char *ft_substr(char *str, int start, int end)
{
	int i = start;
	int ind = 0;
	int j = end - start;
	char *ptr = malloc(j + 1);

	while(i < end)
	{
		ptr[ind] = str[i];
		ind++;
		i++;
	}
	ptr[ind] = '\0';
	return ptr;
}