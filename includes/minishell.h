#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
    struct s_env *before;
}t_env;

typedef struct s_mega_structure{

    t_env **env;
    char *line;
    char *command;
    char *space;
}t_mega_structure;


t_mega_structure data;

void	ft_display_cwd(void);

t_env *ft_create_node_env(char *chain);
int		ft_len_envp(char **envp);
void ft_add_env(t_env **tree, t_env *new);
void ft_env(char *command);
t_env *ft_last_env(t_env **tree);
t_env *ft_search_env(char *chain);
void ft_unset(char *command);
void ft_read_envp();
void	ft_transformenvptoglobal(char **envp);
int ft_trim(char *line, char **line_trimmed);
void ft_error();
void ft_echo(char *command);
int ft_check_space(char c);
char *ft_word(char *phrase);
void ft_export(char *command);
void ft_cd(char *command);
int ft_size(char **arg);
char *ft_print_path(void);
void ft_pwd(char *command);
void ft_build_tree_env(char **envp);
#endif