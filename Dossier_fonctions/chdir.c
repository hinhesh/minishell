int		main(int argc, char** argv, char** envp)
{
    char *home;
    home = malloc(sizeof(char) * 4096);
    getcwd(home,4096);
    printf("%s\n",home);
    chdir("/Users/how-choongines/Documents/42");
      getcwd(home,4096);
    printf("%s",home);
}