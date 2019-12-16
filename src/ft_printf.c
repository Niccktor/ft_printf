/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:44:32 by tbeguin           #+#    #+#             */
/*   Updated: 2018/11/26 10:25:43 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

void    pf_print(t_pf_env *env, ssize_t start)
{
    char    *buff;

    if (start != -1)
    {
        buff = ft_strsub(env->format, start, env->i);
        ft_putstr(buff);
        free(buff);
        env->ret += (env->i - env->ret);
    }
}

int     ft_printf(const char *format, ...)
{
    ssize_t     start;
    va_list     ap;
    t_pf_env    env;
    
    env.format = format;
    env.ret = 0;
	va_start(ap, format);
    env.i = 0;
    start = 0;
    while (env.format[env.i] != '\0')
    {
        if (env.format[env.i] == '%')
        {
            pf_print(&env, start);
            ft_putstr("\n");
            env.i++;
            pf_catch(&env);
            start = env.i;
        }
        env.i++;
    }
    pf_print(&env, start);
    va_end(ap);
    return (env.ret);
}

int     main(void)
{
    ft_printf("test %54s 2eme testtest\n", "bonjour\n");
    return (0);
}