// Print prompt string, read a line of input, echo the input back to the screen
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

char    **tab_env;


char *ft_change_cwd(char *cwd)
{
    char    *home;
    int     i;
    int     j;
    int     k;

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
        home[k] =cwd[j];
        k++;
    }
    return(home);
}

void ft_display_cwd(void)
{
    char *cwd;
    char *home;
    
    cwd = (char*)malloc(sizeof(char) * 4096);
    if (cwd == NULL)
       return;
    getcwd(cwd, 4096);
    home = ft_change_cwd(cwd);
    free(cwd);
    printf("%s",home);
    printf(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	printf("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
    free(cwd);
    free(home);

}
int     ft_len_envp(char **envp)
{
    int i;

    i = 0;
    while(envp[i])
        i++;
    return(i + 1);
}

void ft_transformEnvpToGlobal(char **envp)
{
    int size;
    int i;

    size = ft_len_envp(envp);
    tab_env = (char **)malloc(sizeof(char*) * size + 5);
    i = -1;
    while (++i < size - 1)
        tab_env[i] = ft_strdup(envp[i]);
}

int main(int argc, char **argv, char** envp)
{
    (void) argc;
    (void) argv;
    (void) envp;
    

    int i;
    i =0;
    
    ft_transformEnvpToGlobal(envp);
    ft_display_cwd();
  //  printf("HOME : %s\n", getenv("HOME")); 
  //  printf("HOMEPATH : %s\n", getenv("HOMEPATH"));
/*
    while(envp[i])
    {
         printf("%s\n",envp[i]);
         i++;

    }*/
}