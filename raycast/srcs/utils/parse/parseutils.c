/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:14:14 by razaha            #+#    #+#             */
/*   Updated: 2021/01/08 03:55:35 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//#include "../cube.h"

void	ft_check_comma(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		if (s[i++] == ',')
			j++;
	if (j != 2)
		ft_puterror("INVALID color Syntax !");
}

char	*ft_trim_spaces(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == ' ')
	{
		s[i] = '\0';
		i--;
	}
	return (ft_strdup(s));
}

void	ft_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}
