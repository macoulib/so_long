/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:38:35 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/10 13:36:47 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	ft_puthexamaj(const unsigned int n)
{
	int	x;

	x = 0;
	if (n >= 16)
	{
		x += ft_puthexamaj(n / 16);
		x += ft_puthexamaj(n % 16);
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
			ft_putchar(n - 10 + 'A');
			x++;
		}
	}
	return (x);
}
