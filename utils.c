#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

int ft_check_space(char c)
{
    if (c == '\t' || c == '\n'
    || c == '\v' || c == '\f'
    || c == '\r' || c == ' ')
        return (1);
    return (0);
}
char *ft_word(char *phrase)
{
    char *world;
    int i;

    world = malloc(sizeof(char) * (ft_strlen(phrase) + 1));
    if (world == NULL)
        return (NULL);
    i = 0;
    while (*phrase != '\0' && ft_check_space(*phrase) == 0)
    {
        world[i] = *phrase;
        phrase++;
        i++;
    }
    world[i] = '\0';
    return (world);
}

int ft_trim(char *line, char **line_trimmed)
{
	int trimmed;

	trimmed = 0;
	while (ft_check_space(*line))
	{
		trimmed = 1;
		line++;
	}
	*line_trimmed = line;
	return(trimmed);
}
int ft_size(char **arg)
{
    int i;

    i = 0;
    while (arg[i] != NULL)
         i++;
    return (i);
}

char *ft_print_path(void)
{
    char *cwd;

	cwd = (char*)malloc(sizeof(char) * 4096);
	if (cwd == NULL)
		return(NULL);
	getcwd(cwd, 4096);
    //ft_putstr_fd(cwd, 1);
    return(cwd);
}