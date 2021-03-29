#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}t_env;


typedef struct s_mega_structure{

    t_env **env;
}t_mega_structure;

t_mega_structure data;

t_env *ft_create_node_env(char *chain)
{
    t_env *new;

    new = malloc(sizeof(t_env));
    if (new == NULL)
        return (NULL);
    new->next = NULL;
    new->key = ft_strdup(chain);
    if (new->key == NULL)
        return (NULL);
    new->value = NULL;

    return (new);
}


t_env *ft_last_env(t_env **tree)
{
    t_env *tmp;

    tmp = *tree;
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

void ft_add_env(t_env **tree, t_env *new)
{
    t_env *last;

    if (tree != NULL && new != NULL)
    {
        if (*tree != NULL)
        {
 
           last = ft_last_env(tree);
            last->next = new;
        }
        else
                *tree = new;
    }

}
void ft_build_tree_env(char **envp)
{
    int i;
    t_env *temp;

    data.env = (t_env **)malloc(sizeof(t_env*));
    *(data.env) = NULL;
    if (data.env == NULL)
        return;
    i = 0;
    while (envp[i] != NULL)
    {
        temp = ft_create_node_env(envp[i]);
        ft_add_env(data.env, temp);
        i++;
    }
}
void ft_read_envp()
{
    t_env *temp;
    
    temp = *data.env;
    while (temp != NULL)
    {
        printf("%s\n",temp->key);
        temp = temp->next;
    }
}
int		main(int argc, char** argv, char** envp)
{
	int		i;

	(void)argc;
	(void)argv;
	i = 0;
    ft_build_tree_env(envp);
    ft_read_envp();
}