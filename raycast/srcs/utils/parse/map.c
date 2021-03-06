/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:56:08 by razaha            #+#    #+#             */
/*   Updated: 2021/01/08 03:55:16 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//#include "../cube.h"

void	ft_setup_player(char dir, int x, int y)
{
	if (dir == 'N')
		g_player.rotationangle = -PI / 2;
	if (dir == 'S')
		g_player.rotationangle = PI / 2;
	if (dir == 'E')
		g_player.rotationangle = 0;
	if (dir == 'W')
		g_player.rotationangle = PI;
	g_player.x = x * TILE_SIZE + TILE_SIZE / 2;
	g_player.y = y * TILE_SIZE + TILE_SIZE / 2;
	g_player.player += 1;
}

void	ft_fill_map(char *map)
{
	char	**line;
	size_t	i;
	size_t	j;
	size_t	var;

	line = ft_split(map, '\n');
	i = 0;
	g_map = malloc(sizeof(char *) * g_rows);
	while (i++ < g_rows)
	{
		g_map[i - 1] = malloc(sizeof(char) * g_cols);
		j = 0;
		var = ft_strlen(line[i - 1]);
		while (j++ < g_cols)
		{
			if (j - 1 >= var)
				g_map[i - 1][j - 1] = ' ';
			else
				g_map[i - 1][j - 1] = line[i - 1][j - 1];
			if (g_map[i - 1][j - 1] == 'N' || g_map[i - 1][j - 1] == 'S'
					|| g_map[i - 1][j - 1] == 'W' || g_map[i - 1][j - 1] == 'E')
				ft_setup_player(g_map[i - 1][j - 1], j - 1, i - 1);
		}
	}
	ft_free(line);
}
