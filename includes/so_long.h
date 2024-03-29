/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctogoe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:03:24 by ctogoe            #+#    #+#             */
/*   Updated: 2022/01/25 17:08:37 by ctogoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define IMG_PX 48
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*wall;
	void	*grass;
	void	*player;
	void	*object;
	void	*door;
	char	**map;
	int		len_line;
	int		count_line;
	int		p_x;
	int		p_y;
	int		collect;
	int		moves;
	int		t_i;
	int		t_j;
}					t_vars;

void	parsing_map(char *file, t_vars *vars);
int		check_file(char *file);
int		ft_error(char *str);
int		check_nb_char(t_vars *vars);
void	init_img(t_vars *vars);
void	ft_put_map(t_vars *vars);
int		key_hook(int key, t_vars *vars);
void	ft_display_right(t_vars *vars);
void	ft_display_left(t_vars *vars);
void	ft_display_up(t_vars *vars);
void	ft_display_down(t_vars *vars);
int		close_win(t_vars *vars);
void	init_struct(t_vars *vars);
#endif
