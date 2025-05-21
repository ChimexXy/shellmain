#include "../header.h"

int count_word(char *str, char c)
{
    int i = 0;
    int j = 0;
    
    if (!str) // Protect against NULL input
        return 0;
        
    while (str[i] == c && str[i])
        i++;
        
    while (str[i])
    {
        if (str[i] != c)
        {
            j++;
            while (str[i] != c && str[i])
                i++;
        }
        else
            i++;
    }
    return j;
}

char **ft_split(char *str, char c)
{
    int i = 0;
    int cnt = 0;
    int start = 0;
    int len = 0;
    char **tab = NULL;

    if (!str) // Handle NULL input
        return NULL;
        
    len = count_word(str, c);	
    tab = malloc((len + 1) * sizeof(char *));
    if (!tab) // Check malloc failure
        return NULL;
        
    while (cnt < len && str[i])
    {
        while (str[i] == c && str[i])
            i++;
            
        start = i;
        while (str[i] != c && str[i])
            i++;
            
        tab[cnt] = ft_substr(str, start, i - start);
        if (!tab[cnt]) // Handle substr failure
        {
            // Cleanup already allocated memory
            while (cnt-- > 0)
                free(tab[cnt]);
            free(tab);
            return NULL;
        }
        cnt++;
    }
    tab[cnt] = NULL; // Proper NULL termination
    return tab;
}
