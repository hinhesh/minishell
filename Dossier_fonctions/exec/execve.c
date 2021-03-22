#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int
main(int argc, char *argv[])
{
    char *newargv[] = { NULL, "hello", "world", NULL };
    char *newenviron[] = { NULL };

    assert(argc == 2);  /* argv[1] identifie le // verifie bien qu'il y a bien  2 argument
                           programme à exécuter */
    newargv[0] = argv[1]; // nom de la fonction

    execve(argv[1], newargv, newenviron);
    perror("execve");   /* execve() ne retourne qu'en cas d'erreur */
    exit(EXIT_FAILURE);
}
