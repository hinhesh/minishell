#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

void ft_export(char *command)
{
    char **arg;
    command = &command[ft_strlen("export")];
    arg = ft_split(command, data.space);
    if (arg == NULL)
        return ;
    if (ft_size(arg) == 1)
    {
        data.tab_env
    }
}