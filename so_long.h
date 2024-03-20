/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:53 by oruban            #+#    #+#             */
/*   Updated: 2024/03/20 13:05:36 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>                     // open()
// # include <stdbool.h>

typedef struct s_frame
{
	char	**map;
	int		player[2];		// player's coordinated [row][collumn]
	int		rows;
	int		cols;
	int		collectibles;
	int		exit;
	int		steps;
	int		collected;
}			t_frame;

/* paramters for the funciton called from ismiddle*/
typedef struct s_func_pars
{
	char	*line;
	char	*next_l;
	int		cols;
	int		fd;
}			t_func_pars;

/* PEC0 counters 2 be given as a parameter to teh function called
 from ismiddle */
typedef struct s_peco
{
	int		p;
	int		e;
	int		c;
	int		o;
	int		l;
}				t_peco;

// 2map_check_utils.c:
void	check_path(t_frame *game, int **marked);
void	mark_path(t_frame *game, int row, int col, int **marked);
void	is_path(t_frame *game);
void	is_pec(t_frame *game);
void	init_frame_map(t_frame *game, int fd);
// 1map_check_utils.c :
void	peco_chrs_chck(t_peco *peco, t_func_pars chr_chck);
t_peco	*ismiddle(char *line, char *next_l, int cols, int fd);
int		iswall(char *s, char flag, int fd);
int		map_valid(int fd, t_frame *game);
void	init_frame_start(t_frame *game);
// 99utils.c :
void	error_exit(const char *s, int fd, char *line, char *line1);
#endif  /* SO_LONG_H */
