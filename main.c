// Print prompt string, read a line of input, echo the input back to the screen
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>



int 	ft_read_line(void)
{
	char carac[2];

	data.line = malloc(sizeof(char) * 1);
	if (data.line == NULL)
		return (-1);
	ft_bzero(data.line, 1);
	while (read(0, carac, 1) >= 0)
	{
		carac[1] = 0;
		data.line = ft_strjoin(data.line, carac);
		if (carac[0] == '\n')
			break;
	}
	return(1);
}





void ft_parsing_command(char *line)
{
	char *command;

	ft_trim(line, &command);
	command[ft_strlen(command) - 1] = '\0';
	if (ft_strncmp(command, "echo", ft_strlen("echo")) == 0)
		ft_echo(command);
	if (ft_strncmp(command, "cd", ft_strlen("cd")) == 0)
		ft_cd(command);
	if (ft_strncmp(command, "pwd", ft_strlen("pwd")) == 0)
		ft_pwd(command);
	if (ft_strncmp(command, "export", ft_strlen("export")) == 0)
		ft_export(command);
	if (ft_strncmp(command, "unset", ft_strlen("unset")) == 0)
		ft_unset(command);
	if (ft_strncmp(command, "env", ft_strlen("env")) == 0)
		ft_env(command);
	free(command);
}
void ft_initialize(void)
{
	data.space = malloc(sizeof(char) * 7);
	data.space[0] = '\t';
	data.space[1] = '\n';
	data.space[2] = '\v';
	data.space[3] = '\f';
	data.space[4] = '\r';
	data.space[5] = ' ';
	data.space[6] = '\0';

}
int		main(int argc, char** argv, char** envp)
{
	int		i;

	(void)argc;
	(void)argv;
	i = 0;
	ft_initialize();
	ft_build_tree_env(envp);
	
	
	while (42)
	{
		ft_display_cwd();
		ft_read_line();
		ft_parsing_command(data.line);
		//ft_free();
	}
}