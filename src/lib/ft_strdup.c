/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 22:52:12 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/14 19:42:13 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = ft_strlen((char *)s);
	dst = ft_strnew(len);
	if (!dst)
		return (NULL);
	while (len--)
		dst[len] = s[len];
	return (dst);
}
