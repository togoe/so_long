#include "../includes/so_long.h"


void	init_struct(t_vars *vars)
{
	vars->len_line = 0;
	vars->count_line = 0;
	vars->mlx = NULL;
	vars->collect = 0;
	vars->nb_exit = 0;
	vars->nb_player = 0;
	vars->wall = NULL;
	vars->map = NULL;
}

int		close_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (EXIT_SUCCESS);
}

void	key_hook(int keycode, t_vars *vars)
{
	printf("key = %d\n", keycode);
	if (keycode == ESC)
		close_win(vars);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	
	if (!(ac == 2 && check_file(av[1])))
		ft_error("Error: wrong number of arguments and/or the .ber file");
	init_struct(&vars);
	parsing_map(av[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.len_line * IMG_PX,
				vars.count_line * IMG_PX, "so_long42");
	init_img(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.wall, 0, 0);
	mlx_hook(vars.win, 33, 131072, &close_win, &vars);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
	printf("gooooooooooood");
	return (0);
}
