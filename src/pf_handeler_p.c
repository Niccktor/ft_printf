#include "../inc/ft_printf.h"

#include <stdio.h>
ssize_t             itoa_len(unsigned long long nbr, int base)
{
    ssize_t         i;

    i = 0;
    while (nbr)
    {
        nbr /= base;
        i++;
    }
    return (i);
}

char                *pf_itoa_base(unsigned long long nbr, int base)
{
    char        *str;
    int         len;
    int         i;

    if (nbr == 0)
        return (ft_strdup("0x0\0"));
    len = itoa_len(nbr, base);
    if ((str = (char *)ft_memalloc(sizeof(char) * len + 1)) == NULL)
        return(ft_strdup("0x0\0"));
    i = 0;
    while (nbr)
    {
        if (nbr % base > 9)
            str[len - i - 1] = 'a' + nbr % base - 10;
        else
            str[len - i - 1] = '0' + nbr % base;
        nbr /= base;
        i++;
    }
    return (str);
}


void                pf_handeler_p(t_pf_env *env, va_list *ap)
{
    char    *str;
    unsigned long long nbr;

    nbr = (unsigned long long)va_arg(*ap, void *);
    str = pf_itoa_base(nbr, 16);
    ft_putstr("0x\0");
    env->ret += ft_strlen("0x\0");
    ft_putstr(str);
    env->ret += ft_strlen(str);
    free(str);
    env->i++;
}