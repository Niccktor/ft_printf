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
    //ssize_t     start;
    va_list     ap;
    t_pf_env    env;
    
    env.format = format;
    env.ret = 0;
	va_start(ap, format);
    env.i = 0;
   // start = 0;
    while (env.format[env.i] != '\0')
    {
        if (env.format[env.i] == '%')
        {
        //    pf_print(&env, start);
            env.i++;
            pf_catch(&env, &ap);
          //  ft_putchar('\n');
            //start = env.i;
            //ft_putnbr(start);
            //ft_putchar('\n');
        }
        else
        {
            ft_putchar(env.format[env.i]);
            env.ret++;
            env.i++;
        }
    }
    //pf_print(&env, start);
    va_end(ap);
    return (env.ret);
}

#define f "bonjour %s %s %s %c %p\n"
int     main(void)
{


    char *str = NULL;
    char *str2 = "Bonjour jrmr";
    char *str3 = "Bonjour thomas";
    char c = 't';
    int i = ft_printf(f, str, str2, str3, c, &c);
    //int i = 0;
    printf("ret = %d len = %d\n",i, printf(f, str, str2, str3, c, &c));
    //printf("sizeof(void *) = %ld sizeof(unsigned long long) = %ld\n",sizeof(void *), sizeof(__uintmax_t));
    return (0);
}
