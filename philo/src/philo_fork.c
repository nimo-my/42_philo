/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:00:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 02:11:22 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void	grab_fork(t_info *info, t_philo *p)
{
	if (p->id % 2)
	{
		pthread_mutex_lock(&info->m_fork[p->left_fork]);
		info->fork[p->left_fork] = 1;
		voice(FORK, info, p);
		pthread_mutex_lock(&info->m_fork[p->right_fork]);
		info->fork[p->right_fork] = 1;
		voice(FORK, info, p);
	}
	else
	{
		pthread_mutex_lock(&info->m_fork[p->right_fork]);
		info->fork[p->right_fork] = 1;
		voice(FORK, info, p);
		pthread_mutex_lock(&info->m_fork[p->left_fork]);
		info->fork[p->left_fork] = 1;
		voice(FORK, info, p);
	}
}

void	put_down_fork(t_info *info, t_philo *p)
{
	pthread_mutex_unlock(&info->m_fork[p->right_fork]);
	pthread_mutex_unlock(&info->m_fork[p->left_fork]);
	info->fork[p->right_fork] = 0;
	info->fork[p->left_fork] = 0;

}

