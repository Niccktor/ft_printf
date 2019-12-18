#include "../inc/ft_printf.h"

void            pf_handeler_s(t_pf_env *env, va_list *ap)
{
    char    *str;

    env->i++;
    str = va_arg(*ap, char *);
    if (env->flag[9] == -1)
    {
        if (str == NULL)
            env->ret += write(1, "(null)", 6);
        else
            env->ret += write(1, str, ft_strlen(str));
    }
    else
    {
        if (str == NULL)
        {
            if (env->flag[9] > 5 || env->flag[9] == -1)
                env->ret += write(1, "(null)", 6);
        }
        else
            env->ret += write(1, str, env->flag[9]);
    }
}