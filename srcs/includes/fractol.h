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

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h" 
# include "../lib/libft/libft.h"
# include <stdio.h>
# define HEIGHT 600
# define WIDTH 800
# define MAX_ITERATION 30
# define MANDELBROT 1
# define JULIA 2
typedef struct s_data
{
	mlx_image_t		*img;
	int				set;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			max_it;
	unsigned int	height;
	unsigned int	width;

}					t_data;

typedef struct s_rgba
{
	int				r;
	int				g;
	int				b;
	int				a;

}					t_rgb;

void				help_mess(t_data *data);
void				clear_exit(int exit_code, t_data *data);

#endif