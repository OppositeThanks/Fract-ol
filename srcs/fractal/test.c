/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:06:00 by lperrin           #+#    #+#             */
/*   Updated: 2022/09/29 12:55:05 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void put_the(t_data img, int x, int y)
{
	mlx_put_pixel(img.img, x, y, 0xFF0000FF);
}

int main(void)
{
	mlx_t *mlx;
	t_data img;
	
	mlx = mlx_init(800, 600, "aaaaa",1);
	if (!mlx)
	{
		printf("Mlx couldn't init");
		return (0);
	}
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	put_the(&img, 5, 36);
	mlx_image_to_window(mlx, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}