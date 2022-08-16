/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:33:20 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/16 21:05:43 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_create_thread(t_info *info)
{
	int i;

	i = 0;
	gettimeofday(&info->start_time, 0);
	while (i < info->num_philo)
	{
		if (pthread_create(&info->t_philo[i], 0, philo_run, &info->philos[i]))
			return (RET_ERROR);
		i++;
	}
	return (OK);
}

int	philo_collect_all_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(info->t_philo[i], NULL) >= 0)
			i++;
		else
			return (RET_ERROR);
	}
	return (OK);
}
