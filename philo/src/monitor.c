/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:48:10 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 23:11:03 by jisookim         ###   ########.fr       */
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
		if (info->philos[i].eat_count == info->num_must_eat)
		{
			pthread_mutex_unlock(&(info->philos[i].m_eat_count));
			voice(EAT_ALL, info, &info->philos[i]);
			pthread_mutex_lock(&info->philos[i].m_flag_eat_all);
			info->philos[i].flag_eat_all = 1;
			pthread_mutex_unlock(&info->philos[i].m_flag_eat_all);
			return (OK);
		}
		pthread_mutex_unlock(&(info->philos[i].m_eat_count));
	}
	return (OK);
}

void	init_fork(t_info *info, int i)
{
	pthread_mutex_lock(&info->philos[i].m_flag_eat_all);
	info->philos[i].flag_eat_all = -2;
	pthread_mutex_unlock(&info->philos[i].m_flag_eat_all);
	pthread_mutex_lock(&info->m_fork[i]);
	if (info->fork[info->philos[i].right_fork] == 0)
		info->fork[info->philos[i].right_fork] = 1;
	if (info->fork[info->philos[i].left_fork] == 0)
		info->fork[info->philos[i].left_fork] = 1;
	pthread_mutex_unlock(&info->philos[i].m_flag_eat_all);
}

int	monitor(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < info->num_philo)
		{
			if (check_philo_dead(info, &info->philos[i]) == PHIL_DIE)
				break ;
			// if (check_philo_eat_all(info, i))
			// 	break ;
			i++;
		}
		i = 0;
		if (info->flag_die == 1)
			return (PHIL_DIE);
		pthread_mutex_lock(&(info->m_everyone_eat));
		if (info->count_everyone_eat == info->num_philo)
			return (OK);
		pthread_mutex_unlock(&(info->m_everyone_eat));
	}
	return (PHIL_DIE);
}


// pthread_mutex_lock(&(info->philos[i].m_eat_count));
// 		if (info->philos[i].eat_count == info->num_must_eat)
// 		{
// 			pthread_mutex_unlock(&(info->philos[i].m_eat_count));
// 			voice(EAT_ALL, info, &info->philos[i]);
// 			pthread_mutex_lock(&info->philos[i].m_flag_eat_all);
// 			info->philos[i].flag_eat_all = 1;
// 			pthread_mutex_unlock(&info->philos[i].m_flag_eat_all);
// 			return (OK);
// 		}
// 		else if (info->philos[i].eat_count > info->num_must_eat)
// 		{
// 			pthread_mutex_lock(&info->philos[i].m_flag_eat_all);
// 			init_fork(info, i);
// 			pthread_mutex_unlock(&info->philos[i].m_flag_eat_all);
// 			return (0);
// 		}
// 		pthread_mutex_unlock(&(info->philos[i].m_eat_count));
// 		pthread_mutex_lock(&info->philos[i].m_flag_eat_all);
// 		info->philos[i].flag_eat_all = 0;
// 		pthread_mutex_unlock(&info->philos[i].m_flag_eat_all);
// 		i++;