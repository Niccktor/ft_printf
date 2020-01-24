/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:01:59 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/23 07:08:17 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void				pf_print_space(t_pf_env *env, int len,\
							unsigned long long nbr)
{
	while (len < env->flag[10] && !(nbr == 0 && env->flag[9] <= -10))
	{
		env->ret += write(1, " ", 1);
		len++;
	}
}

void					pf_handeler_p(t_pf_env *env, va_list *ap)
{
	char				*str;
	unsigned long long	nbr;
	int					len;

	nbr = (unsigned long long)va_arg(*ap, void *);
	str = pf_itoa_base(nbr, 16);
	len = ft_strlen(str) + 2;
	if (env->flag[7] == 0)
		pf_print_space(env, len, nbr);
	env->ret += write(1, "0x", 2);
	while (env->flag[9] - len + 2 > 0)
	{
		env->ret += write(1, "0", 1);
		len++;
	}
	if (!(nbr == 0 && env->flag[9] <= -10))
		env->ret += write(1, str, ft_strlen(str));
	if (env->flag[7] == 1)
		pf_print_space(env, len, nbr);
	free(str);
	env->i++;
}
