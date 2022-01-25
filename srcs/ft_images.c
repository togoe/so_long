/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:41:42 by ctogoe            #+#    #+#             */
/*   Updated: 2022/01/25 11:46:56 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"./images/wall1.xpm", &img_width, &img_height);
	vars->grass = mlx_xpm_file_to_image(vars->mlx,
			"./images/grass1.xpm", &img_width, &img_height);
	vars->player = mlx_xpm_file_to_image(vars->mlx,
			"./images/player1.xpm", &img_width, &img_height);
	vars->object = mlx_xpm_file_to_image(vars->mlx,
			"./images/colect1.xpm", &img_width, &img_height);
	vars->door = mlx_xpm_file_to_image(vars->mlx,
			"./images/door1.xpm", &img_width, &img_height);
}

void	ft_put_img(int x, int y, t_vars *vars)
{
	if (vars->map[x][y] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall,
			(y * IMG_PX), (x * IMG_PX));
	if (vars->map[x][y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->grass,
			(y * IMG_PX), (x * IMG_PX));
	if (vars->map[x][y] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->object,
			(y * IMG_PX), (x * IMG_PX));
	if (vars->map[x][y] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
			(y * IMG_PX), (x * IMG_PX));
		vars->p_x = x;
		vars->p_y = y;
	}
	if (vars->map[x][y] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->door,
			(y * IMG_PX), (x * IMG_PX));
}

void	ft_put_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->count_line)
	{
		j = 0;
		while (j < vars->len_line)
		{
			ft_put_img(i, j, vars);
			j++;
		}
		i++;
	}
}
