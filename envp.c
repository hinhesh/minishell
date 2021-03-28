 #include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
 int		ft_len_envp(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	return (i + 1);
}
void	ft_transformenvptoglobal(char **envp)
{
	int size;
	int i;

	size = ft_len_envp(envp);
	data.tab_env = (char **)malloc(sizeof(char*) * size + 5);
	i = -1;
	while (++i < size - 1)
		data.tab_env[i] = ft_strdup(envp[i]);
	data.tab_env[i] = 0;
}

int ft_get_env(char *var)
{
	int i;

	i = 0;
	while (data.tab_env[i] != 0)
	{
		if (ft_strncmp(data.tab_env[i], var, ft_strlen(var)) == 0)
			return (i);
		i++;
	}
	return (-1);
}