/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:48:36 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/08 23:41:05 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	ft_error(char *message, t_data *data)
{
	perror(message);
	freemap(data);
	//free(data);
	exit(EXIT_FAILURE);
}
