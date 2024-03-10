/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:07:14 by oruban            #+#    #+#             */
/*   Updated: 2024/03/10 20:50:17 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://github.com/jotavare/42-resources?tab=readme-ov-file#02-so_long
// https://reactive.so/post/42-a-comprehensive-guide-to-so_long
// https://www.youtube.com/watch?v=D1DeE-Qit3M&t=17s

// check the functions used:
// Nm -r ./so_long

#include "so_long.h"

static t_frame *map_check(char *av)
{
	t_frame *game = NULL;
	char	*ext;
	int		fd;
	
	ext = ft_strrchr(av, '.');
	if (!ext || ft_strlen(ext) != 4 || ft_strncmp(ext, ".ber", 4))
	{
		write(2, "Error: not a valid map file name\n", 33);
		exit(1);
	}
	fd = open(av, O_RDONLY);
	if (fd == -1 )
	{
		write(2, "Error: map file can not be open\n", 32);
		exit(1);
	}
	
	close(fd);
	return(game);
}

int main(int ac, char **av)
{
	t_frame	*game;
	
	if (ac != 2)
	{
		write(2, "Error: Wrong number of arguments!\n", 34);
		return (0);
	}
	game = map_check(av[1]);
// {	ft_printf("'%s'\n", *av);
// 	ft_printf("'%s'\n", *(av + 1));
// 	ft_printf("'%s'\n", av[0]);
// 	ft_printf("'%s'\n", av[1]);}
	
	return (0);
}
