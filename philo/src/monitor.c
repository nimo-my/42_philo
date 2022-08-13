/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:48:10 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/14 04:04:03 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// 죽은 필로 확인하고
// 하나라도 있으면 finish_flag = 1;
// 이때, info->flag는 공유자원이기 때문에 뮤텍스 걸어놓아야함

int	check_philo_starve(t_info *info, int i)
{
	struct timeval now_time;

	gettimeofday(&now_time, 0);
	pthread_mutex_lock(&(info->philos[i].m_eat_count));
	if (starved_time(info->philos[i].current_eat, now_time) > info->time_to_die)
		return (PHIL_DIE);
	pthread_mutex_unlock(&(info->philos[i].m_eat_count));
	return (OK);
}

int	check_philo_eat_all(t_info *info, int i)
{
	while (i < info->num_must_eat)
	{
		pthread_mutex_lock(&(info->philos[i].m_eat_count));
		if (info->philos[i].eat_count < info->num_must_eat)
		{
			info->flag_eat_all = 0;
			return (0);
		}
		pthread_mutex_unlock(&(info->philos[i].m_eat_count));
		i++;
	}
	return (OK);
}

void	monitor(t_info *info)
{
	int	i;
	int	dead;

	i = 0;
	dead = 0;
	while (1)
	{
		pthread_mutex_lock(&info->m_flag_die);
		dead = info->flag_die;
		pthread_mutex_unlock(&info->m_flag_die);
		if (dead)
			break ;
		while (i < info->num_philo)
		{
			if (!check_philo_starve(info, i))
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
	}
}
