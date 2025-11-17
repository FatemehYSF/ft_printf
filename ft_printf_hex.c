/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/11/13 13:34:46 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints a number in hexadecimal format.
 *
 * @param nbr The number to print.
 * @param up 'x' for lowercase, 'X' for uppercase.
 * @return Number of characters printed, or -1 on error.
 */
int	ft_putnbr_xhex_count(unsigned long nbr, char up)
{
	int		len;
	char	mod;
	char	*base;
	int		aux;

	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		aux = ft_putnbr_xhex_count(nbr / 16, up);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	mod = base[nbr % 16];
	if (write(1, &mod, 1) == -1)
		return (-1);
	len++;
	return (len);
}
