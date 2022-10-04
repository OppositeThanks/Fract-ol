/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:32:41 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/03 11:42:43 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	mlx_t *mlx;
	t_data img;
/* 	t_data data; */
	unsigned int ImageWidth;
	unsigned int ImageHeight;

	ImageWidth = 800;
	ImageHeight = 600;

	mlx = mlx_init(800, 600, "Fract-ol", 1);
	if (!mlx)
	{
		printf("Mlx couldn't init");
		return (0);
	}
	img.img = mlx_new_image(mlx, ImageWidth, ImageHeight);
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm + (MaxRe - MinRe) * ImageHeight / ImageWidth;
	double Re_factor = (MaxRe - MinRe) / (ImageWidth - 1);
	double Im_factor = (MaxIm - MinIm) / (ImageHeight - 1);
	unsigned MaxIterations = 30;

	for (unsigned y = 0; y < ImageHeight; ++y)
	{
		double c_im = MaxIm - y * Im_factor;
		for (unsigned x = 0; x < ImageWidth; ++x)
		{
			double c_re = MinRe + x * Re_factor;

			double Z_re = c_re, Z_im = c_im;
			unsigned int isInside = 1;
			for (unsigned n = 0; n < MaxIterations; ++n)
			{
				double Z_re2 = Z_re * Z_re, Z_im2 = Z_im * Z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
					break ;
				}
				Z_im = 2 * Z_re * Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if (isInside == 1)
				mlx_put_pixel(img.img, x, y, 0x00FF00FF);
			else
				mlx_put_pixel(img.img, x, y, 0xFF0000FF);
		}
	}
	mlx_image_to_window(mlx, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}