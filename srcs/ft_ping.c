#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* 
TO DO
# REFRACTORING
- virer les (void)

# Parsing
- List all possible parsing or CLI errors
- Implement all parsing error

#ERROR HANDLING
- associate struct ou fonction ERR_CODE - ERR_STRING


*/


typedef struct  s_ping_opt
{
    char *ip_dst;
    int v;
    int help;
    int err_code;
    #define PARSING_OK              000
    #define ERR_PARS_ARG_UNKNOWN    001
    #define ERR_PARS_ARG_MISSING    002 
    #define ERR_PARS_DST            003 
}   t_ping_opt;

int ft_is_ip(const char *argv, t_ping_opt *ping_opt)
{
    (void)argv, (void)ping_opt;
    int dot = 0;
    int digit_count = 0;
    int len;
    ping_opt->err_code = ERR_PARS_DST; /* ERR ASSUME FAILURE */

    if (argv == NULL || !isdigit(argv[0]))
        return ERR_PARS_DST;
    len = strlen(argv);

    /* 172.0.0.0 */
    for (int i = 0; i < len; i++)
    {
        if (isdigit(argv[i]))
        {
            digit_count++;
            if (digit_count >= 4)
                return ERR_PARS_DST; 
        }
        else
        {
            if (argv[i] == '.')
            {
                dot++;
                digit_count = 0; //Reset digit count
                if (dot > 3)
                    return ERR_PARS_DST;
            }
        }
    }
    return PARSING_OK;
};

void ft_print_error(const int error_code)
{   
    (void)error_code;
    printf("myping : error : %s\n","TO DO PUT REAL ERROR");
};

int ft_ping_parsing(const int arg_count, const char **argv, t_ping_opt *ping_opt)
{
    (void)argv;
    /* Init struct for safety DELETE */
    ping_opt->err_code = 0;
    ping_opt->help = 0;
    ping_opt->v = 0;
    ping_opt->ip_dst = NULL;

    if (arg_count < 2)
    {
        ping_opt->err_code = ERR_PARS_ARG_MISSING;
        return ping_opt->err_code;
    }

    for (int i = 0; i < arg_count; i++)
    {
        if (ft_is_ip(argv[i], ping_opt) != PARSING_OK)
        {
            /*ERR STR */
            printf("Error : DST is not valid IPV4\n");
            return ping_opt->err_code;
        }
    }

   return PARSING_OK;
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

    /* Signal handler */

    /* ping loop */

    return 0;
}
