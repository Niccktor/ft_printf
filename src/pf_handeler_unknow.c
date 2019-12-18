#include "../inc/ft_printf.h"

void            pf_handeler_unknow(t_pf_env *env, va_list *ap)
{
    if (env->format[env->i] != '%')
        pf_handeler_p(env, ap);
    else
    {
        env->ret += write(1, "%\0", 1);
        env->i++;
    }
}