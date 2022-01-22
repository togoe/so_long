#include "../includes/so_long.h"

int    ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    return (-1);
}

int     check_file(char *file)
{
    char    *index_ber;
    int     len;

    len = ft_strlen(file);
    index_ber = ft_strnstr(file,".ber", len);
    len = ft_strlen(index_ber);
    if (!index_ber || ft_strncmp(index_ber, ".ber", len))
        return (0);
    return (1);
}

int    check_c(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
        return (1);
    return (0);
}