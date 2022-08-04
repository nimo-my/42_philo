/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:11:02 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/04 22:21:12 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

char	*p_malloc(size_t size)
{
	char	*ret;

	ret = (char *)malloc(size);
	if (!ret)
	{
		free(ret);
		printf("error!\n");
	}
	return (ret);
}