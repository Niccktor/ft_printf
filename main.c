/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:47:39 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 01:45:06 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#define F "bonjour [%s] [%s] [%s] [%c] [%p] [%%] [% 1.0li] [%lu] [%lu] [%hhd] [%10d]\n"


int		main(void)
{
	char *str = NULL;
	char *str2 = "Bonjour jrmr";
	char *str3 = "Bonjour thomas";
	char c = 't';
	long int j = 0;
	int	i = ft_printf(F, str, str2, str3, c, &j, j, 0ul, ULONG_MAX, CHAR_MAX + 42, 42);
	printf("ft_printf = %d printf = %d\n", i, printf(F, str, str2, str3, c, &j, j, 0ul, ULONG_MAX, CHAR_MAX + 42, 42));

/*	i = ft_printf("[%10d] [%+3c]\n", 42, 'a');
	printf("ft_printf = %d printf = %d\n", i, printf("[%10d] [%+3c]\n", 42, 'a'));
	i = ft_printf("[%5p] [%-5p]\n", 0, 0);
	printf("ft_printf = %d printf = %d\n", i, printf("[%5p] [%-5p]\n", 0, 0));

	i = ft_printf("[%010d] [%010d] [%030x]\n", 42, -42, 0xFFFF);
	printf("ft_printf = %d printf = %d\n", i, printf("[%010d] [%010d] [%030x]\n", 42, -42, 0xFFFF));

	i = ft_printf("[%#o] [%#o]\n", 40, 0);
	printf("ft_printf = %d printf= %d\n", i, printf("[%#o] [%#o]\n", 40, 0));

	i = ft_printf("[% +d] [%0-3d] [%03.2d]\n", 40, 0, 0);
	printf("ft_printf = %d printf = %d\n", i, printf("[% +d] [%0-3d] [%03.2d]\n", 40, 0, 0));

	i = ft_printf("[%15.4d] [%15.4d] [%.d] [%.0d] [%+d]\n", 42, -42, 0, 0, 0);
	printf("ft_printf = %d printf = %d\n", i, printf("[%15.4d] [%15.4d] [%.d] [%.0d] [%+d]\n", 42, -42, 0, 0, 0));

	i = ft_printf("[%u] [%.u] [%.0u]\n", 0, 0, 0);
	printf("ft_printf = %d printf = %d\n", i,printf("[%u] [%.u] [%.0u]\n", 0, 0, 0));

	i = ft_printf("[%.o] [%.0o] [%#.o] [%#o]\n", 0, 0, 0, 0);
	printf("ft_printf = %d printf = %d\n", i, printf("[%.o] [%.0o] [%#.o] [%#o]\n", 0, 0, 0, 0));


	i = ft_printf("[%x] [%#x] [%.x] [%.0x] [%#.x] [%#x] [%x] [%#x]\n", 0, 0, 0, 0, 0, 0, 42, 42);
	printf("ft_printf = %d printf = %d\n", i, printf("[%x] [%#x] [%.x] [%.0x] [%#.x] [%#x] [%x] [%#x]\n", 0, 0, 0, 0, 0, 0, 42, 42));
	
	i = ft_printf("[%.p] [%.0p] [%#.p] [%#p] [%.5p]\n", 0, 0, 0, 0, 0);
	printf("ft_printf = %d printf = %d\n", i, printf("[%.p] [%.0p] [%#.p] [%#p] [%.5p]\n", 0, 0, 0, 0, 0));

	i = ft_printf("[%.4s] [%15.4s] [%15.4s] [%4.s]\n", "42", "42", "I am 42", "42");
	printf("ft_printf = %d printf = %d\n", i, printf("[%.4s] [%15.4s] [%15.4s] [%4.s]\n"
	, "42", "42" "I am 42", "42"));
	i = ft_printf("p [%.0p] [%.p] [%.p] [%.5p] [%2.9p]\n", 0, 0, 50, 0, 4242);
	printf("ft_printf = %d printf = %d\n", i, printf("p [%.0p] [%.p] [%.p] [%.5p] [%2.9p]\n", 0, 0, 50, 0, 4242));

	i = ft_printf("[%#.3o]\n", 1);
	printf("ft_printf = %d printf = %d\n", i, printf("[%#.3o]\n", 1));

	i = ft_printf("[%#.o] [%#.0o] [%.o] [%.0o]\n", 0, 0, 0, 0);
	printf("ft_printf = %d printf = %d\n", i, printf("[%#.o] [%#.0o] [%.o] [%.0o]\n", 0, 0, 0, 0));
	
	i = ft_printf("[%5.x] [%5.0x]\n", 0, 0);
	printf("ft_printf = %d printf = %d\n", i, printf("[%5.x] [%5.0x]\n", 0, 0));
	
	i = ft_printf("[%#3o] [%08.3o]\n", 0, 42);
	printf("ft_printf = %d printf = %d\n", i, printf("[%#3o] [%08.3o]\n", 0, 42));
	
	i = ft_printf("[%05%] \n");
	printf("ft_printf = %d printf = %d\n", i, printf("[%05%]\n"));*/

	i = ft_printf("[%f] \n", 23.00041);
	printf("ft_printf = %d printf = %d\n", i, printf("[%f]\n", 23.00041));
	return (0);
}
