/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:49 by rreis-de          #+#    #+#             */
/*   Updated: 2023/01/11 14:55:35 by rreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

t_complex	square(t_complex z)
{
	t_complex	z2;

	z2.re = pow(z.re, 2) - pow(z.im, 2);
	z2.im = 2 * z.re * z.im;
	return (z2);
}

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

float	module(t_complex a)
{
	return (sqrt(pow(a.re, 2) + pow(a.im, 2)));
}
