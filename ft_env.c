#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

void ft_env(char *command)
{
    char **arg;
    command = &command[ft_strlen("env")];
    arg = ft_split(command, data.space);
    if (arg[0] == NULL)
        ft_read_envp();
    else
        ft_putstr_fd("Too many arguments", 1);
}