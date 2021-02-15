#include "./../../includes/includes.h"
#include "./structparse.h"
#include "./../../libft/libft.h"

static int    check_sprite_extension(char *line)
{
    char    **data;

    data = ft_split(line, ' ');
    if (!ft_strncmp(ft_strrchr(*(data + 1), '.') + 1, "xpm", 3))
        return (1);
    return (0);
}

static int      check_space(char    *line)
{
    char    **data;

    data = ft_split(line, ' ');
    if (data[0][1] == '.')
        return (1);
    return (0);
}

void    get_textures(t_parsedata *parsedata, char *line)
{
    char    **data;

    data = ft_split(line, ' ');
    if (check_space(line))
    {
        ft_putstr_fd("no space between identifient and path", 1);
        return ;
    }
    else if (check_sprite_extension(line))
    {
        if (!ft_strncmp(data[0], "S", 1) && *(data + 1) && !*(data + 2))
                parsedata->s_text = *(data + 1);
        else
        {
            ft_putstr_fd("something wrong", 1);
            return ;
        }
    }
    else if (!check_sprite_extension(line))
    {
        ft_putstr_fd("Invalid extension of sprite", 1);
        return ;
    }
}