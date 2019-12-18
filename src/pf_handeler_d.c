#include "../inc/ft_printf.h"
#include <stdio.h>

static void pf_print_sign(t_pf_env *env, int sign)
{
    if (sign == 1)
        env->ret += write(1, "-", 1);
    else if (env->flag[11] == 1)
        env->ret += write(1, " ", 1);
    else if (env->flag[8] == 1)
        env->ret += write(1, "+", 1);
}

static void pf_print_d(char *str, int sign, t_pf_env *env)
{
    int len;
    int focus;
    int width;

    len = ft_strlen(str);
    if (env->flag[8] == 1 || env->flag[11] == 1 || sign == 1)
        len++;
    focus = env->flag[9] - len + 1;
    width = env->flag[10] - focus - len;
    if (env->flag[7] == 1)
    {
        pf_print_sign(env, sign);
        while (focus > 0)
        {
            env->ret += write(1, "0", 1);
            focus--;
        }
        env->ret+= write(1, str, ft_strlen(str));
        while (width > 0)
        {
            env->ret += write(1, " ", 1);
            width--;
        }   
    }
    else
    {
        while (width > 0)
        {
            env->ret += write(1, " ", 1);
            width--;
        }
        pf_print_sign(env, sign);
        while (focus > 0 )
        {
            env->ret += write(1, "0", 1);
            focus--;
        }
        env->ret+= write(1, str, ft_strlen(str));
    }
    env->i++;
}

void       pf_handeler_d(t_pf_env *env, va_list *ap)
{
    long long int       nbr;
    unsigned long long  unbr;
    int                 sign;

    sign = 0;
    if (env->flag[0] == 1)
        nbr = (long long int)va_arg(*ap, long int);
    else if (env->flag[1] == 1)
        nbr = (long long int)va_arg(*ap, long long int);
    else if (env->flag[2] == 1)
        nbr = (long long int)va_arg(*ap, int);
    else if (env->flag[3] == 1)
        nbr = (long long int)va_arg(*ap, int);
    else
        nbr = (long long int)va_arg(*ap, int);
    if (nbr < 0)
    {
        sign = 1;
        unbr = -nbr;
    }
    else
        unbr = nbr;
    pf_print_d(pf_itoa_base(unbr, 10), sign, env);
}