/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:48:10 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/16 23:08:40 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_philo_dead(t_info *info, t_philo *p)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	if (time_gap(p->current_eat, curr) > info->time_to_die)
	{
		pthread_mutex_lock(&info->m_flag_die);
		info->flag_die = 1;
		pthread_mutex_unlock(&info->m_flag_die);
		voice(DEAD, info, p);
		return (PHIL_DIE);
	}
		return (OK);
}

int	monitor(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		if (check_philo_dead(info, &info->philos[i++]) == PHIL_DIE)
			break ;
		pthread_mutex_lock(&(info->m_everyone_eat));
		if (info->count_everyone_eat == info->num_philo)
			return (OK);
		pthread_mutex_unlock(&(info->m_everyone_eat));
		//usleep(1000);
	}
	return (PHIL_DIE);
}
