/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handeler_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:04:47 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/20 18:12:26 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	pf_print_str(t_pf_env *env, char *str)
{
	int		width;

	width = env->flag[10] - ft_strlen(str);
	if ((int)ft_strlen(str) > env->flag[9] && env->flag[9] > -1)
		width = env->flag[10] - env->flag[9];
	else if (env->flag[9] == -10)
		width = env->flag[10];
	while (env->flag[7] == 0 && --width >= 0)
		env->ret += write(1, " ", 1);
	if (env->flag[9] == -1)
		env->ret += write(1, str, ft_strlen(str));
	else if (env->flag[9] > 0)
	{
		if ((int)ft_strlen(str) > env->flag[9] && env->flag[9] > 0)
			env->ret += write(1, str, env->flag[9]);
		else
			env->ret += write(1, str, ft_strlen(str));
	}
	while (env->flag[7] == 1 && --width >= 0)
		env->ret += write(1, " ", 1);
}

void		pf_handeler_s(t_pf_env *env, va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
		pf_print_str(env, "(null)");
	else
		pf_print_str(env, str);
	env->i++;
}
