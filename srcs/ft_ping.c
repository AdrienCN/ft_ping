

#include "ping_struct.h"

/* 
TO DO
# REFRACTORING / CODING
- Faire un fichier STRUCT
- virer les (void)

# Parsing
- List all possible parsing or CLI errors
- Implement all parsing error
- IP : parsing false leading 0 . ie : 08.8.8.8 or 8.8.08.8
#ERROR HANDLING
- associate struct ou fonction ERR_CODE - ERR_STRING
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

    /* ping loop */

    return 0;
}
