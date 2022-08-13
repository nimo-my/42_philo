/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:10:56 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/05 10:03:55 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	p_atoi(const char *str)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		return (ERROR);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 2147483647)
			return (ERROR);
		else
			res = res * 10 + (str[i] - '0');
		if (!res || !str[i])
			break;
		i++;
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] != 0)
		return (ERROR);
	
	return ((int) res);
}