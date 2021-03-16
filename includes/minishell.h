#ifndef MINISHELL_H
# define MINISHELL_H


typedef struct s_mega_structure{

    char **tab_env;
}t_mega_structure;

char **tab_env;

t_mega_structure *data;

void	ft_display_cwd(void);

#endif