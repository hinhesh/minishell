#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>


char *ft_flags_echo(char *command)
{
    char *tmp;

    if (ft_strncmp(command, "-n", 2) == 0)
    {
        tmp = &command[ft_strlen("-n")];
        if (ft_trim(tmp, &tmp) == 1)
            {
                command = tmp;
                return(command);
            }
    }
    return(command);
}

int ft_search_envp(char *var)
{
    t_env *env;

    env = *(data.env);
    while (env && ft_strncmp(env->key,
    var, ft_strlen(var)) != 0)
		env = env->next;
    if (env == 0)
        return (0);
    ft_putstr_fd(env->value, 1);
    return (1);
}

char *ft_check_variable(char *command)
{
    char *var;
    int  i;

    i = 0;
    command++;
    var = ft_word(command);
    if (ft_strlen(var) == 0)
    {
        ft_putchar_fd('$', 1);
        return(command);
    }
    if (ft_search_envp(var) == 0 
    && command[ft_strlen(var)] != '\0')
        ft_trim(&command[ft_strlen(var)], &command);
    else 
        command = &command[ft_strlen(var)];
    free(var);
    return(command);
}

void ft_print_echo(char *command)
{
    while (*command != '\0')
    {
        if (*command == '$')
            command = ft_check_variable(command);
        else {
            ft_putchar_fd(*command, 1);
            command++;
        }
    }
}

void ft_echo(char *command)
{
	command = &command[ft_strlen("echo")];
	if (ft_trim(command, &command) == 0)
		ft_error();
	else
        {
            command = ft_flags_echo(command);
            ft_print_echo(command);
        }
}