/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:01:44 by obelkhad          #+#    #+#             */
/*   Updated: 2021/11/06 15:22:01 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t	len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)buf)[i] = ch;
		i++;
	}
	return (buf);
}
