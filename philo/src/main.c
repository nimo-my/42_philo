/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/07/31 22:15:22 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main()
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (false);
	printf("result : %ld\n" , tv.tv_sec * MILLI + tv.tv_usec / MILLI);
	// sleep(5);
	// if (gettimeofday(&tv, NULL) == ERROR)
	// 	return (false);
	// printf("result : %ld\n" , tv.tv_sec * MILLI + tv.tv_usec / MILLI);
	printf("\033[0;31m died\033[0;0m\n");
	printf("\033[1;33m has taken a fork\033[0;0m\n");
	printf("\033[0;32m is eating\033[0;0m\n");
	printf("\033[0;36m is thinking\033[0;0m\n");
	return (0);
}
