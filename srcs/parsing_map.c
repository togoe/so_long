#include "../includes/so_long.h"

void     extract_file(char *file, t_vars *vars)
{
    int     fd;
    int     ret;
    char    buf[BUFFER_SIZE + 1];
    char    *stock_file = NULL;

    fd = open(file, O_RDONLY);
    ret = read(fd, buf, BUFFER_SIZE);
    buf[ret] = '\0';
    while (ret != 0)
    {
        stock_file = ft_strjoin(stock_file, buf);
        ret = read(fd, buf, BUFFER_SIZE);
        buf[ret] = '\0';
    }
    close(fd);
    if (!stock_file)
        return ;
    vars->map = ft_split(stock_file, '\n');
    free(stock_file);
}

int     rectangular_map_and_nb_lines(char **map_file, t_vars *vars)
{
    int     len;
    int     i;

    vars->len_line = ft_strlen(map_file[0]);
    i = 0;
    while (map_file[i])
    {
        len = ft_strlen(map_file[i]);
        if (len != vars->len_line)
            return (0);
        i++;
    }
    vars->count_line = --i;
    return (1);
}

int     check_map(char **map_file, t_vars *vars)
{   
    int     i;

    i = 0;
    while (i < vars->len_line)
    {
        if(map_file[0][i] != '1' || map_file[vars->count_line - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < vars->count_line)
    {
        if (map_file[i][0] != '1' && map_file[i][vars->len_line - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int     check_character(t_vars *vars)
{
    int i;
    int j;

    j = 0;
    while (vars->map[j])
    {
        i = 0;
        while (vars->map[i][j])
        {
            if (!check_c(vars->map[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    pars_map(char *file, t_vars *vars)
{
    extract_file(file, vars);
    if (!rectangular_map_and_nb_lines(vars->map, vars))
        ft_error("The map is not rectangular");
    if (!check_map(vars->map, vars))
        ft_error("The format wall is not good");
    if (!check_character(vars))
        ft_error("Invalid characters");
}