/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:01:19 by tbeguin           #+#    #+#             */
/*   Updated: 2019/09/21 07:10:27 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>

/*
**                      *flag 
**                          modify      = | 0 = 'l' | 1 = 'll' | 2 = 'h' | 3 = 'hh' | 4 = 'L' |
**                          Attribut    = | 5 = '#' | 6 = '0'  | 7 = '-' | 8 = '+'  |
**                          focus       = | 9 = foc |
**                          width       = | A = wid |            
*/

typedef struct          s_pf_enf
{
    int                 ret;
    int                 i;
    const char          *format;
    int                 flag[13];
    va_list             ap;
}                       t_pf_env;

/*
**                      pf_catch.c
*/
void                    pf_catch(t_pf_env *env);
/*
**                      pf_check.c
*/
int                     pf_check(t_pf_env *env);

/*
**                      pf_set.c
*/
void                    pf_reset_flag(t_pf_env *env);




#endif