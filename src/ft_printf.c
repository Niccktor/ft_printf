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
        env->ret += (env->i - start);
    }
}

int     ft_printf(const char *format, ...)
{
    va_list     ap;
    t_pf_env    env;
    
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

#define f "bonjour [%s] [%s] [%s] [%c] [%p] [%%] [% 1.0li]\n"
int     main(void)
{


    char *str = NULL;
    char *str2 = "Bonjour jrmr";
    char *str3 = "Bonjour thomas";
    char c = 't';
    long int j = 50;
    int i = ft_printf(f, str, str2, str3, c, &c, j);
    //int i = 0;
    printf("ret = %d len = %d\n",i, printf(f, str, str2, str3, c, &c, j));
    //printf("[%+-7.5ld]\n",j);
    return (0);
}
