#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

void ft_export(char *command)
{
    char **arg;
    t_env *replace;
    t_env *new;
    command = &command[ft_strlen("export")];
    arg = ft_split(command, data.space);
    if (arg == NULL)
        return ;
    if (ft_size(arg) == 1)
    {
        new = ft_create_node_env(arg[0]);
        replace = ft_search_env(new->key);
       if (replace == NULL)
       {
           replace = ft_last_env(data.env);
            new->next = replace;
       }
        else
            new->next = replace->next;
        replace->before->next = new;
        new->before = replace->before;
        replace->before = new;
        ft_read_envp();
    }
}