#ifndef MINISHELL_H
# define MINISHELL_H


typedef struct s_mega_structure{

    char **tab_env;
    char *line;
    char *command;
    char *space;
}t_mega_structure;


t_mega_structure data;

void	ft_display_cwd(void);


int		ft_len_envp(char **envp);
void	ft_transformenvptoglobal(char **envp);
int ft_trim(char *line, char **line_trimmed);
void ft_error();
void ft_echo(char *command);
int ft_check_space(char c);
char *ft_word(char *phrase);
void ft_cd(char *command);
#endif