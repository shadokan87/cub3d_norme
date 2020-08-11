#include "cublib.h"


void	closegame(var_t *var, char *message)
{
	int i;

	i = -1;
	if (var->mlx_ptr)
		free(var->mlx_ptr);
	if (var->mlx_win)
		free(var->mlx_win);
	if (var->addr)
		free(var->addr);
	while (++i < var->spritenum && var->spritequeue)
		var->spritequeue[i] ? free(var->spritequeue[i]) : 0;
	message ? ft_fprintf(1, message) : 0;
	exit(0);
}

int	main(int argc, char **argv)
{
	var_t var;

	if (!(argc >= 2 && argc <= 3))
	{
		ft_fprintf(1, "Please use [--save] argument to save the first frame into a bmp file\nfollowed by a .cub file or directly the .cub file to launch the game");
		exit(0);
	}
	init_struct(&var, argv);
	if ((var.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (var.s_w > 1914)
		var.s_w = 1914;
	if (var.s_h > 924)
		var.s_h = 924;
	if ((var.mlx_win = mlx_new_window(var.mlx_ptr, var.s_w, var.s_h, "cub3d")) == NULL)
	return (EXIT_FAILURE);
	init_raycast(&var);
	init_keys(&var, 5);
	start(&var);
	return (EXIT_SUCCESS);
}
