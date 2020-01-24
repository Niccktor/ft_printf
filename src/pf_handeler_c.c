/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:56:39 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/20 12:26:41 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_handeler_c(t_pf_env *env, va_list *ap)
{
	int len;

	len = env->flag[10] - 1;
	while (len > 0 && env->flag[7] == 0)
	{
		env->ret += write(1, " ", 1);
		len--;
	}
	env->ret += 1;
	env->i += 1;
	ft_putchar((char)va_arg(*ap, int));
	while (len > 0 && env->flag[7] == 1)
	{
		env->ret += write(1, " ", 1);
		len--;
	}
}
