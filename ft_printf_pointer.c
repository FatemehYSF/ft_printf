/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/11/13 15:16:42 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Recursively prints a pointer’s numeric
 *       value in hexadecimal (lowercase).
 *
 * @param n The pointer value cast to unsigned long long.
 * @return Number of characters printed.
 */
static int	ft_putnbr_pointer_hex(unsigned long long n)
{
	int		count;
	char	digit;
	char	*hex_lookup;

	count = 0;
	hex_lookup = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_pointer_hex(n / 16);
	digit = hex_lookup[n % 16];
	write(1, &digit, 1);
	count++;
	return (count);
}

/**
 * @brief Prints a pointer in standard %p format.
 *
 * @param p The pointer to print.
 * @return Number of characters printed.
 * @note Prints "(nil)" if the pointer is NULL.
 */
int	ft_print_pointer(void *p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putnbr_pointer_hex((unsigned long long)p) + 2);
}
