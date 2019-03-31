/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:34:34 by vpetropa          #+#    #+#             */
/*   Updated: 2019/01/05 19:55:18 by vpetropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)b;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
