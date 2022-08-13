/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:42:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/14 04:21:01 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	custom_timer(int input_time)
{
	struct timeval	start_time;
	struct timeval	now_time;

	gettimeofday(&start_time, 0);
	gettimeofday(&now_time, 0);
	while (starved_time(start_time, now_time) < input_time)
	{
		usleep(200);
		gettimeofday(&now_time, 0);
	}
}

// get gap of time that philo starved
time_t	starved_time(struct timeval start_time, struct timeval now_time)
{
	time_t	sec;
	time_t	micro;
	time_t	res;

	sec = (now_time.tv_sec) - (start_time.tv_sec);
	micro = ((sec * 1000000) + now_time.tv_usec) - (start_time.tv_usec);
	res = sec + micro;
	return (res);
}


// printf("The elapsed time is %d seconds and %d micros\n", sec, micro); // debug
// printf("res : %llu", res);



// long	set_time(struct timeval time)
// {
// 	long	time_mill_sec;

// 	if (gettimeofday(&time, NULL)) // set time(init)
// 		return (RET_ERROR);
// 	time_mill_sec = (time.tv_sec % 10000) * 1000000 + time.tv_usec;
// 	return (time_mill_sec);
// }
