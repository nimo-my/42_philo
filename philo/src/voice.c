/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:58:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/16 23:09:09 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// int		get_flag_philo_dead(t_info *info)
// {
// 	int	ret;

// 	ret = 0;
// 	pthread_mutex_lock(&info->m_flag_die);
// 	ret = info->flag_die;
// 	pthread_mutex_unlock(&info->m_flag_die);
	
// 	return (ret);
// }

void	set_flag_philo_dead(t_info *info)
{
	pthread_mutex_lock(&info->m_flag_die);
	info->flag_die = 1;
	pthread_mutex_unlock(&info->m_flag_die);
	return ;
}

void	voice(enum STATE state, t_info *info, t_philo *p)
{
	int gap;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	gap = time_gap(info->start_time, curr);
	pthread_mutex_lock(&info->m_print);
	
	if (state == EAT_ALL) // eat all needs to be in monitor
	{
		set_flag_philo_dead(info); // todo: wrong
		pthread_mutex_lock(&info->m_everyone_eat);
		info->count_everyone_eat++;
		pthread_mutex_unlock(&info->m_everyone_eat);
	}
	else if (state == FORK)
		printf("[%d] philo %d has taken a fork\n", gap, p->id + 1);
	else if (state == EAT)
		printf("[%d] philo %d is eating\n", gap, p->id + 1);
	else if (state == SLEEP)
		printf("[%d] philo %d is sleeping\n", gap, p->id + 1);
	else if (state == THINK)
		printf("[%d] philo %d is thinking\n", gap, p->id + 1);
	else if (state == DEAD)
		printf("[%d] philo %d died\n", gap, p->id + 1);
	pthread_mutex_unlock(&info->m_print);

	return ;
}
