/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyousefi <fyousefi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/18 13:37:42 by kube              #+#    #+#             */
/*   Updated: 2025/11/17 15:31:45 by fyousefi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int count;
    int x = 42;
    char c = 'A';
    char *str = "Fatemeh";
    char *null_str = NULL;
    unsigned int u = 123;
    unsigned int u_max = UINT_MAX;
    int i_min = INT_MIN;
    int i_max = INT_MAX;

    // ---- %c ----
    ft_printf("ft_printf %%c normal: ");
    count = ft_printf("%c\n", c);
    ft_printf("count: %d\n", count);
    printf("printf %%c normal: ");
    count = printf("%c\n", c);
    printf("count: %d\n\n", count);

    ft_printf("ft_printf %%c edge (null char): ");
    count = ft_printf("%c\n", '\0');
    ft_printf("count: %d\n", count);
    printf("printf %%c edge (null char): ");
    count = printf("%c\n", '\0');
    printf("count: %d\n\n", count);

    // ---- %s ----
    ft_printf("ft_printf %%s normal: ");
    count = ft_printf("%s\n", str);
    ft_printf("count: %d\n", count);
    printf("printf %%s normal: ");
    count = printf("%s\n", str);
    printf("count: %d\n\n", count);

    ft_printf("ft_printf %%s NULL: ");
    count = ft_printf("%s\n", null_str);
    ft_printf("count: %d\n", count);
    printf("printf %%s NULL: ");
    count = printf("%s\n", null_str);
    printf("count: %d\n\n", count);

    // ---- %d / %i ----
    ft_printf("ft_printf %%d: ");
    count = ft_printf("%d %d %d\n", -123, i_min, i_max);
    ft_printf("count: %d\n", count);
    printf("printf %%d: ");
    count = printf("%d %d %d\n", -123, i_min, i_max);
    printf("count: %d\n\n", count);

    // ---- %u ----
    ft_printf("ft_printf %%u: ");
    count = ft_printf("%u %u\n", u, u_max);
    ft_printf("count: %d\n", count);
    printf("printf %%u: ");
    count = printf("%u %u\n", u, u_max);
    printf("count: %d\n\n", count);

    // ---- %x ----
    ft_printf("ft_printf %%x: ");
    count = ft_printf("%x %x\n", 0, u_max);
    ft_printf("count: %d\n", count);
    printf("printf %%x: ");
    count = printf("%x %x\n", 0, u_max);
    printf("count: %d\n\n", count);

    // ---- %X ----
    ft_printf("ft_printf %%X: ");
    count = ft_printf("%X %X\n", 0, u_max);
    ft_printf("count: %d\n", count);
    printf("printf %%X: ");
    count = printf("%X %X\n", 0, u_max);
    printf("count: %d\n\n", count);

    // ---- %p ----
    ft_printf("ft_printf %%p normal: ");
    count = ft_printf("%p\n", &x);
    ft_printf("count: %d\n", count);
    printf("printf %%p normal: ");
    count = printf("%p\n", &x);
    printf("count: %d\n\n", count);

    ft_printf("ft_printf %%p NULL: ");
    count = ft_printf("%p\n", NULL);
    ft_printf("count: %d\n", count);
    printf("printf %%p NULL: ");
    count = printf("%p\n", NULL);
    printf("count: %d\n\n", count);

    // ---- %% ----
    ft_printf("ft_printf %%%%: ");
    count = ft_printf("%%%%\n");
    ft_printf("count: %d\n", count);
    printf("printf %%%%: ");
    count = printf("%%%%\n");
    printf("count: %d\n", count);

    return 0;
} */