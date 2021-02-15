/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:00:44 by razaha            #+#    #+#             */
/*   Updated: 2021/01/08 03:55:48 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//#include "../cube.h"

void	ft_textu2(char c, char c2, char *line)
{
	if (c == 'W' && c2 == 'E')
	{
		if (g_wetxt)
			ft_puterror("Double INCLUDE of west texture");
		g_wetxt = ft_trim_spaces(line);
	}
	if (c == 'E' && c2 == 'A')
	{
		if (g_eatxt)
			ft_puterror("Double INCLUDE of east texture");
		g_eatxt = ft_trim_spaces(line);
	}
	if (c == 'S' && c2 == ' ')
	{
		if (g_sprit)
			ft_puterror("Double INCLUDE of sprit texture");
		g_sprit = ft_trim_spaces(line);
	}
}

void	ft_textu(char c, char c2, char *line)
{
	line = line + 2;
	while (*line == ' ' && *line != '\n')
		line++;
	if (c == 'N' && c2 == 'O')
	{
		if (g_notxt)
			ft_puterror("Double INCLUDE of north texture");
		g_notxt = ft_trim_spaces(line);
	}
	if (c == 'S' && c2 == 'O')
	{
		if (g_sotxt)
			ft_puterror("Double INCLUDE of south texture");
		g_sotxt = ft_trim_spaces(line);
	}
	ft_textu2(c, c2, line);
}
