#include "../includes/so_long.h"

void    init_img(t_vars *vars)
{
    vars->wall = mlx_xpm_file_to_image(vars->mlx, "./images/wall1.xpm", &vars->width, &vars->height);
    vars->grass = mlx_xpm_file_to_image(vars->mlx, "./images/grass1.xpm", &vars->width, &vars->height);
    vars->player = mlx_xpm_file_to_image(vars->mlx, "./images/player1.xpm", &vars->width, &vars->height);
    vars->object = mlx_xpm_file_to_image(vars->mlx, "./images/colect1.xpm", &vars->width, &vars->height);
    vars->door = mlx_xpm_file_to_image(vars->mlx, "./images/door1.xpm", &vars->width, &vars->height);
}