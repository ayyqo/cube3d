#include "./../../includes/includes.h"
#include "./structparse.h"
#include "./../../libft/libft.h"

void    get_resolution(t_parsedata *parsedata, char *line)
{
    char    **data;

    data = ft_split(line, ' ');
    if (!ft_strncmp(data[0], "R", 1) && !data[0][1])
    {
        if (data[1] && data[2] && !data[3])
        {
            parsedata->win_width = ft_atoi(data[1]);
            parsedata->win_height = ft_atoi(data[2]);
        }
        else
        {
            ft_putstr_fd("format of your resolution is bad", 1);
            return ;
        }
    }
    else {
        ft_putstr_fd("check you resolution format", 1);
    }
}