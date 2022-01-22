#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define UP 119



# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307

typedef struct      s_vars {
    void    *mlx;
    void    *win;
    void    *wall;
    void    *grass;
    void    *player;
    void    *object;
    void    *door;
    int     len;
    int     len_line;
    int     count_line;
    char    **map;
    int     collect;
    int     nb_exit;
    int     nb_player;
}                   t_vars;

void     pars_map(char *file, t_vars *vars);
int     check_file(char *file);
int    ft_error(char *str);
int    check_c(char c);

#endif
