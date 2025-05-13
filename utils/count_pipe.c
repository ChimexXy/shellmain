#include "../header.h"

int count_pipes(char *line)
{
    int count = 1;
    int i = 0;

    while (line[i])
    {
        if (line[i] == '|')
            count++;
        i++;
    }
    return count;
}
