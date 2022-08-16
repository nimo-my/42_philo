/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:04:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/16 18:05:06 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_init_input(t_info *info)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < info->num_philo)
	{
		memset(&info->philos[i], 0, sizeof(t_philo));
		info->philos[i].info = (t_info *)malloc(sizeof(t_info));
		if (!info->philos[i].info)
		{
			flag = 1;
			break ;
		}
		info->philos[i].info = info;
		info->philos[i].eat_count = 0;
		info->philos[i].id = i;
		info->philos[i].right_fork = i;
		info->philos[i].left_fork = (i + 1) % info->num_philo;
		i++;
	}
	if (flag)
		return (ERROR);
	return (OK);
}
