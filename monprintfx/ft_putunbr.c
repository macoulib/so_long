/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:36:03 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/10 13:36:56 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	ft_putunbr(const unsigned int n)
{
	int	x;

	x = 0;
	if (n >= 10)
	{
		x += ft_putunbr(n / 10);
		x += ft_putunbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		x++;
	}
	return (x);
}
