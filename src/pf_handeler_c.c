#include "../inc/ft_printf.h"

void       pf_handeler_c(t_pf_env *env, va_list *ap)
{
    env->ret += 1;
    env->i += 1;
    ft_putchar((char)va_arg(*ap, int));
}