#include "../inc/ft_printf.h"
#include <stdio.h>

void        pf_catch(t_pf_env *env, va_list *ap)
{
    t_pf_handel    handel[16];
    int         i;

    pf_check(env);
    pf_set_handel(handel);
    i = 0;
    while (handel[i].c != '\0' && handel[i].c != env->format[env->i])
        i++;
    handel[i].fnc(env, ap);
}