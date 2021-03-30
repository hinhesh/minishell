#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

void ft_create_var(char *chain)
{
    t_env *new;
    t_env *replace;
    
    new = ft_create_node_env(chain);
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
}
void ft_export(char *command)
{
    char **arg;
    
    command = &command[ft_strlen("export")];
    arg = ft_split(command, data.space);
    if (arg == NULL)
        return ;
    if (ft_size(arg) == 1)
    {
        ft_create_var(arg[0]);;
        ft_read_envp();
    }

}