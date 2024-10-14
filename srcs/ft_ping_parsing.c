#include "ping_struct.h"

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
            else
                return ERR_PARS_DST;
        }
    }
    return PARSING_OK;
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

    /*Start at 1 to skip executable name parsing*/
    for (int i = 1; i < arg_count; i++)
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