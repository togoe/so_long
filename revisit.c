#include "../includes/so_long.h"

void    init_struct(t_vars *vars)
{
    vars->x = 0;
    vars->y = 0;
    vars->mlx = NULL;
    vars->collect = 0;
    vars->nb_player = 0;
}

int     close_win(t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->wall);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit (EXIT_SUCCESS);
}

int main(int ac, char av)
{
    t_vars  vars;
    int     height;
    int     width;

    init_struct(&vars);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 960, 540, "So_long_42");
    vars.wall = mlx_xpm_file_to_image(vars.mlx, "./images/wall1.xpm", &width, &height);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.wall, 0, 0);
    mlx_hook(vars.win, 33, 131072, &close_win, &vars);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
}