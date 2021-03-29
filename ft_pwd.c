#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

void ft_pwd(char *command)
{
    char **arg;
    char *pwd;

    command = &command[3];
    ft_trim(command, &command);
    arg = ft_split(command, data.space);
    if (ft_size(arg) == 0)
    {
        pwd = ft_print_path();
        ft_putstr_fd(pwd, 1);
        ft_putchar_fd(10,1);
    }
    else
        ft_putstr_fd("Too many arguments\n", 1);
    free(command);
}