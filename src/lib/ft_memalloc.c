/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:55:25 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/14 19:42:26 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void *)malloc(size * sizeof(void *));
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
