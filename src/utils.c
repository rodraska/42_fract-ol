/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:48:05 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/16 10:00:29 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	in_bounds(int x, int y)
{
	if (x >= 0 && y >= 0 && x < W && y < H)
		return (1);
	return (0);
}

float	ft_seed(char *str)
{
	int		i;
	float	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	return (num / 200);
}
