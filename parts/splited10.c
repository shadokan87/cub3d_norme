#include "../cublib.h"

int			*cpy(t_var *var, int *tab)
{
	int *ret;

	if (!(malloc(sizeof(int) * 2)))
		return (0);
	ret[0] = tab[0];
	ret[1] = tab[1];
	return (ret);
}

double		*sortqueue(t_var *var, double *dist)
{
	int		i;
	double	swap;
	double	swap2;

	i = 1;
	while (i < var->spritenum)
	{
		if (dist[i - 1] < dist[i])
		{
			swap = dist[i - 1];
			dist[i - 1] = dist[i];
			dist[i] = swap;
			swap2 = var->spriteorder[i - 1];
			var->spriteorder[i - 1] = var->spriteorder[i];
			var->spriteorder[i] = swap2;
			i = 1;
		}
		else
			i++;
	}
	return (dist);
}

double		*getdist(t_var *var)
{
	int		i;
	double	*dist;
	double	swap;
	int		swap2;

	dist = (double *)malloc(sizeof(double) * var->spritenum);
	var->spriteorder = malloc(sizeof(int) * var->spritenum);
	i = 0;
	while (i < var->spritenum)
	{
		dist[i] = ((var->posx - var->spritequeue[i][0]) *
		(var->posx - var->spritequeue[i][0])
		+ (var->posy - var->spritequeue[i][1])
		* (var->posy - var->spritequeue[i][1]));
		var->spriteorder[i] = i;
		i++;
	}
	return (sortqueue(var, dist));
}

static void	draw_sprite2(t_var *var, int x, int y)
{
	int	color;
	int	d;

	d = (y - var->vmovescreen) * 256 - var->s_h
				* 128 + var->spriteheight * 128;
	var->texy = ((d * var->tex_h / var->spriteheight) / 256);
	color = var->loaded_addr[6][(var->texx + var->texy * var->tex_w)];
	if ((color & 0x00FFFFFF) != 0)
		pixel_put(var, x, y, color);
}

void		draw_sprite(t_var *var, int sx, int sy)
{
	int	x;
	int	y;
	int	color;
	int	d;

	init_sprite_var(var, sx, sy);
	x = var->drawstartx - 1;
	while (++x < var->drawendx)
	{
		if (var->transformy > 0 && x > 0 && x < var->s_w
		&& var->transformy < var->zbuffer[x])
		{
			y = var->drawstarty - 1;
			var->texx = (int)(256 * (x - (-var->spritewidth / 2 +
			var->spritescreenx)) * var->tex_w / var->spritewidth) / 256;
			while (++y < var->drawendy)
				draw_sprite2(var, x, y);
		}
	}
}
