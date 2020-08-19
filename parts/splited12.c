/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:41:20 by motoure           #+#    #+#             */
/*   Updated: 2020/08/14 13:41:22 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cublib.h"

void	fill_color(t_var *var, int i)
{
	if (i <= 8 && i != 7)
		var->text_paths[i] = NULL;
	if (ft_strcmp(var->paramsliced[i], "F"))
	{
		var->f_color[0] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[0]);
		var->f_color[1] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[1]);
		var->f_color[2] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[2]);
		return ;
	}
	if (ft_strcmp(var->paramsliced[i], "C"))
	{
		var->c_color[0] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[0]);
		var->c_color[1] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[1]);
		var->c_color[2] = ft_atoi(ft_split(var->paramsliced[i + 1], ',')[2]);
	}
}

void	fillloopparams(t_var *var)
{
	int i;

	i = -1;
	while (var->paramsliced[++i] != NULL)
	{
		if (ft_strcmp(var->paramsliced[i], "R"))
		{
			var->s_w = ft_atoi(var->paramsliced[i + 1]);
			var->s_h = ft_atoi(var->paramsliced[i + 2]);
		}
		if (ft_strcmp(var->paramsliced[i], "NO"))
			var->text_paths[2] = ft_strdup(var->paramsliced[i + 1]);
		if (ft_strcmp(var->paramsliced[i], "SO"))
			var->text_paths[3] = ft_strdup(var->paramsliced[i + 1]);
		if (ft_strcmp(var->paramsliced[i], "WE"))
			var->text_paths[4] = ft_strdup(var->paramsliced[i + 1]);
		if (ft_strcmp(var->paramsliced[i], "EA"))
			var->text_paths[5] = ft_strdup(var->paramsliced[i + 1]);
		if (ft_strcmp(var->paramsliced[i], "S"))
			var->text_paths[6] = ft_strdup(var->paramsliced[i + 1]);
		fill_color(var, i);
	}
}

int		getred(int rgb, t_var *var)
{
	char	str[3];
	char	*hex;
	int		i;

	i = 0;
	hex = ft_putnbr_base(rgb, HEXD);
	if (rgb == 0)
		return (0);
	str[0] = hex[0];
	str[1] = hex[1];
	str[2] = '\0';
	if (str[0] == '0' && str[1] == '0')
		str[1] = '\0';
	while (i < 255)
	{
		if (ft_strcmp(var->hextable[i], str))
			return (i);
		i++;
	}
	return (255);
}

int		getblue(int rgb, t_var *var)
{
	char	str[3];
	char	*hex;
	int		i;

	i = 0;
	hex = ft_putnbr_base(rgb, HEXD);
	if (rgb == 0)
		return (0);
	str[0] = hex[4];
	str[1] = hex[5];
	str[2] = '\0';
	if (str[0] == '0' && str[1] == '0')
		str[1] = '\0';
	while (i < 255)
	{
		if (ft_strcmp(var->hextable[i], str))
			return (i);
		i++;
	}
	return (255);
}

int		getgreen(int rgb, t_var *var)
{
	char	str[3];
	char	*hex;
	int		i;

	i = 0;
	hex = ft_putnbr_base(rgb, HEXD);
	if (rgb == 0)
		return (0);
	str[0] = hex[2];
	str[1] = hex[3];
	str[2] = '\0';
	if (str[0] == '0' && str[1] == '0')
		str[1] = '\0';
	while (i < 255)
	{
		if (ft_strcmp(var->hextable[i], str))
			return (i);
		i++;
	}
	return (255);
}
