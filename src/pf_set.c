 #include "../inc/ft_printf.h"

void    pf_reset_flag(t_pf_env *env)
{
    int i;

    i = -1;
    while (++i < 14)
        env->flag[i] = 0;
    env->flag[i] = 0;
}