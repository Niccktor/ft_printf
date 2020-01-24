/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:47:52 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/14 20:12:41 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_print(t_pf_env *env, ssize_t start)
{
	char	*buff;

	if (start != -1)
	{
		buff = ft_strsub(env->format, start, env->i);
		ft_putstr(buff);
		free(buff);
		env->ret += (env->i - start);
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_pf_env	env;

	env.format = format;
	env.ret = 0;
	va_start(ap, format);
	env.i = 0;
	while (env.format[env.i] != '\0')
	{
		if (env.format[env.i] == '%')
		{
			env.i++;
			pf_catch(&env, &ap);
		}
		else
		{
			ft_putchar(env.format[env.i]);
			env.ret++;
			env.i++;
		}
	}
	va_end(ap);
	return (env.ret);
}
