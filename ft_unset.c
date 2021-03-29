#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

void ft_unset(char *command)
{
    char **arg;
    t_env *tmp;
    command = &command[ft_strlen("unset")];
    arg = ft_split(command, data.space);
    if (ft_size(arg) == 1)
    {
        tmp = ft_search_env(arg[0]);
        if (tmp == 0)
            return;
        tmp->before->next = tmp->next;
        tmp->next->before = tmp->before;
    }
}