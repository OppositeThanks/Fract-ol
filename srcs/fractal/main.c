/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:55:12 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/03 14:34:44 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <unistd.h>

//int offset = (y * line_length + x * (bits_per_pixel / 8));

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	mlx_t	*mlx;
	t_data	img;
	t_data	data;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} */

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

/* void	mandelbrot_init(void)
{
	data.min_r = -2.0;
	data.max_r = 1.0;
	data.min_i = -1.5;
	data.max_i = data.min_i + (data.max_r - data.min_r) * height / width;
	
} */

int	main(void)
{
	mlx_t	*mlx;
	t_data	img;
	t_data	data;
	unsigned int height;
	unsigned int width;

	height = 600;
	width = 800;

	mlx = mlx_init(width, height, "Fract-ol", 1);
	if (!mlx)
	{
		printf("Mlx couldn't init");
		return (0);
	}
	img.img = mlx_new_image(mlx, width, height);
	//Def of limits between Real nbrs && Unreal nbrs for mandelbrot
	data.min_r = -2.0;
	data.max_r = 1.0;
	data.min_i = -1.2;
	data.max_i = data.min_i + (data.max_r - data.min_r) * height / width;
	//Drawing proc set up first two iterations of double pixel r && i init x && y
	unsigned int x;
	unsigned int y;
	double pr;
	double pi;
	
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pr = data.min_r + x * ((data.max_r - data.min_r) / width);
			pi = data.min_i + y * ((data.max_i - data.min_i) / height);
			mandelbrot(&img, x, y, pr, pi);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

/* //calcule nbr complx d'un pixel :
cr = min_r + x * (max_r - min_r) / width;
ci = min_i + y * (max_i - min_i) / height;
zr = zr * zr - zi * zi + cr;
zi = 2 * zr * zi + ci;
if ((zr * zr + zi * zi) > 4)
	//no pixel */
//mlx_put_pixel(img.img, x, y, (unsigned int)(i + 255));
//0x00FF0000 is hex for ARGB(0, 255, 0, 0);

/* .1- Check nbr of args
.2- Check which fractal is used
.3- Init t_fractol
.4- Call mlx functionsthat init the mlx_new_window
.5- Call the function that will create the fractal
.6- Call mlx function that will display + interact
(make ft_exit that make sure you exit properly and with the right error message) */

//fscan(stdin, "c");
//system("leaks -q fractol");
//env -i <exe> in shell
//f(z) = z^2+c; z(n)=(zn-1)^2+c;(AA-BB)+(2AB)i;
//Complex squaring: z(n-1)^2 = (A+iB)^2 = (AA)+(AB)i+(AB)i-BB = (AA-BB)+(2AB)i