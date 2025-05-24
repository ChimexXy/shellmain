#include "../header.h"

void free_double_pointer(char **str)
{
    int i;

    i = 0;
    if (!str)
        return;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void free_red(t_bash *bash)
{
    int i;
    int x;

    i = 0;
    while (i < bash->num_cmd)
    {
        if(bash->s_cmd[i]->check_red == 1)
        {
            x = 0;
            while(bash->s_cmd[i]->s_red[x])
            {
                free(bash->s_cmd[i]->s_red[x]->file);
                free(bash->s_cmd[i]->s_red[x]);
                x++;
            }
            free(bash->s_cmd[i]->s_red);
        }
        i++;
    }
}

void    free_env(t_bash *bash)
{
    int i;
    int x;

    i = 0;
    while (i < bash->num_cmd)
    {
        if(bash->s_cmd[i]->check_env == 1)
        {
            x = 0;
            while(bash->s_cmd[i]->s_env[x])
            {
                free(bash->s_cmd[i]->s_env[x]->key);
                free(bash->s_cmd[i]->s_env[x]->value);
                free(bash->s_cmd[i]->s_env[x]);
                x++;
            }
            free(bash->s_cmd[i]->s_env);
        }
        i++;
    }
}

void free_s_bash(t_bash *bash)
{
    int i;

    i = 0;
    while(i < bash->num_cmd)
    {
        free(bash->s_cmd[i]->command);
        free_double_pointer(bash->s_cmd[i]->argument);
        free(bash->s_cmd[i]);
        i++;
    }
    // free(bash->s_cmd);
    free(bash->commands);
    free_double_pointer(bash->args);
    return;
}

void    ft_free(t_bash *bash)
{
    free_red(bash);
    free_env(bash);
    // free_s_bash(bash);
    // free(bash);
}
