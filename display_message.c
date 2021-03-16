#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "minishell.h"
static char	*ft_change_cwd(char *cwd, char **tab_env)
{
	char	*home;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (tab_env[i] && ft_strncmp(tab_env[i], "HOME", 4) != 0)
		i++;
	home = (char *)malloc(sizeof(char) * (ft_strlen(cwd) + 1));
	if (home == NULL)
		return (NULL);
	j = 0;
	while (cwd[j] == tab_env[i][j + 5])
		j++;
	home[0] = '~';
	home[1] = '/';
	k = 2;
	while (cwd[j++])
	{
		home[k] = cwd[j];
		k++;
	}
	return (home);
}

 void	ft_display_cwd(void)
{
	char *cwd;
	char *home;

	cwd = (char*)malloc(sizeof(char) * 4096);
	if (cwd == NULL)
		return ;
	getcwd(cwd, 4096);
	home = ft_change_cwd(cwd, data->tab_env);
	printf("%s", home);
	printf(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	printf("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
	free(cwd);
	free(home);
}



