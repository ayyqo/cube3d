/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezann <kezann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:21:40 by hfadyl            #+#    #+#             */
/*   Updated: 2021/01/08 03:55:39 by kezann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//#include "../cube.h"

int	ft_puterror(char *error)
{
	char *e;

	e = "\033[1;31m(x) error\n >> \033[0;31m";
	write(1, e, ft_strlen(e));
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
