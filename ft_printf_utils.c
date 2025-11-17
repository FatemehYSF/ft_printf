/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/11/13 13:34:17 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints a single character.
 *
 * @param c The character to print.
 * @return 1 on success, -1 on write error.
 */
int	ft_putchar_count(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

/**
 * @brief Prints a null-terminated string.
 *          Prints "(null)" if the string pointer is NULL.
 *
 * @param s The string to print.
 * @return Number of characters printed, or -1 on write error.
 */
int	ft_putstr_count(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}
