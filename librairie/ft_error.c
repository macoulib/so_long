/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:48:36 by macoulib          #+#    #+#             */
/*   Updated: 2025/06/21 15:11:52 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "../src/so_long.h"

void ft_error(const char *message) {
    perror(message);  
    exit(EXIT_FAILURE);  
}