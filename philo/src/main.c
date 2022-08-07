/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/07 15:29:06 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char *argv[])
{
	t_info	*info;

	// [set] & [init]
	info = make_info_struct(argc, argv);
	if (!info || check_argv(argc, info) == RET_ERROR || !set_time(info->start_time))
		return (RET_ERROR);
	else // for debug
	{
		printf("[main] num of phil: %d\n", info->num_philo);
		printf("[main] time to die: %d\n", info->time_to_die);
		printf("[main] time to eat: %d\n", info->time_to_eat);
		printf("[main] time to slp: %d\n", info->time_to_sleep);
		printf("[main] num mus eat: %d\n", info->num_must_eat);
	}
	
	// [do] : 필로소퍼 생성(스레드 생성)
	if (!make_philos(info))
	{
		printf("finished!\n");
		return (0);
	}
	
	

	// // - 필로소퍼 생성 완료하면 시간재고 시뮬레이션 시작
	// // 

	// // thread join (기다리기)
	// i = 0;
	// while (i < info->num_philo)
	// {
	// 	pthread_join(&info->tid_arr[i], NULL);
	// 	i++;
	// }

	// // malloc free, delete philo

	// // pthread_mutex_destroy
	// i  = 0;
	// while (i < info->num_philo)
	// {
	// 	pthread_mutex_destroy(&mutex_arr[i]);
	// 	i++;
	// }

	return (0);
}
