/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:36:34 by lperrin           #+#    #+#             */
/*   Updated: 2022/07/25 15:04:21 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			c1;
	size_t			c2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	c1 = 0;
	c2 = 0;
	if (!s1 || !s2)
		return (0);
	while (ss1[c1] == ss2[c1] && ss1[c1] != '\0')
		c1++;
	c2 = ss1[c1] - ss2[c1];
	return (c2);
}
