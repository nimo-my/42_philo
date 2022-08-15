/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:48:10 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 20:26:37 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int	check_philo_dead(t_info *info, t_philo *p)
{
	check_curr_time(info);
	if (time_gap(p->current_eat, info->current_time) > info->time_to_die)
	{
		pthread_mutex_unlock(&info->m_start_time);
		voice(DEAD, info, p);
		pthread_mutex_lock(&info->m_flag_die);
		info->flag_die = 1;
		pthread_mutex_unlock(&info->m_flag_die);
		return (PHIL_DIE);
	}
	else
	{
		pthread_mutex_unlock(&info->m_start_time);
		return (OK);
	}
}

int	check_philo_eat_all(t_info *info, int i)
{
	while (i < info->num_must_eat)
	{
		pthread_mutex_lock(&(info->philos[i].m_eat_count));
		if (info->philos[i].eat_count > info->num_must_eat)
		{
			pthread_mutex_unlock(&(info->philos[i].m_eat_count));
			voice(EAT_ALL, info, &info->philos[i]);
			pthread_mutex_lock(&(info->m_flag_eat_all));
			info->flag_eat_all = 1;
			pthread_mutex_lock(&(info->m_flag_eat_all));
			return (0);
		}
		pthread_mutex_unlock(&(info->philos[i].m_eat_count));
		pthread_mutex_lock(&(info->m_flag_eat_all));
		info->flag_eat_all = 0;
		pthread_mutex_unlock(&(info->m_flag_eat_all));
		i++;
	}
	return (OK);
}

int	monitor(t_info *info)
{
	int	i;
	int	dead;

	i = 0;
	while (1)
	{
		while (i < info->num_philo)
		{
			if (!check_philo_dead(info, &info->philos[i]))
				break ;
			i++;
		}
		i = 0;
		while (i < info->num_philo && info->num_must_eat)
		{
			if (check_philo_eat_all(info, i))
				break ;
			i++;
		}
		i = 0;
		if (info->flag_die == 1)
			return (PHIL_DIE);
	}
	return (PHIL_DIE);
}
