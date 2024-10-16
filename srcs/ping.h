#ifndef PING_STRUCT_H
#define PING_STRUCT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>

#include <errno.h>

#include  <sys/socket.h>
#include  <netinet/in.h>

#define DEFAULT_INTERVAL 1 // seconds between sending each packet.

#define SUCCESS 0
#define ERROR   -1

#define EXIT_SUCCESS            0
#define EXIT_ERR_PKT_OR_DELAY   1
#define EXIT_ERR_OTHER          2

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


void sigalarm_handler(int sigalarm);
void sigquit_handler(int sigquit);
void sigint_handler(int sigint);

#endif