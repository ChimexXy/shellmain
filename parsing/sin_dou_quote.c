#include "../header.h"

char *remove_quotes(char *str)
{
    if (!str) return NULL;
    
    int len = ft_strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    int i = 0, j = 0;
    char quote = 0;
    
    while (str[i])
    {
        if ((str[i] == '\'' || str[i] == '\"') && !quote)
            quote = str[i];
        else if (str[i] == quote)
            quote = 0;
        else
            result[j++] = str[i];
        i++;
    }
    result[j] = '\0';
    
    // Handle case where we removed everything
    if (j == 0)
    {
        free(result);
        return ft_strdup(""); // Return empty string instead of NULL
    }
    
    return result;
}