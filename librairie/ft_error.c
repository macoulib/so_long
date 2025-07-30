/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:48:36 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/24 20:12:06 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_error(char *message, t_data *data)
{
	write(2, message, ft_strlen(message));
	freemap(data);
	exit(EXIT_FAILURE);
}
