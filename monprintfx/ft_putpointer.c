/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:08:36 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/10 13:36:53 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	ft_printadrss(const unsigned long n)
{
	int	x;

	x = 0;
	if (n >= 16)
	{
		x += ft_printadrss(n / 16);
		x += ft_printadrss(n % 16);
	}
	else
	{
		if (n < 10)
		{
			ft_putchar(n + '0');
			x++;
		}
		else
		{
			ft_putchar(n - 10 + 'a');
			x++;
		}
	}
	return (x);
}

int	ft_putpointer(void *pointer)
{
	int	x;

	x = 0;
	if (!pointer)
	{
		x = 3;
		return (write(1, "(nil)", 5));
	}
	else
	{
		ft_putstr("0x");
		x = ft_printadrss((const unsigned long)pointer) + 2;
	}
	return (x);
}
