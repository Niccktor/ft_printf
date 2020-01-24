/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 00:00:28 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/14 19:46:11 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
