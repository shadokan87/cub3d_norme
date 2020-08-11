
#include "../cublib.h"

void	initcolormap(t_var *var)
{
	int i;

	i = 0;
	var->colormap = malloc(sizeof(int *) * var->m_height);
	while (i < var->m_height)
	{
		var->colormap[i] = malloc(sizeof(int) * var->m_width);
		i++;
	}
}

int	skip(char ***split)
{
	char *str = **split;
	if (str[0] == 'R' || str[0] == 'F'
	|| str[0] == 'C' || str[0] == 'S')
		return (1);
	if ((str[0] == 'S' && str[1] == 'O')
	|| (str[0] == 'N' && str[1] == 'O')
	|| (str[0] == 'W' && str[1] == 'E')
	|| (str[0] == 'E' && str[1] == 'A'))
		return (1);
	return (0);
}

int checkbottom(char *str)
{
	int i;
	int y;
	int count;

	i = 0;
	y = 0;
	count = 0;
	if (str[i] && str[i] == ' ')
	{
		while (str[i] && str[i] == ' ')
			i++;
	}
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (!iswall(str[i]))
			return (0);
		i++;
	}
	return (1);
}
