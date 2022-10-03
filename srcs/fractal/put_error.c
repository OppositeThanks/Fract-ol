/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:45:22 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/03 15:46:17 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	clear_exit(int exit_code, t_data *data)
{
	if (!f)
		exit(exit_code);
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	if (data->win && data->mlx)
		mlx_close_window(data->mlx);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	exit(exit_code);
}

void	option_f(void);
{
	ft_putendl_fd("\nChoose between the following available options :", 1);
	ft_putendl_fd("\n1. Mandelbrot", 1);
	ft_putendl_fd("\n2. Julia", 1);
	ft_putendl_fd("\n+====================================================+", 1);
}

void	help_mess(t_data *data)
{
	ft_putendl_fd("\n+====================================================+", 1);
	ft_putendl_fd("|                     FRACT'OL                       |", 1);
	ft_putendl_fd("+====================================================+\n", 1);
	option_f();
	/* option_c(); */
	clear_exit(EXIT_FAILURE, data);
}
