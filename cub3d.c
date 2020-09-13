/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:03:20 by motoure           #+#    #+#             */
/*   Updated: 2020/09/13 17:03:23 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"

void	closegame(t_var *var, char *message)
{
	int i;

	i = -1;
	var->mlx_ptr ? free(var->mlx_ptr) : 0;
	var->mlx_win ? free(var->mlx_win) : 0;
	var->addr ? free(var->addr) : 0;
	while (var->paramsliced && var->paramsliced[++i])
		var->paramsliced[i] ? free(var->paramsliced[i]) : 0;
	i = 0;
	var->text_paths ? free(var->text_paths) : 0;
	var->loaded_addr ? free(var->loaded_addr) : 0;
	var->loaded_text ? free(var->loaded_text) : 0;
	freesprite(var, 1);
	i = -1;
	while (var->map && ++i < var->m_height)
		free(var->map[i]);
	var->map ? free(var->map) : 0;
	message ? ft_fprintf(1, message) : 0;
	exit(0);
}

void	dontrun(char *str)
{
	ft_fprintf(1, "%s", str);
	exit(0);
}

void	check_arg(int argc, char **argv)
{
	char	*str;
	int		map;
	int		fd;

	map = (argc == 3) ? 2 : 1;
	str = NULL;
	if (!(argc >= 2 && argc <= 3))
		dontrun("Arguments conditions not met");
	if (map == 2 && !ft_strcmp(argv[1], "--save"))
		dontrun("Second argument should be [--save]");
	str = ft_strdup(argv[map]) + (ft_strlen(argv[map]) - 4);
	if (!ft_strcmp(str, ".cub") || ft_strlen(argv[map]) < 5)
		dontrun("Not a .cub");
	if ((fd = open(argv[map], O_RDWR)) == -1)
		dontrun("file descriptor error");
}

int		main(int argc, char **argv)
{
	t_var var;

	check_arg(argc, argv);
	init_struct(&var, argv);
	if ((var.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (var.s_w > 1914)
		var.s_w = 1914;
	if (var.s_h > 924)
		var.s_h = 924;
	if (!var.screenshot && (var.mlx_win = mlx_new_window
(var.mlx_ptr, var.s_w, var.s_h, "cub3d")) == NULL)
		return (EXIT_FAILURE);
	init_raycast(&var);
	init_keys(&var, 5);
	start(&var);
	return (EXIT_SUCCESS);
}
