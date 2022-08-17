/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:58:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 10:05:01 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	voice(enum STATE state, t_info *info, t_philo *p)
{
	int gap;
	int	die;
	struct timeval	curr;

	pthread_mutex_lock(&info->m_flag_die);
	die = info->flag_die;
	pthread_mutex_unlock(&info->m_flag_die);
	if (die)
		return ;
	gettimeofday(&curr, NULL);
	gap = time_gap(info->start_time, curr);

	pthread_mutex_lock(&info->m_print);
	if (state == FORK)
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
