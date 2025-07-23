/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 03:00:24 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/10 13:36:55 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	ft_putstr(char *s)
{
	int	slen;

	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	slen = ft_strlen(s);
	write(1, s, slen);
	return (slen);
}
