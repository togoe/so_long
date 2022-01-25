#include "../includes/so_long.h"

void     extract_file(char *file, t_vars *vars)
{
    int     fd;
    int     ret;
    char    buf[BUFFER_SIZE + 1];
    char    *stock_file = NULL;

    fd = open(file, O_RDONLY);
    if (fd < 0 || BUFFER_SIZE < 1)
        return ;
    ret = read(fd, buf, BUFFER_SIZE);
    while (ret != '\0')
    {
        if (ret == -1)
            return ;
        buf[ret] = '\0';
        stock_file = ft_strjoin_gnl(stock_file, buf);
        ret = read(fd, buf, BUFFER_SIZE);
    }
    close(fd);
    if (!stock_file)
       return ;
    vars->map = ft_split(stock_file, '\n');
    free(stock_file);
}

int     rectangular_map_and_nb_lines(t_vars *vars)
{
    int     len;
    int     i;

    vars->len_line = ft_strlen(vars->map[0]);
    i = 0;
    while (vars->map[i])
    {
        len = ft_strlen(vars->map[i]);
        if (len != vars->len_line)
            return (0);
        i++;
    }
    vars->count_line = i;
    return (1);
}

int     check_wall(t_vars *vars)
{   
    int     i;
    i = 0;
    while (i < vars->len_line)
    {
        if(vars->map[0][i] != '1' || vars->map[vars->count_line - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < vars->count_line)
    {
        if (vars->map[i][0] != '1' || vars->map[i][vars->len_line - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int     check_character(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (vars->map[i])
    {
        j = 0;
        while (vars->map[i][j])
        {
            if (!(vars->map[i][j] == '1' || vars->map[i][j] == '0' 
                    || vars->map[i][j] == 'C' || vars->map[i][j] == 'P'
                    || vars->map[i][j] == 'E'))   
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    parsing_map(char *file, t_vars *vars)
{
    extract_file(file, vars);
    if (!rectangular_map_and_nb_lines(vars))
        ft_error("The map is not rectangular");
    if (!check_wall(vars))
        ft_error("The format wall is not good");
    if (!check_character(vars))
        ft_error("Invalid characters");
    if (!check_nb_char(vars))
        ft_error("There are not all the characteres");
}