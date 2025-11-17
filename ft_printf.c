/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/11/17 15:36:18 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Handles a single format specifier
 * 	 and calls the corresponding printing function.
 *
 * @param args Pointer to the va_list of arguments.
 * @param c The format specifier character (e.g., 'd', 's', 'x').
 * @return The number of characters printed, or -1 on error.
 */
static int	ft_handle_format(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar_count((char)va_arg(*args, int)));
	else if (c == '%')
		return (ft_putchar_count('%'));
	else if (c == 's')
		return (ft_putstr_count(va_arg(*args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_int_count(va_arg(*args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_xhex_count(va_arg(*args, unsigned int), c));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	return (0);
}

/**
 * @brief Prints a single character or
 * 		 calls the format handler for '%' sequences.
 *
 * @param fmt The format string.
 * @param i Pointer to the current index in the format string.
 * @param args Pointer to the va_list of arguments.
 * @return Number of characters printed, or -1 on error.
 */
static int	ft_print_char_or_format(const char *fmt, size_t *i, va_list *args)
{
	char	c;
	int		w;

	if (fmt[*i] != '%')
	{
		w = write(1, &fmt[*i], 1);
		if (w == -1)
			return (-1);
		return (1);
	}
	if (!fmt[*i + 1])
		return (0);
	(*i)++;
	c = fmt[*i];
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (ft_handle_format(args, c));
	if (write(1, "%", 1) == -1 || write(1, &c, 1) == -1)
		return (-1);
	return (2);
}

/**
 * @brief Loops through the format string 
 * 			and prints all characters and formatted arguments.
 *
 * @param format The format string.
 * @param args Pointer to the va_list of arguments.
 * @return Total number of characters printed, or -1 on error.
 */
static int	ft_parse_format(const char *format, va_list *args)
{
	size_t	i;
	int		count;
	int		tmp;

	i = 0;
	count = 0;
	while (format[i])
	{
		tmp = ft_print_char_or_format(format, &i, args);
		if (tmp == -1)
			return (-1);
		count += tmp;
		i++;
	}
	return (count);
}

/**
 * @brief Mimics the standard printf function.
 *
 * @param format Format string containing characters
 * 				 and conversion specifiers.
 * @return The total number of characters printed, or -1 on error.
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_parse_format(format, &args);
	va_end(args);
	return (count);
}
