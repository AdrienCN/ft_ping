

#include "ping.h"


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
