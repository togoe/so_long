/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:49:36 by ctogoe            #+#    #+#             */
/*   Updated: 2022/01/25 14:39:57 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}

int	check_file(char *file)
{
	char	*index_ber;
	int		len;

	len = ft_strlen(file);
	index_ber = ft_strnstr(file, ".ber", len);
	len = ft_strlen(index_ber);
	if (!index_ber || ft_strncmp(index_ber, ".ber", len))
		return (0);
	return (1);
}

int	check_nb_char(t_vars *vars)
{
	int	tab[4] = {0, 0, 0, 0};
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '0')
				tab[0] += 1;
			if (vars->map[i][j] == 'P')
				tab[1] += 1;
			if (vars->map[i][j] == 'C')
				tab[2] += 1;
			if (vars->map[i][j] == 'E')
				tab[3] += 1;
			j++;
		}
		i++;
	}
	if (tab[0] < 1 || tab[1] != 1 || tab[2] < 1 || tab[3] != 1)
		return (0);
	vars->collect = tab[2];
	return (1);
}
