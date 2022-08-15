/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:58:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 20:26:54 by jisookim         ###   ########.fr       */
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
	int gap;

	check_curr_time(info);
	pthread_mutex_lock(&info->m_start_time);
	gap = time_gap(info->start_time, info->current_time);
	pthread_mutex_unlock(&info->m_start_time);

	pthread_mutex_lock(&info->m_print);
	if (get_flag_philo_dead(info))
		;
	else if (state == EAT_ALL)
		printf("[%d] philo %d 다먹음! \n", gap, p->id);
	else if (state == EAT_MORE)
		;
	else if (state == FORK)
		printf("[%d] philo %d has taken a fork\n", gap, p->id);
	else if (state == EAT)
		printf("[%d] philo %d is eating\n", gap, p->id);
	else if (state == SLEEP)
		printf("[%d] philo %d is sleeping\n", gap, p->id);
	else if (state == THINK)
		printf("[%d] philo %d is thinking\n", gap, p->id);
	else if (state == DEAD)
	{
		printf("[%d] philo %d died\n", gap, p->id);
		set_flag_philo_dead(info);
	}
	pthread_mutex_unlock(&info->m_print);
	return ;
}
