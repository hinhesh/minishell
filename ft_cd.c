#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>


char *ft_check_relative(char *command)
{
    char *abs;
    char *cwd;

    if (*command == '/')
        return (command);
    cwd = ft_print_path();
    abs = malloc(sizeof(char) * (ft_strlen(cwd) + ft_strlen(command) + 10));
    ft_bzero(abs, ft_strlen(cwd) + ft_strlen(command) + 10);
    ft_strlcpy(abs, cwd, ft_strlen(cwd) + 10);
    abs[ft_strlen(cwd)] = '/';
    ft_strlcat(abs, command, ft_strlen(cwd) + ft_strlen(command) + 10);
    return(abs);
}

void ft_update_path(char *new_path,char *old_path)
{
    char *new_var;
    char *key;

    key = ft_strdup("OLDPWD=");
    new_var = ft_strjoin(key, old_path);
    ft_create_var(new_var);
    free(new_var);
    key = ft_strdup("PWD=");
    new_var = ft_strjoin(key,new_path);
    ft_create_var(new_var);
}

void ft_cd(char *command)
{
   char *path;
    char **arg;
    char *old_pwd;
	command = &command[2];
	ft_trim(command, &command);
    arg = ft_split(command, data.space);
    old_pwd = ft_print_path();
    if (ft_size(arg) == 1)
    {
        path = ft_check_relative(arg[0]);
        if (chdir(path) == -1)
            ft_error();
        else
            ft_update_path(path, old_pwd);
        free(path);
        free(old_pwd);
    }

}
