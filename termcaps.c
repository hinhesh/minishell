#include <stdlib.h>
#include <stdio.h>

#include <curses.h>
#include <term.h>
#include <unistd.h>

int init_term()
{
    int ret;
    char *term_type = getenv("TERM");

    if (term_type == NULL)
    {
        fprintf(stderr, "TERM must be set (see 'env').\n");
        return -1;
    }

    ret = tgetent(NULL, term_type);

    if (ret == -1)
    {
        fprintf(stderr, "Could not access to the termcap database..\n");
        return -1;
    }
    else if (ret == 0)
    {
        fprintf(stderr, "Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_type);
        return -1;
    }

    return 0;
}

int main(int argc, char **argv)
{
   int ret = init_term();
char *cl_cap;
    /* On évite les warnings pour variables non utilisées. */
    (void)argc;
    (void)argv;

    if (ret == 0)
    {

        /* Le déroulement de notre programme se fera ici. */

        // Print le nb de columne et le nb line
        int column_count = tgetnum("co");
        int line_count = tgetnum("li");
        printf("%d ", column_count);
        printf("%d", line_count);

        // C’est elle qui permet de récupérer les fameux termcaps 
        //sous la forme d’une séquence d’échappement ! On peut par 
        //exemple récupérer le termcap « cl » (pour clean) qui 
        //permet de nettoyer (vider) un terminal.
        //tputs est la fonction qui marche de pair avec tgetstr, 
        //c’est elle qui va se charger d’exécuter le termcap que 
        //l’on vient de récupérer.

//tgetstr prend en deuxième paramètre l’adresse du buffer que l’on a utilisé pour tgetent, à savoir NULL.
       cl_cap  = tgetstr("cl", NULL);
       tputs (cl_cap, 1, putchar);

              char *mb_cap = tgetstr("mb", NULL);
        tputs(mb_cap, 1, putchar);

      char *af_cap = tgetstr("AF", NULL);
       tputs(tparm(af_cap, COLOR_GREEN), 1, putchar);



printf("Cool ! Maintenant j'ecris en vert !\n");
printf("Hkldfj");
    char *cm_cap = tgetstr("cm", NULL);
        tputs(tgoto(cm_cap, 5, 5), 1, putchar);
    
    }
 
    return ret;
}