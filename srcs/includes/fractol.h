/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:14:45 by lperrin           #+#    #+#             */
/*   Updated: 2022/09/29 14:47:49 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# define WIDTH 100
# define HEIGHT 100
# define MAX_ITERATION 80
typedef struct s_data
{
	mlx_image_t	*img;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		max_it;

}				t_data;

/* typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex; */

typedef struct s_fractol
{
	char		*set;
	//mandelbrot;
	//julia;
}				t_fractol;

typedef struct s_rgba
{
	int			r;
	int			g;
	int			b;
	int			a;

}				t_rgb;

#endif