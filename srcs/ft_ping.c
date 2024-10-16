

#include "ping.h"

/* 
TO DO
# REFRACTORING / CODING

- Documentation des protode fonctions

# Parsing
- List all possible parsing or CLI errors
- Implement all parsing error
    - IP PARSING
        - parsing false leading 0 . ie : 08.8.8.8 or 8.8.08.8

#SIGNAL HANDLING 
    - use volatile var to store exitsignal and status snapshot  ?
    - Implementer  SIGINT  (Ctrl+C) --> sigexit
    - Implementer SIGQUIT  (Ctrl+\) --> sigstatus 
        - Ne pas quitter le prog en en repetant SIGQUIT+++
    - Implementer SIGALRM           --> sigexit
        - Comment declencher sigalarm ?
        - Trouver le comportement.


#ERROR HANDLING
- associate struct ou fonction ERR_CODE - ERR_STRING


# END CHECKS
- Virer les (void)
- Remove DEBUG OPTION in makefile

*/



void ft_print_error(const int error_code)
{   
    (void)error_code;
    printf("myping : error : %s\n","TO DO PUT REAL ERROR");
};


int main(int argc, char **argv)
{
    (void)argv;
    t_ping_opt ping_opt;

    /* Parsing */
    if (ft_ping_parsing((const int)argc, (const char **)argv, &ping_opt) != PARSING_OK)
    {
        ft_print_error((const int)ping_opt.err_code);
        return 1;
    }
    printf("Parsing ok\n");

    /* Signal handler */
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalarm_handler);
    signal(SIGINT, sigint_handler);

    /* ping loop */
    while (1)
    {
        ;
    }

    return EXIT_SUCCESS;
}
