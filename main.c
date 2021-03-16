// Print prompt string, read a line of input, echo the input back to the screen
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
	data->tab_env = (char **)malloc(sizeof(char*) * size + 5);
	i = -1;
	while (++i < size - 1)
		data->tab_env[i] = ft_strdup(envp[i]);
}

void ft_free(void)
{
	int i;

	i = 0;
	while (data->tab_env[i])
	{
			free(data->tab_env[i]);
			i++;
	}
}


int		main(int argc, char** argv, char** envp)
{
	int		i;

	(void)argc;
	(void)argv;
	i = 0;
	data = malloc(sizeof(t_mega_structure));
	while (42)
	{
		ft_transformenvptoglobal(envp);
		ft_display_cwd();

		//ft_free();
	}
}