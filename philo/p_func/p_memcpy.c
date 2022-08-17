/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:30:53 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 21:16:37 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*p_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*copy_dest;
	unsigned char	*copy_src;

	copy_dest = (unsigned char *) dest;
	copy_src = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (!n)
		return (dest);
	while (n--)
		*(copy_dest++) = *(copy_src++);
	return (dest);
}
