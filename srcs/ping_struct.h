#ifndef PING_STRUCT_H
#define PING_STRUCT_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int ft_is_ip(const char *argv, t_ping_opt *ping_opt);
int ft_ping_parsing(const int arg_count, const char **argv, t_ping_opt *ping_opt);


#endif