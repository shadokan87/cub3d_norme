#include "../cublib.h"

static void	initspritequeue2(t_var *var)
{
	int i;

	i = -1;
	var->spritequeue = malloc(sizeof(int *) * var->spritenum);
	while (++i < var->spritenum)
		var->spritequeue[i] = malloc(sizeof(int) * 2);
}

void		initspritequeue(t_var *var)
{
	int i;
	int y;
	int z;

	i = -1;
	y = -1;
	z = 0;
	initspritequeue2(var);
	while (++y < var->m_height)
	{
		while (++i < var->m_width)
		{
			if (var->map[y][i] == 6)
			{
				var->map[y][i] = 0;
				var->s_spritex = y;
				var->s_spritey = i;
				var->spritequeue[z][0] = y;
				var->spritequeue[z][1] = i;
				z++;
			}
		}
		i = -1;
	}
}

static void	duplicate_map2(t_var *var)
{
	int i;

	i = -1;
	var->map = malloc(sizeof(int *) * var->m_height);
	var->spritenum = 0;
	while (++i < var->m_height)
		var->map[i] = malloc(sizeof(int) * var->m_width);
}

void		duplicate_map(t_var *var, char **str2)
{
	char	**str;
	int		i;
	int		y;

	i = 0;
	y = -1;
	duplicate_map2(var);
	while (++y < var->m_height)
	{
		while (++i < var->m_width)
		{
			str = ft_split(str2[y], ' ');
			var->map[y][i] = str[i][0] - '0';
			if (var->map[y][i] == 6)
				var->spritenum++;
			if (var->map[y][i] == 4)
			{
				var->posx = y + 1.5;
				var->posy = i + 1;
			}
		}
		i = -1;
	}
}

char		**getmapstr(t_var *var)
{
	int		width;
	char	*str;
	char	**split;
	char	*ptr;

	str = ft_strdup(var->paramfile);
	split = ft_split(str, '\n');
	width = 0;
	ptr = *split;
	while (skip(&split))
	{
		free(*split);
		split++;
	}
	return (split);
}
