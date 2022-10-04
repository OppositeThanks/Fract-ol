/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:14:45 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/03 16:26:57 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void mandelbrot(t_data *data, int x, int y, double cr, double ci)
{
	int it;
	double zr;
	double zi;
	double tmp;
	int included;

	zr = 0;
	zi = 0;
	it = -1;
	while (it++ < MAX_ITERATION)
	{
		included = 1;
		if ((zr * zr + zi * zi) > 4.0)
		{
			included = 0;
			break;
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	if (included == 1)
		mlx_put_pixel(data->img, x, y, 0x00FF00FF);
	else
		mlx_put_pixel(data->img, x, y, 0xFF0000FF);
}

void    render(t_data *data)
{
    unsigned int x;
	unsigned int y;
	double pr;
	double pi;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pr = data.min_r + x * ((data.max_r - data.min_r) / WIDTH);
			pi = data.min_i + y * ((data.max_i - data.min_i) / HEIGHT);
			mandelbrot(&img, x, y, pr, pi);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx, img.img, 0, 0);
}