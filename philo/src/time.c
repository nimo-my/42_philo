/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:42:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 20:09:28 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_curr_time(t_info *info)
{
	pthread_mutex_lock(&info->m_current_time);
	gettimeofday(&info->current_time, 0);
	pthread_mutex_unlock(&info->m_current_time);
}

void	custom_usleep_timer(int input_time)
{
	struct timeval start;
	struct timeval now;

	gettimeofday(&start, 0);
	gettimeofday(&now, 0);

	while (time_gap(start, now) < input_time)
	{
		usleep(300);
		gettimeofday(&now, 0);
	}
}

// get gap of time that philo starved
int	time_gap(struct timeval start_time, struct timeval now_time)
{
	time_t	sec;
	time_t	micro;

	sec = (now_time.tv_sec) - (start_time.tv_sec);
	micro = (sec * 1000) + ((now_time.tv_usec - start_time.tv_usec) / 1000);
	return ((int)micro);
}
