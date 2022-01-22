#include "../includes/so_long.h"

int     check_character(t_vars *vars)
{

}

void    stock_map(char *file, t_vars *vars)
{
    int fd;
    int i = 0;
    int j = 0;

    vars->map = (char **)malloc(sizeof(char *) * (vars->y + 1));
    fd = open(file, O_RDONLY);
    vars->map[i] = get_next_line(fd);
    while (i < vars->y)
    {
        i++;
        vars->map[i] = get_next_line(fd);
    }
    while (vars->map[j])
    {
        printf("%s", vars->map[j]);
        j++;
    }
    close(fd);
}

void     count_y(char *file, t_vars *vars)
{
    int     fd;
    char    *line;

    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        (vars->y)++;
    }
    free(line);
    close(fd);
}

void     pars_map(char *file, t_vars *vars)
{
    count_y(file, vars);
    stock_map(file, vars);
    check_character(vars);
    printf("\n   y =%d\n", vars->y);
}