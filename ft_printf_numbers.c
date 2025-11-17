/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/11/13 13:31:19 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints a signed integer in base 10.
 *
 * @param n The integer to print.
 * @return Number of characters printed, or -1 on error.
 */
int	ft_putnbr_int_count(long n)
{
	int		count;
	char	digit;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_int_count(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}

/**
 * @brief Prints an unsigned integer in base 10.
 *
 * @param n The unsigned integer to print.
 * @return Number of characters printed.
 */
int	ft_print_unsigned(unsigned long int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}
