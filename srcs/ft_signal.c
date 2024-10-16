#include "ping.h"

void sigint_handler(int sigint)
{
    if (sigint == SIGINT)
    {
        printf("\nSIGINT %d handler\n", SIGINT);
        exit(EXIT_SUCCESS);
    }
};

void sigquit_handler(int sigquit)
{
    if (sigquit == SIGQUIT)
        printf("\nSIGQUIT %d handler\n", SIGQUIT);

};

void sigalarm_handler(int sigalarm)
{
    if (sigalarm == SIGALRM )
        printf("\nSIGALARM %d handler\n", SIGALRM);
}
