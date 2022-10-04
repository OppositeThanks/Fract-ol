/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:14:45 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/03 16:26:57 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	msg(char *str1, char *str2, int errnbr)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (errnbr);
}

void	complex_limits(t_data *data)
{
	if (data->set == JULIA)
	{
		data->min_r = -2.0;
		data->max_r = 2.0;
		data->min_i = -2.0;
		data->max_i = data->min_i + (data->max_r - data->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		data->min_r = -2.0;
		data->max_r = 1.0;
		data->max_i = -1.5;
		data->min_i = data->max_i + (data->max_r - data->min_r) * HEIGHT / WIDTH;
	}
}

static void	get_julia_starting_values(t_data *data, int ac, char **av)
{
	if (data->set != JULIA || ac == 2)
	{
		data->kr = -0.766667;
		data->ki = -0.090000;
		return ;
	}
	if (ac == 3)
		help_mess(f);
	if (!ft_strchr(av[2], '.'))
		help_mess(f);
	if (!ft_strchr(av[3], '.'))
		help_mess(f);
	data->kr = ft_atof(av[2]);
	data->ki = ft_atof(av[3]);
	if (data->kr > 2.0 || f->kr < -2.0)
		help_mess(f);
	if (data->ki >= 2.0 || f->ki <= -2.0)
		help_mess(f);
}

mlx_t	init(t_data *data, mlx_t *mlx)
{
	mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", 1);
	if (!mlx)
		clear_exit(msg("MLX: error connecting to mlx.", "", 1), data);
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	complex_limits(data);
	return (mlx);
}