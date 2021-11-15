/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:07:40 by obelkhad          #+#    #+#             */
/*   Updated: 2021/11/10 21:59:04 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void	*dst, const void	*src, size_t	n)
{
	size_t	i;

	i = 0;
	if (src < dst)
	{	
		while (i++ < n)
			((char *)dst)[n - i] = ((char *)src)[n - i];
		return (dst);
	}
	return (ft_memcpy(dst, src, n));
}
