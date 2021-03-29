#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include <libft.h>

t_env *ft_create_node_env(char *chain)
{
    t_env *new;
    char **tab;

    new = malloc(sizeof(t_env));
    if (new == NULL)
        return (NULL);
    new->next = NULL;
    new->before = NULL;
    tab = ft_split(chain, "=");
    new->key = ft_strdup(tab[0]);
    free(tab[0]);
    if (tab[1])
    {
        new->value = ft_strdup(tab[1]);
        free(tab[1]);
    }
    free(tab);
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
            new->before = last;
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
        printf("%s",temp->key);
        printf("=");
        printf("%s\n",temp->value);
        temp = temp->next;
    }
}
t_env *ft_search_env(char *chain)
{
    t_env *tmp;

    tmp = *(data.env);
    while (tmp != NULL)
    {
        if (ft_strncmp(tmp->key, chain, ft_strlen(tmp->key)) == 0)
            return(tmp);
        tmp = tmp->next;
    }
    return (NULL);
}/*
int		main(int argc, char** argv, char** envp)
{
	int		i;

	(void)argc;
	(void)argv;
	i = 0;
    ft_build_tree_env(envp);
    ft_read_envp();
}*/