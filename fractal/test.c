/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:06:00 by lperrin           #+#    #+#             */
/*   Updated: 2022/10/03 16:08:22 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	type_cmp(char *av, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

static void	get_set(t_data *data, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		data->set = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		data->set = JULIA;
	else
		help_mess(data);
}

static void	check_args(t_data *data, int ac, char **av)
{
	get_set(data, av);
	if (data->set != JULIA && ac > 3)
		help_mess(data);
	else if (data->set == JULIA && ac > 5)
		help_mess(data);
	get_julia_starting_values(data, ac, av);
}

int	main(int ac, char **av)
{
	mlx_t *mlx;
	t_data data;
	
	if (ac < 2)
		help_mess(&data);
	check_args(&data, ac ,av);
	mlx = init(&data);
	render(&data);
	/* MIRAR LOS HOOKS */
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
	
/* .1- Check nbr of args
.2- Check which fractal is used
.3- Init t_fractol
.4- Call mlx functionsthat init the mlx_new_window
.5- Call the function that will create the fractal
.6- Call mlx function that will display + interact
(make ft_exit that make sure you exit properly and with the right error message)
	 */