/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:42:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/10 16:09:00 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	set_time(struct timeval time)
{
	long	time_mill_sec;

	if (gettimeofday(&time, NULL)) // set time(init)
		return (RET_ERROR);
	time_mill_sec = (time.tv_sec % 10000) * 1000000 + time.tv_usec;
	return (time_mill_sec);
}
// 이런식으로 사용: 
// philo->time->life_time[0] = settime(philo->time->life[0]) //밀리세컨드로 시간 표시
// (do sth)
// philo->time->life_time[1] = settime(philo->time->life[1])
// 

long	time_gap(struct timeval start_time, struct timeval end_time)
{
	long	sec;
	long	micro;
	size_t	res;

	sec = (end_time.tv_sec) - (start_time.tv_sec);
	micro = ((sec * 1000000) + end_time.tv_usec) - (start_time.tv_usec);
	res = sec + micro;

	printf("The elapsed time is %d seconds and %d micros\n", sec, micro); // debug
	printf("res : %llu", res);
	return (res);
}