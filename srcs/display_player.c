#include "../includes/so_long.h"

void    ft_display(t_vars *vars)
{
    int     i;
    int     j;

    i = vars->p_x;
    j = vars->p_y;
    if (vars->map[i][j + 1] == '0' || vars->map[i][j + 1] == 'C')
    {
        if (vars->map[i][j + 1] == 'C')
            vars->collect -= 1;
        vars->map[i][j] = '0';
        vars->map[i][j + 1] = 'P';
        vars->p_y += 1;
        vars->moves++;
    }
   /* else if (vars->map[vars->p_y][vars->p_x + 1] == 'E')
    {
        vars->moves++;
        ft_putnbr_fd(vars->moves, 1);
        ft_putstr_fd(" moves\n", 1);
        close_win(vars);
    }
    */
}