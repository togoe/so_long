/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:06:31 by ctogoe            #+#    #+#             */
/*   Updated: 2022/01/25 11:12:21 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	init_struct(t_vars *vars)
{
	vars->len_line = 0;
	vars->count_line = 0;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->collect = 0;
	vars->moves = 0;
	vars->map = 0;
	vars->p_x = 0;
	vars->p_y = 0;
	vars->t_i = -1;
}

int	close_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->grass);
	mlx_destroy_image(vars->mlx, vars->player);
	mlx_destroy_image(vars->mlx, vars->object);
	mlx_destroy_image(vars->mlx, vars->door);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars->map);
	exit (EXIT_SUCCESS);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == RIGHT)
		ft_display_right(vars);
	if (key == LEFT)
		ft_display_left(vars);
	if (key == UP)
		ft_display_up(vars);
	if (key == DOWN)
		ft_display_down(vars);
	if (key == ESC)
		close_win(vars);
	ft_put_map(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (!(ac == 2 && check_file(av[1])))
		ft_error("Error: wrong number of arguments and/or the .ber file");
	init_struct(&vars);
	parsing_map(av[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.len_line * IMG_PX),
			(vars.count_line * IMG_PX), "so_long42");
	init_img(&vars);
	ft_put_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 33, 131072, &close_win, &vars);
	mlx_loop(vars.mlx);
	mlx_key_hook(vars.win, key_hook, &vars);
	return (0);
}
