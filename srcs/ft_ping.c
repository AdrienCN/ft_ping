

#include "ping.h"


void ft_print_error(const int error_code)
{   
    (void)error_code;
    printf("myping : error : %s\n","TO DO PUT REAL ERROR");
};

int ft_print_errno(const char *custom_err_msg)
{
    char *str_err = NULL;
    str_err = strerror(errno);
    /* TO DO */
    if ( custom_err_msg != NULL )
        printf("ERRNO : [%s] / CustomMsg  [%s]\n", str_err, custom_err_msg);
    else
        printf("ERRNO : %s\n", str_err);
    return ERROR;
}

int ft_setup_socket(int *icmp_socket)
{
    *icmp_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    
    if (*icmp_socket == ERROR )
        return ft_print_errno(NULL);
    
    /*int setsockopt(int sockfd, int level, int optname,
                      const void *optval, socklen_t optlen)
    */
    return SUCCESS;
};

int main(int argc, char **argv)
{
    (void)argv;
    t_ping_opt  ping_opt;
    int         icmp_socket;

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
    
    /*setup socket */
    if (ft_setup_socket(&icmp_socket) == ERROR)
        return EXIT_ERR_OTHER;
    /* ping loop */
    while (1)
    {
        ;
    }

    return EXIT_SUCCESS;
}
