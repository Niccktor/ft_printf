/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_unknow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:05:41 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/20 18:25:22 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			pf_handeler_unknow(t_pf_env *env)
{
	int len;

	len = 1;
	while (env->flag[10] > len && env->flag[7] == 0)
	{
		len++;
		if (env->flag[6] == 1)
			env->ret += write(1, "0", 1);
		else
			env->ret += write(1, " ", 1);
	}
	env->ret += write(1, "%", 1);
	while (env->flag[10] > len && env->flag[7] == 1)
	{
		len++;
		env->ret += write(1, " ", 1);
	}
	env->i++;
}
