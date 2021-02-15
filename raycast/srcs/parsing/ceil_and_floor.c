#include "./../../includes/includes.h"
#include "./structparse.h"
#include "./../utils/libft/libft.h"

static int  count_char(char *str, int c)
{
    int     i;

    i = 0;
    while (*str)
    {
        if (*str == c)
            i++;
        str++;
    }
    return (i);
}

static  int rgb_to_hexa(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

unsigned int    get_colors(char *c_l)
{
    char    **rgb;

    if(count_char(c_l, ',') == 2)
    {
        rgb = ft_split(c_l, ',');
        return (rgb_to_hexa(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2])));
    }
    else {
        ft_putstr_fd("Error on rgb Format", 1);
        return (0);
    }
    return (0);
}