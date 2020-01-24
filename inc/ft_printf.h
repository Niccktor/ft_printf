/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:25:33 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/24 02:04:38 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_pf_env
{
	int			ret;
	int			i;
	const char	*format;
	int			flag[13];
	va_list		*ap;
}					t_pf_env;

typedef struct		s_pf_handel
{
	char		c;
	void		(*fnc)();
}					t_pf_handel;

/*
**					lib
*/
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*pf_itoa_base(unsigned long long nbr, int base);
ssize_t				itoa_len(unsigned long long nbr, int base);
char				*pf_ftoa(long double nbr, int focus);
/*
**					ft_printf
*/
int					ft_printf(const char *format, ...);
void				pf_print_dx(char *str, int sign, t_pf_env *env);
void				pf_catch(t_pf_env *env, va_list *ap);
int					pf_check(t_pf_env *env);
void				pf_set_handel(t_pf_handel *handel);
void				pf_reset_flag(t_pf_env *env);
void				pf_handeler_b(t_pf_env *env, va_list *ap);
void				pf_handeler_c(t_pf_env *env, va_list *ap);
void				pf_handeler_f(t_pf_env *env, va_list *ap);
void				pf_handeler_s(t_pf_env *env, va_list *ap);
void				pf_handeler_p(t_pf_env *env, va_list *ap);
void				pf_handeler_d(t_pf_env *env, va_list *ap);
void				pf_handeler_o(t_pf_env *env, va_list *ap);
void				pf_handeler_u(t_pf_env *env, va_list *ap);
void				pf_handeler_x(t_pf_env *env, va_list *ap);
void				pf_handeler_x_up(t_pf_env *env, va_list *ap);
void				pf_handeler_unknow(t_pf_env *env);
#endif
