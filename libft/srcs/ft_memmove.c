/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 20:54:40 by idonado        #+#    #+#                */
/*   Updated: 2019/12/02 16:11:26 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstcpy;
	char	*srccpy;
	int		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dstcpy = (char*)dst;
	srccpy = (char*)src;
	if (dst < src)
		while (i < (int)len)
		{
			dstcpy[i] = srccpy[i];
			i++;
		}
	else
	{
		i = (int)len;
		while (i != 0)
		{
			dstcpy[i - 1] = srccpy[i - 1];
			i--;
		}
	}
	return (dstcpy);
}
