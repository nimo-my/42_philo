/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:48:10 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 00:59:15 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// 죽은 필로 확인하고
// 하나라도 있으면 finish_flag = 1;
// 이때, info->flag는 공유자원이기 때문에 뮤텍스 걸어놓아야함

int	check_philo_starve(t_info *info, int i)
{
	// int res;
	(void)info;
	(void)i;
	// pthread_mutex_lock(&(info->philos[i].m_current_eat));
	// gettimeofday(&info->philos[i].current_eat, 0);
	// pthread_mutex_unlock(&(info->philos[i].m_current_eat));

	// pthread_mutex_lock(&(info->m_start_time));
	// gettimeofday(&info->start_time, 0);
	// pthread_mutex_unlock(&(info->m_start_time));

	// printf("i : %d\n", i);
	//printf("33 %d %d [%d]\n", start, curr, start - curr);
	//printf("res: %d\n", res);

	// res = time_gap(info->start_time, info->philos[i].current_eat);
	// if (res > info->time_to_die)
	// {
	// 	get_flag_philo_dead(info);
	// 	return (PHIL_DIE);
	// }
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

int	check_curr_time(t_info *info)
{
	int ret;

	pthread_mutex_lock(&info->m_current_time);
	ret = gettimeofday(&info->current_time, 0);
	pthread_mutex_unlock(&info->m_current_time);
	return (ret);
}

void	monitor(t_info *info)
{
	int	i;
	int	dead;

	i = 0;
	dead = 0;
	printf("this is monitor!\n");
	
	while (1)
	{
		dead = get_flag_philo_dead(info);
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
