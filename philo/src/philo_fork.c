/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:00:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/12 16:43:39 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	pick_fork(t_philo *p,)
{
	int	lfork;
	int	rfork;

	lfork = p->left_fork;
	rfork = p->left_fork;
	if (p->id % 2) // 홀수
	{
		pthread_mutex_lock(&(p->info->m_fork[lfork]));
		print(philo, time, p->id, "picks up a fork.");
		pthread_mutex_unlock(&(p->info->m_fork[rfork]));
	}
	else
	{
		pthread_mutex_lock(&(p->info->m_fork[rfork]));
		print(philo, time, p->id, "picks up a fork.");
		pthread_mutex_unlock(&(p->info->m_fork[lfork]));
	}
	return (OK);
}

void	put_down_fork(t_philo *p)
{
	pthread_mutex_unlock(p->info->m_fork[p->left_fork]);
	pthread_mutex_unlock(p->info->m_fork[p->right_fork]);
}

