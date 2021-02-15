/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:01:07 by razaha            #+#    #+#             */
/*   Updated: 2021/01/08 03:55:43 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//#include "../cube.h"

void	ft_fill_resolution(char *line)
{
	char **s1;

	s1 = ft_split(line, ' ');
	if (g_window_width || g_window_height)
		ft_puterror("Double Resolution elements !");
	if (*(s1 + 1) && *(s1 + 2) && !*(s1 + 3))
	{
		g_window_width = ft_p_atoi(*(s1 + 1));
		g_window_height = ft_p_atoi(*(s1 + 2));
	}
	ft_free(s1);
}
