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
	if (ft_strncmp(command, "echo", ft_strlen("echo")) == 0)
	{
		ft_echo(command);
	}
}
int		main(int argc, char** argv, char** envp)
{
	int		i;

	(void)argc;
	(void)argv;
	i = 0;

	
	ft_transformenvptoglobal(envp);
	
	while (42)
	{
		
		ft_display_cwd();
		ft_read_line();
		ft_parsing_command(data.line);
		//ft_free();
	}
}