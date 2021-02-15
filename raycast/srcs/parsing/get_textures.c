#include "./../../includes/includes.h"
#include "./structparse.h"
#include "./../../libft/libft.h"

static int    check_tex_extension(char *line)
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
    if (data[0][2] == '.')
        return (1);
    return (0);
}

void    get_textures(t_parsedata *parsedata, char *line)
{
    char    **data;

    data = ft_split(line, ' ');
    if (check_space(line))
    {
        ft_putstr_fd("no space between identifient and path\n", 1);
        return ;
    }
    else if (check_tex_extension(line))
    {
        if (!ft_strncmp(data[0], "NO", 2) && *(data + 1) && !*(data + 2))
                parsedata->no_text = *(data + 1);
        if (!ft_strncmp(data[0], "SO", 2) && *(data + 1) && !*(data + 2))
                parsedata->so_text = *(data + 1);
        if (!ft_strncmp(data[0], "WE", 2) && *(data + 1) && !*(data + 2))
                parsedata->we_text = *(data + 1);
        if (!ft_strncmp(data[0], "EA", 2) && *(data + 1) && !*(data + 2))
                parsedata->ea_text = *(data + 1);
        if (!(*data && *(data + 1) && !*(data + 2)))
        {
            ft_putstr_fd("Something wrong Check your file!\n", 1);
            return ;
        }       
    }
    else if (!check_tex_extension(line))
    {
        ft_putstr_fd("Invalid extension of texture\n", 1);
        return ;
    }
}

int main()
{
    t_parsedata parsedata;
    char a[35] = "    NO ./textures/blook.xpm as ";
    char b[35] = "   ./textures/north.xpm  ";
    char c[35] = "  WE    ./textures/west.m     ";
    char d[35] = "    EA    ./textures/east.xpm  ";
    char e[35] = "    EA ./textures/east.xpm   ff";
    get_textures(&parsedata, a);
    printf("\n");
    get_textures(&parsedata, b);
    printf("\n");
    get_textures(&parsedata, c);
    printf("\n");
    get_textures(&parsedata, d);
    //printf("%s\n",parsedata.we_text);
    get_textures(&parsedata, e);
    printf("\n");
}