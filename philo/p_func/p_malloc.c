/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:11:02 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/05 09:43:09 by jisookim         ###   ########.fr       */
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
		ret = NULL;
	}
	return (ret);
}

char	**p_double_malloc(size_t size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(size);
	if (!ret)
	{
		while (ret[i])
			free(ret[i]);
		free(ret);
		ret = NULL;
	}
	return (ret);
}