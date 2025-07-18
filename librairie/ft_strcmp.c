/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:11:55 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/18 21:13:26 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	ft_strcmp(char *char1, char *char2)
{
	int i;

	i = 0;

	while ((char1[i] || char2[i]) && char1[i] == char2[i])
		i++;
	return (char1[i] - char2[i]);
}