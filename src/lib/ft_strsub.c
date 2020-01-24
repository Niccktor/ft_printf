/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 00:52:37 by tbeguin           #+#    #+#             */
/*   Updated: 2020/01/14 19:28:31 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[len] = '\0';
	i = 0;
	while (len--)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	return (new);
}
