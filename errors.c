#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

void ft_error()
{
	ft_putstr_fd("Error", 1);
}