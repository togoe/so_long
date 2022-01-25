/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:53:53 by ctogoe            #+#    #+#             */
/*   Updated: 2022/01/25 12:01:02 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_display_right(t_vars *vars)
{
	if (vars->map[vars->p_x][vars->p_y + 1] == '0'
		|| vars->map[vars->p_x][vars->p_y + 1] == 'C')
	{
		if (vars->map[vars->p_x][vars->p_y + 1] == 'C')
			vars->collect -= 1;
		vars->map[vars->p_x][vars->p_y] = '0';
		vars->map[vars->p_x][vars->p_y + 1] = 'P';
		vars->moves++;
	}
	else if (vars->map[vars->p_x][vars->p_y + 1] == 'E'
			&& vars->collect == 0)
	{
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putstr_fd(" moves\n", 1);
		close_win(vars);
	}
}

void	ft_display_left(t_vars *vars)
{
	if (vars->map[vars->p_x][vars->p_y - 1] == '0'
		|| vars->map[vars->p_x][vars->p_y - 1] == 'C')
	{
		if (vars->map[vars->p_x][vars->p_y - 1] == 'C')
			vars->collect -= 1;
		vars->map[vars->p_x][vars->p_y] = '0';
		vars->map[vars->p_x][vars->p_y - 1] = 'P';
		vars->moves++;
	}
	else if (vars->map[vars->p_x][vars->p_y - 1] == 'E'
			&& vars->collect == 0)
	{
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putstr_fd(" moves\n", 1);
		close_win(vars);
	}
}

void	ft_display_up(t_vars *vars)
{
	if (vars->map[vars->p_x - 1][vars->p_y] == '0'
		|| vars->map[vars->p_x - 1][vars->p_y] == 'C')
	{
		if (vars->map[vars->p_x - 1][vars->p_y] == 'C')
			vars->collect -= 1;
		vars->map[vars->p_x][vars->p_y] = '0';
		vars->map[vars->p_x - 1][vars->p_y] = 'P';
		vars->moves++;
	}
	else if (vars->map[vars->p_x - 1][vars->p_y] == 'E'
			&& vars->collect == 0)
	{
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putstr_fd(" moves\n", 1);
		close_win(vars);
	}
}

void	ft_display_down(t_vars *vars)
{
	if (vars->map[vars->p_x + 1][vars->p_y] == '0'
		|| vars->map[vars->p_x + 1][vars->p_y] == 'C')
	{
		if (vars->map[vars->p_x + 1][vars->p_y] == 'C')
			vars->collect -= 1;
		vars->map[vars->p_x][vars->p_y] = '0';
		vars->map[vars->p_x + 1][vars->p_y] = 'P';
		vars->moves++;
	}
	else if (vars->map[vars->p_x + 1][vars->p_y] == 'E'
			&& vars->collect == 0)
	{
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putstr_fd(" moves\n", 1);
		close_win(vars);
	}
}
