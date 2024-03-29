/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:42:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 21:32:01 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	custom_usleep_timer(struct timeval *start, int sleep_time)
{
	struct timeval	now;

	gettimeofday(&now, 0);
	while (time_gap(*start, now) < sleep_time)
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
