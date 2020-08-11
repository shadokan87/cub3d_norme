
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
