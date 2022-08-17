/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:48:10 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 10:07:58 by jisookim         ###   ########.fr       */
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
		return (p->id);
	}
		return (OK);
}

int	monitor(t_info *info)
{
	int	i;
	int count_everyone_eat;

	i = 0;
	while (1)
	{
		if (check_philo_dead(info, &info->philos[i]) == info->philos[i].id)
			return (info->philos[i].id); // dead philo's thread
		pthread_mutex_lock(&(info->m_everyone_eat));
		count_everyone_eat = info->count_everyone_eat;
		pthread_mutex_unlock(&(info->m_everyone_eat));
		if (info->count_everyone_eat == info->num_philo)
			return (EAT_ALL);
		i = 0;
	}
	return (1);
}
