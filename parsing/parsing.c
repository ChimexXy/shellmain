#include "../header.h"

int red_parse(t_bash *bash)
{
    int i;
    int j;

    i = 0;
    while (i < bash->num_cmd)
    {
        j = ft_strlen(bash->s_cmd[i]->command) - 1;
        // skip spaces f l'akhir
        while (j >= 0 && (bash->s_cmd[i]->command[j] == ' ' 
			|| bash->s_cmd[i]->command[j] == '\t'))
            j--;
        // check if last char (before spaces) is a redirection
        if (j >= 0 && (bash->s_cmd[i]->command[j] == '>' 
			|| bash->s_cmd[i]->command[j] == '<'))
            return (0);
        i++;
    }
    return (1);
}

