/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:36:15 by macoulib          #+#    #+#             */
/*   Updated: 2025/07/10 13:37:38 by macoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	checkx(const char x, va_list ap)
{
	int	len;

	len = 0;
	if (x == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (x == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (x == 'd' || x == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (x == 'p')
		len += ft_putpointer(va_arg(ap, void *));
	else if (x == 'u')
		len += ft_putunbr(va_arg(ap, const unsigned int));
	else if (x == 'x')
		len += ft_puthexamin(va_arg(ap, const unsigned int));
	else if (x == 'X')
		len += ft_puthexamaj(va_arg(ap, const unsigned int));
	else if (x == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *x, ...)
{
	va_list	ap;
	int		len;

	if (!x)
		return (-1);
	va_start(ap, x);
	len = 0;
	while (*x)
	{
		if (*x == '%')
		{
			x++;
			len += checkx(*x, ap);
		}
		else
		{
			len += ft_putchar(*x);
		}
		x++;
	}
	va_end(ap);
	return (len);
}
/*
int	main(void)
{
	int ret1, ret2;

	// Test string
	ret1 = ft_printf("Test string: %s\n", "Hello, world!");
	ret2 = printf("Test string: %s\n", "Hello, world!");
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// Test integer
	ret1 = ft_printf("Test integer: %d\n", 42);
	ret2 = printf("Test integer: %d\n", 42);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// Test character
	ret1 = ft_printf("Test char: %c\n", 'A');
	ret2 = printf("Test char: %c\n", 'A');
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// Test hexadecimal (lowercase)
	ret1 = ft_printf("Test hex: %x\n", 255);
	ret2 = printf("Test hex: %x\n", 255);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// Test pointer
	int a = 42;
	ret1 = ft_printf("Test pointer: %p\n", &a);
	ret2 = printf("Test pointer: %p\n", &a);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// Test percent
	ret1 = ft_printf("Test percent: %%\n");
	ret2 = printf("Test percent: %%\n");
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	return (0);
} */
