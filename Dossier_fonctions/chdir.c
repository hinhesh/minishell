int		main(int argc, char** argv, char** envp)
{
    int i;

    i =0;
    while (envp[i] != 0)
    {
        printf("%s\n",envp[i]);
        i++;
    }
    printf("---------------------");
    chdir("/Users/how-choongines/Documents/42");
    i =0;
    while (envp[i] != 0)
    {
        printf("%s\n",envp[i]);
        i++;
    }
}