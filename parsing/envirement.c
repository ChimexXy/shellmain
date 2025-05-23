#include "../header.h"

int count_env(char *str)
{
	int i = 0, env = 0;

	while (str[i])
	{
		if (str[i] == '=' && str[i - 1] != '=')
			env++;
		i++;
	}
	return env;
}

void parse_env_entries(t_bash *bash, int ind, int num_env)
{
    int i = 0, x = 0;
    char *eq_pos;

    while (bash->s_cmd[ind]->argument[i] && x < num_env)
    {
        // stop parsing env vars if no '=' found in argument
        eq_pos = ft_strchr(bash->s_cmd[ind]->argument[i], '=');
        if (!eq_pos)
            break;
        
        // skip if starts with '='
        if (bash->s_cmd[ind]->argument[i][0] == '=')
        {
            i++;
            continue;
        }
        bash->s_cmd[ind]->s_env[x]->key = ft_substr(
            bash->s_cmd[ind]->argument[i], 0, eq_pos - bash->s_cmd[ind]->argument[i]);
        bash->s_cmd[ind]->s_env[x]->value = ft_strdup(eq_pos + 1);
        x++;
        i++;
    }

    bash->s_cmd[ind]->s_env[x] = NULL;
}


int alloc_env(t_bash *bash, int num_env, int ind) {
    int i = 0;
    bash->s_cmd[ind]->s_env = malloc(sizeof(t_env *) * (num_env + 1));
    if (!bash->s_cmd[ind]->s_env)
        return 0;
    while (i < num_env) {
        bash->s_cmd[ind]->s_env[i] = malloc(sizeof(t_env));
        if (!bash->s_cmd[ind]->s_env[i])
            return 0;
        bash->s_cmd[ind]->s_env[i]->key = NULL;
        bash->s_cmd[ind]->s_env[i]->value = NULL;
        i++;
    }
    bash->s_cmd[ind]->s_env[i] = NULL;
    return 1;
}

int parse_env(t_bash *bash) {
    int i, num_env;
    i = 0;
    while (i < bash->num_cmd) {
        if (bash->s_cmd[i]->check_env == 1) {
            num_env = count_env(bash->s_cmd[i]->command);
            if (num_env > 0 && alloc_env(bash, num_env, i) == 0)
                return 0;
            parse_env_entries(bash, i, num_env);
        }
        i++; 
    }
    return 1;
}