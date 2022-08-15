/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:58:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 01:42:34 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int		get_flag_philo_dead(t_info *info)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&info->m_flag_die);
	ret = info->flag_die;
	pthread_mutex_unlock(&info->m_flag_die);
	return (ret);
}

void	set_flag_philo_dead(t_info *info)
{
	pthread_mutex_lock(&info->m_flag_die);
	info->flag_die = 1;
	pthread_mutex_unlock(&info->m_flag_die);
	return ;
}

void	voice(enum STATE state, t_info *info, t_philo *p)
{
	int	curr;
	int gap;

	curr = check_curr_time(info);
	pthread_mutex_lock(&info->m_start_time);
	gap = time_gap(info->start_time, info->current_time);
	pthread_mutex_unlock(&info->m_start_time);

	pthread_mutex_lock(&info->m_print);
	if (get_flag_philo_dead(info))
		;
	else if (state == EAT_ALL)
		printf("[%d] philo %d finished eating.\n", gap, p->id);
	else if (state == EAT_MORE)
		;
	else if (state == FORK)
		printf("[%d] philo %d grabed a fork.\n", gap, p->id);
	else if (state == EAT)
		printf("[%d] philo %d is eating.\n", gap, p->id);
	else if (state == SLEEP)
		printf("[%d] philo %d is sleeping.\n", gap, p->id);
	else if (state == THINK)
		printf("[%d] philo %d is thinking.\n", gap, p->id);
	else if (state == DEAD)
	{
		printf("[%d] philo %d is dead.\n", gap, p->id);
		set_flag_philo_dead(info);
	}
	pthread_mutex_unlock(&info->m_print);
	return ;
}


// 	pthread_mutex_lock(&info->m_print);
// 	if (get_flag_philo_dead(info))
// 		;
// 	else if (state == FORK)
// 		printf("[%ld] philo %ld grabed a fork.\n", info->start_time) - info->current_time, p->id));
// 	else if (state == EAT)
// 		printf("[%ld] philo %ld is eating.\n", info->start_time) - info->current_time, p->id));
// 	else if (state == SLEEP)
// 		printf("[%ld] philo %ld is sleeping.\n", info->start_time) - info->current_time, p->id));
// 	else if (state == THINK)
// 		printf("[%ld] philo %ld is thinking.\n", info->start_time) - info->current_time, p->id));
// 	else if (state == DEAD)
// 	{
// 		printf("[%ld] philo %ld is dead.\n", info->start_time) - info->current_time, p->id));
// 		set_flag_philo_dead(info);
// 	}
// 	pthread_mutex_unlock(&info->m_print);
// 	return ;
// }


//struct timeval	now_time;
	//struct timeval	start_time;


	// pthread_mutex_lock(&info->m_start_time);
	// if (info->flag_starting)
	// {
	// 	gettimeofday(&info->current_time, 0);
	// 	info->flag_starting = 0;
	// }
	// else
	// 	start_time = info->start_time;
	// pthread_mutex_unlock(&info->m_start_time);

	// pthread_mutex_lock(&info->m_current_time);
	// gettimeofday(&info->current_time, 0);
	// pthread_mutex_unlock(&info->m_current_time);
