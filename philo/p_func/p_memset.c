/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_memset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:28:38 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/04 22:36:07 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*p_memset(void *b, int c, size_t len)
{
	unsigned char	*copy_b;
	size_t			i;

	copy_b = (unsigned char *)b;
	i = 0;
	while (len--)
	{
		copy_b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}